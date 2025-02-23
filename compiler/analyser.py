from dataclasses import dataclass
from typing import Dict, List, Optional, Set
from enum import Enum

# Assuming we have access to ASTNode and ASTNodeType from the parser

class Type(Enum):
    VOID = 'void'
    CHAR = 'char'
    INT = 'int'
    FLOAT = 'float'
    DOUBLE = 'double'
    LONG = 'long'
    SHORT = 'short'
    UNSIGNED = 'unsigned'
    SIGNED = 'signed'
    ARRAY = 'array'
    POINTER = 'pointer'
    FUNCTION = 'function'

@dataclass
class Symbol:
    name: str
    type: Type
    is_function: bool = False
    parameters: List['Symbol'] = None
    array_dimensions: List[int] = None
    is_constant: bool = False
    initialized: bool = False
    scope_level: int = 0

class SymbolTable:
    def __init__(self):
        self.scopes: List[Dict[str, Symbol]] = [{}]  # Start with global scope
        self.current_scope = 0
    
    def enter_scope(self):
        self.scopes.append({})
        self.current_scope += 1
    
    def exit_scope(self):
        if self.current_scope > 0:
            self.scopes.pop()
            self.current_scope -= 1
    
    def declare(self, symbol: Symbol) -> bool:
        # Check if symbol already exists in current scope
        if symbol.name in self.scopes[self.current_scope]:
            return False
        
        symbol.scope_level = self.current_scope
        self.scopes[self.current_scope][symbol.name] = symbol
        return True
    
    def lookup(self, name: str) -> Optional[Symbol]:
        # Look through all scopes from current to global
        for scope in reversed(self.scopes[:self.current_scope + 1]):
            if name in scope:
                return scope[name]
        return None

class SemanticError(Exception):
    def __init__(self, message: str):
        self.message = message
        super().__init__(self.message)

class SemanticAnalyzer:
    def __init__(self):
        self.symbol_table = SymbolTable()
        self.current_function: Optional[Symbol] = None
        self.errors: List[str] = []
        self.warnings: List[str] = []
        
        # Initialize built-in types
        self.types = {
            'void': Type.VOID,
            'char': Type.CHAR,
            'int': Type.INT,
            'float': Type.FLOAT,
            'double': Type.DOUBLE,
            'long': Type.LONG,
            'short': Type.SHORT,
            'unsigned': Type.UNSIGNED,
            'signed': Type.SIGNED
        }
    
    def analyze(self, ast: ASTNode):
        """Main entry point for semantic analysis"""
        try:
            self._analyze_node(ast)
            return len(self.errors) == 0
        except SemanticError as e:
            self.errors.append(str(e))
            return False
    
    def _analyze_node(self, node: ASTNode) -> Optional[Type]:
        if node is None:
            return None
        
        if node.type == ASTNodeType.PROGRAM:
            return self._analyze_program(node)
        elif node.type == ASTNodeType.FUNCTION_DEF:
            return self._analyze_function_def(node)
        elif node.type == ASTNodeType.VAR_DECL:
            return self._analyze_var_declaration(node)
        elif node.type == ASTNodeType.COMPOUND_STMT:
            return self._analyze_compound_statement(node)
        elif node.type == ASTNodeType.IF_STMT:
            return self._analyze_if_statement(node)
        elif node.type == ASTNodeType.WHILE_STMT:
            return self._analyze_while_statement(node)
        elif node.type == ASTNodeType.FOR_STMT:
            return self._analyze_for_statement(node)
        elif node.type == ASTNodeType.RETURN_STMT:
            return self._analyze_return_statement(node)
        elif node.type == ASTNodeType.BINARY_OP:
            return self._analyze_binary_operation(node)
        elif node.type == ASTNodeType.UNARY_OP:
            return self._analyze_unary_operation(node)
        elif node.type == ASTNodeType.ASSIGNMENT:
            return self._analyze_assignment(node)
        elif node.type == ASTNodeType.IDENTIFIER:
            return self._analyze_identifier(node)
        elif node.type == ASTNodeType.LITERAL:
            return self._analyze_literal(node)
        elif node.type == ASTNodeType.FUNCTION_CALL:
            return self._analyze_function_call(node)
        
        raise SemanticError(f"Unknown node type: {node.type}")
    
    def _analyze_program(self, node: ASTNode) -> None:
        """Analyze the program node (root of AST)"""
        for child in node.children:
            self._analyze_node(child)
    
    def _analyze_function_def(self, node: ASTNode) -> None:
        """Analyze function definition"""
        return_type = self._get_type_from_specifier(node.children[0])
        name = node.children[1]
        parameters = node.children[2]
        body = node.children[3]
        
        # Create function symbol
        func_symbol = Symbol(
            name=name,
            type=return_type,
            is_function=True,
            parameters=[],
            scope_level=self.symbol_table.current_scope
        )
        
        # Add parameters to function symbol
        self.symbol_table.enter_scope()
        for param in parameters:
            param_type = self._get_type_from_specifier(param.children[0])
            param_name = param.children[1]
            param_symbol = Symbol(name=param_name, type=param_type)
            func_symbol.parameters.append(param_symbol)
            
            if not self.symbol_table.declare(param_symbol):
                raise SemanticError(f"Duplicate parameter name: {param_name}")
        
        # Declare function in global scope
        if not self.symbol_table.declare(func_symbol):
            raise SemanticError(f"Function {name} already declared")
        
        # Analyze function body
        self.current_function = func_symbol
        self._analyze_node(body)
        self.current_function = None
        
        self.symbol_table.exit_scope()
    
    def _analyze_var_declaration(self, node: ASTNode) -> None:
        """Analyze variable declaration"""
        var_type = self._get_type_from_specifier(node.children[0])
        name = node.children[1]
        init = node.children[2]
        
        # Create and declare symbol
        symbol = Symbol(
            name=name,
            type=var_type,
            initialized=init is not None,
            scope_level=self.symbol_table.current_scope
        )
        
        if not self.symbol_table.declare(symbol):
            raise SemanticError(f"Variable {name} already declared in this scope")
        
        # Check initialization type if present
        if init:
            init_type = self._analyze_node(init)
            if not self._types_compatible(var_type, init_type):
                raise SemanticError(
                    f"Cannot initialize variable of type {var_type} with expression of type {init_type}"
                )
    
    def _analyze_compound_statement(self, node: ASTNode) -> None:
        """Analyze compound statement (block)"""
        self.symbol_table.enter_scope()
        for child in node.children:
            self._analyze_node(child)
        self.symbol_table.exit_scope()
    
    def _analyze_if_statement(self, node: ASTNode) -> None:
        """Analyze if statement"""
        condition_type = self._analyze_node(node.children[0])
        if condition_type not in [Type.INT, Type.FLOAT, Type.DOUBLE]:
            raise SemanticError("Condition must be numeric type")
        
        self._analyze_node(node.children[1])  # Then branch
        if node.children[2]:  # Else branch
            self._analyze_node(node.children[2])
    
    def _analyze_while_statement(self, node: ASTNode) -> None:
        """Analyze while statement"""
        condition_type = self._analyze_node(node.children[0])
        if condition_type not in [Type.INT, Type.FLOAT, Type.DOUBLE]:
            raise SemanticError("Condition must be numeric type")
        
        self._analyze_node(node.children[1])  # Body
    
    def _analyze_for_statement(self, node: ASTNode) -> None:
        """Analyze for statement"""
        self.symbol_table.enter_scope()
        
        # Analyze init, condition, and increment expressions
        if node.children[0]:
            self._analyze_node(node.children[0])
        if node.children[1]:
            condition_type = self._analyze_node(node.children[1])
            if condition_type not in [Type.INT, Type.FLOAT, Type.DOUBLE]:
                raise SemanticError("For loop condition must be numeric type")
        if node.children[2]:
            self._analyze_node(node.children[2])
        
        # Analyze body
        self._analyze_node(node.children[3])
        
        self.symbol_table.exit_scope()
    
    def _analyze_return_statement(self, node: ASTNode) -> None:
        """Analyze return statement"""
        if not self.current_function:
            raise SemanticError("Return statement outside function")
        
        if node.children[0]:  # Return with value
            return_type = self._analyze_node(node.children[0])
            if not self._types_compatible(self.current_function.type, return_type):
                raise SemanticError(
                    f"Return type {return_type} doesn't match function return type {self.current_function.type}"
                )
        elif self.current_function.type != Type.VOID:
            raise SemanticError("Non-void function must return a value")
    
    def _analyze_binary_operation(self, node: ASTNode) -> Type:
        """Analyze binary operation"""
        left_type = self._analyze_node(node.children[0])
        operator = node.children[1]
        right_type = self._analyze_node(node.children[2])
        
        if not self._types_compatible(left_type, right_type):
            raise SemanticError(
                f"Incompatible types for operator {operator}: {left_type} and {right_type}"
            )
        
        # Determine result type based on operator and operand types
        if operator in ['&&', '||']:
            return Type.INT
        elif operator in ['<', '<=', '>', '>=', '==', '!=']:
            return Type.INT
        elif operator in ['+', '-', '*', '/']:
            return self._promote_type(left_type, right_type)
        
        raise SemanticError(f"Unknown operator: {operator}")
    
    def _analyze_unary_operation(self, node: ASTNode) -> Type:
        """Analyze unary operation"""
        operator = node.children[0]
        operand_type = self._analyze_node(node.children[1])
        
        if operator == '!':
            return Type.INT
        elif operator == '-':
            if operand_type not in [Type.INT, Type.FLOAT, Type.DOUBLE]:
                raise SemanticError(f"Cannot apply unary minus to type {operand_type}")
            return operand_type
        
        raise SemanticError(f"Unknown unary operator: {operator}")
    
    def _analyze_assignment(self, node: ASTNode) -> Type:
        """Analyze assignment"""
        left_type = self._analyze_node(node.children[0])
        right_type = self._analyze_node(node.children[1])
        
        if not self._types_compatible(left_type, right_type):
            raise SemanticError(
                f"Cannot assign value of type {right_type} to variable of type {left_type}"
            )
        
        # Mark left-side symbol as initialized
        if node.children[0].type == ASTNodeType.IDENTIFIER:
            symbol = self.symbol_table.lookup(node.children[0].value)
            if symbol:
                symbol.initialized = True
        
        return left_type
    
    def _analyze_identifier(self, node: ASTNode) -> Type:
        """Analyze identifier"""
        symbol = self.symbol_table.lookup(node.value)
        if not symbol:
            raise SemanticError(f"Undefined identifier: {node.value}")
        
        if not symbol.initialized:
            self.warnings.append(f"Use of uninitialized variable: {node.value}")
        
        return symbol.type
    
    def _analyze_literal(self, node: ASTNode) -> Type:
        """Analyze literal value"""
        # Determine type based on literal value
        value = node.value
        if isinstance(value, int):
            return Type.INT
        elif isinstance(value, float):
            return Type.FLOAT
        elif isinstance(value, str):
            if len(value) == 1:  # Character literal
                return Type.CHAR
            return Type.POINTER  # String literal (pointer to char)
        
        raise SemanticError(f"Unknown literal type: {type(value)}")
    
    def _analyze_function_call(self, node: ASTNode) -> Type:
        """Analyze function call"""
        func_name = node.children[0]
        arguments = node.children[1]
        
        # Look up function in symbol table
        symbol = self.symbol_table.lookup(func_name)
        if not symbol or not symbol.is_function:
            raise SemanticError(f"Undefined function: {func_name}")
        
        # Check number of arguments
        if len(arguments) != len(symbol.parameters):
            raise SemanticError(
                f"Function {func_name} expects {len(symbol.parameters)} arguments, got {len(arguments)}"
            )
        
        # Check argument types
        for i, (arg, param) in enumerate(zip(arguments, symbol.parameters)):
            arg_type = self._analyze_node(arg)
            if not self._types_compatible(param.type, arg_type):
                raise SemanticError(
                    f"Argument {i+1} of function {func_name} expects type {param.type}, got {arg_type}"
                )
        
        return symbol.type
    
    def _get_type_from_specifier(self, type_node: ASTNode) -> Type:
        """Convert type specifier node to Type enum"""
        if type_node.type != ASTNodeType.TYPE_SPECIFIER:
            raise SemanticError("Expected type specifier")
        
        type_str = type_node.value
        if type_str in self.types:
            return self.types[type_str]
        
        raise SemanticError(f"Unknown type: {type_str}")
    
    def _types_compatible(self, type1: Type, type2: Type) -> bool:
        """Check if two types are compatible for assignment/comparison"""
        if type1 == type2:
            return True
        
        # Numeric type promotion rules
        numeric_types = {Type.CHAR, Type.SHORT, Type.INT, Type.LONG, Type.FLOAT, Type.DOUBLE}
        if type1 in numeric_types and type2 in numeric_types:
            # Allow implicit numeric conversions
            # Double > Float > Long > Int > Short > Char
            type_rank = {
                Type.CHAR: 1,
                Type.SHORT: 2,
                Type.INT: 3,
                Type.LONG: 4,
                Type.FLOAT: 5,
                Type.DOUBLE: 6
            }
            return type_rank[type1] >= type_rank[type2]
        
        # Pointer compatibility
        if type1 == Type.POINTER and type2 == Type.POINTER:
            return True  # For simplicity, we're not checking pointed-to types
        
        # Allow NULL (integer 0) to be assigned to pointers
        if type1 == Type.POINTER and type2 == Type.INT:
            return True
        
        return False
    
    def _promote_type(self, type1: Type, type2: Type) -> Type:
        """Determine result type for arithmetic operations"""
        if type1 == type2:
            return type1
        
        type_rank = {
            Type.CHAR: 1,
            Type.SHORT: 2,
            Type.INT: 3,
            Type.LONG: 4,
            Type.FLOAT: 5,
            Type.DOUBLE: 6
        }
        
        if type1 in type_rank and type2 in type_rank:
            return max(type1, type2, key=lambda t: type_rank[t])
        
        raise SemanticError(f"Cannot promote types {type1} and {type2}")
    
    def _check_array_bounds(self, node: ASTNode) -> None:
        """Check array access bounds if size is known"""
        if node.type == ASTNodeType.ARRAY_ACCESS:
            array_name = node.children[0]
            index_expr = node.children[1]
            
            symbol = self.symbol_table.lookup(array_name)
            if not symbol:
                raise SemanticError(f"Undefined array: {array_name}")
            
            if symbol.array_dimensions:
                # If we have a literal index, we can check bounds
                if index_expr.type == ASTNodeType.LITERAL and isinstance(index_expr.value, int):
                    if index_expr.value < 0 or index_expr.value >= symbol.array_dimensions[0]:
                        self.warnings.append(
                            f"Array index {index_expr.value} out of bounds for array {array_name} "
                            f"of size {symbol.array_dimensions[0]}"
                        )
    
    def _check_variable_usage(self) -> None:
        """Check for unused variables"""
        for scope in self.symbol_table.scopes:
            for name, symbol in scope.items():
                if not symbol.is_function and not symbol.initialized:
                    self.warnings.append(f"Variable {name} declared but never initialized")

def analyze_code(ast: ASTNode) -> tuple[bool, List[str], List[str]]:
    """
    Analyze C code for semantic correctness.
    
    Args:
        ast: The abstract syntax tree from the parser
        
    Returns:
        tuple containing:
        - bool: True if analysis succeeded with no errors
        - List[str]: List of error messages
        - List[str]: List of warning messages
    """
    analyzer = SemanticAnalyzer()
    success = analyzer.analyze(ast)
    
    # Perform final checks
    analyzer._check_variable_usage()
    
    return success, analyzer.errors, analyzer.warnings

# Example usage:
if __name__ == "__main__":
    # Example code using our previous lexer and parser
    code = '''
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    int main() {
        int x;  // Warning: uninitialized
        float y = 3.14;
        y = x;  // Warning: using uninitialized variable
        return factorial(5);
    }
    '''
    
    # Create lexer and get tokens
    lexer = Lexer(code)
    tokens = lexer.tokenize()
    
    # Parse tokens into AST
    parser = Parser(tokens)
    ast = parser.parse()
    
    # Perform semantic analysis
    success, errors, warnings = analyze_code(ast)
    
    if not success:
        print("Semantic analysis failed!")
        print("\nErrors:")
        for error in errors:
            print(f"- {error}")
    else:
        print("Semantic analysis succeeded!")
        
    if warnings:
        print("\nWarnings:")
        for warning in warnings:
            print(f"- {warning}")
