from dataclasses import dataclass
from typing import List, Optional, Union
from enum import Enum

# Import TokenType and Token from previous lexer
from typing import Any  # Used for expression types

class ASTNodeType(Enum):
    PROGRAM = 'Program'
    FUNCTION_DEF = 'FunctionDefinition'
    COMPOUND_STMT = 'CompoundStatement'
    DECLARATION = 'Declaration'
    VAR_DECL = 'VariableDeclaration'
    PARAM_DECL = 'ParameterDeclaration'
    TYPE_SPECIFIER = 'TypeSpecifier'
    BINARY_OP = 'BinaryOperation'
    UNARY_OP = 'UnaryOperation'
    ASSIGNMENT = 'Assignment'
    IDENTIFIER = 'Identifier'
    LITERAL = 'Literal'
    RETURN_STMT = 'ReturnStatement'
    IF_STMT = 'IfStatement'
    WHILE_STMT = 'WhileStatement'
    FOR_STMT = 'ForStatement'
    FUNCTION_CALL = 'FunctionCall'
    ARRAY_ACCESS = 'ArrayAccess'

@dataclass
class ASTNode:
    type: ASTNodeType
    children: List[Any] = None
    value: Any = None
    
    def __post_init__(self):
        if self.children is None:
            self.children = []

class Parser:
    def __init__(self, tokens: List[Token]):
        self.tokens = tokens
        self.current = 0
    
    def error(self, message: str = "Invalid syntax"):
        token = self.current_token()
        raise Exception(f"{message} at line {token.line}, column {token.column}")
    
    def current_token(self) -> Token:
        if self.current < len(self.tokens):
            return self.tokens[self.current]
        return self.tokens[-1]  # EOF token
    
    def peek(self) -> Token:
        if self.current + 1 < len(self.tokens):
            return self.tokens[self.current + 1]
        return self.tokens[-1]  # EOF token
    
    def advance(self) -> Token:
        token = self.current_token()
        self.current += 1
        return token
    
    def consume(self, token_type: TokenType, error_message: str = None) -> Token:
        current = self.current_token()
        if current.type == token_type:
            return self.advance()
        raise Exception(error_message or f"Expected {token_type}, got {current.type}")
    
    def match(self, *token_types: TokenType) -> bool:
        if self.current_token().type in token_types:
            self.advance()
            return True
        return False
    
    def parse(self) -> ASTNode:
        """Parse the entire program"""
        declarations = []
        while self.current_token().type != TokenType.EOF:
            declarations.append(self.parse_declaration())
        return ASTNode(ASTNodeType.PROGRAM, declarations)
    
    def parse_declaration(self) -> ASTNode:
        """Parse global declaration (function or variable)"""
        type_spec = self.parse_type_specifier()
        identifier = self.consume(TokenType.IDENTIFIER)
        
        if self.match(TokenType.LEFT_PAREN):
            # Function definition
            params = self.parse_parameters()
            self.consume(TokenType.RIGHT_PAREN)
            body = self.parse_compound_statement()
            return ASTNode(
                ASTNodeType.FUNCTION_DEF,
                [type_spec, identifier.value, params, body]
            )
        else:
            # Variable declaration
            init = None
            if self.match(TokenType.ASSIGN):
                init = self.parse_expression()
            self.consume(TokenType.SEMICOLON)
            return ASTNode(
                ASTNodeType.VAR_DECL,
                [type_spec, identifier.value, init]
            )
    
    def parse_type_specifier(self) -> ASTNode:
        """Parse type specification"""
        type_tokens = {
            TokenType.INT, TokenType.CHAR, TokenType.FLOAT, TokenType.DOUBLE,
            TokenType.VOID, TokenType.LONG, TokenType.SHORT, TokenType.UNSIGNED,
            TokenType.SIGNED
        }
        
        if self.current_token().type not in type_tokens:
            self.error("Expected type specifier")
        
        type_specs = []
        while self.current_token().type in type_tokens:
            type_specs.append(self.advance().value)
        
        return ASTNode(ASTNodeType.TYPE_SPECIFIER, value=' '.join(type_specs))
    
    def parse_parameters(self) -> List[ASTNode]:
        """Parse function parameters"""
        params = []
        if self.current_token().type != TokenType.RIGHT_PAREN:
            while True:
                type_spec = self.parse_type_specifier()
                identifier = self.consume(TokenType.IDENTIFIER)
                params.append(ASTNode(
                    ASTNodeType.PARAM_DECL,
                    [type_spec, identifier.value]
                ))
                if not self.match(TokenType.COMMA):
                    break
        return params
    
    def parse_compound_statement(self) -> ASTNode:
        """Parse compound statement (block)"""
        self.consume(TokenType.LEFT_BRACE)
        statements = []
        while self.current_token().type != TokenType.RIGHT_BRACE:
            statements.append(self.parse_statement())
        self.consume(TokenType.RIGHT_BRACE)
        return ASTNode(ASTNodeType.COMPOUND_STMT, statements)
    
    def parse_statement(self) -> ASTNode:
        """Parse statement"""
        token = self.current_token()
        
        if token.type == TokenType.IF:
            return self.parse_if_statement()
        elif token.type == TokenType.WHILE:
            return self.parse_while_statement()
        elif token.type == TokenType.FOR:
            return self.parse_for_statement()
        elif token.type == TokenType.RETURN:
            return self.parse_return_statement()
        elif token.type == TokenType.LEFT_BRACE:
            return self.parse_compound_statement()
        elif token.type in {TokenType.INT, TokenType.CHAR, TokenType.FLOAT, 
                          TokenType.DOUBLE, TokenType.VOID, TokenType.LONG, 
                          TokenType.SHORT, TokenType.UNSIGNED, TokenType.SIGNED}:
            return self.parse_declaration()
        else:
            # Expression statement
            expr = self.parse_expression()
            self.consume(TokenType.SEMICOLON)
            return expr
    
    def parse_if_statement(self) -> ASTNode:
        """Parse if statement"""
        self.consume(TokenType.IF)
        self.consume(TokenType.LEFT_PAREN)
        condition = self.parse_expression()
        self.consume(TokenType.RIGHT_PAREN)
        
        then_branch = self.parse_statement()
        else_branch = None
        
        if self.match(TokenType.ELSE):
            else_branch = self.parse_statement()
        
        return ASTNode(ASTNodeType.IF_STMT, [condition, then_branch, else_branch])
    
    def parse_while_statement(self) -> ASTNode:
        """Parse while statement"""
        self.consume(TokenType.WHILE)
        self.consume(TokenType.LEFT_PAREN)
        condition = self.parse_expression()
        self.consume(TokenType.RIGHT_PAREN)
        body = self.parse_statement()
        
        return ASTNode(ASTNodeType.WHILE_STMT, [condition, body])
    
    def parse_for_statement(self) -> ASTNode:
        """Parse for statement"""
        self.consume(TokenType.FOR)
        self.consume(TokenType.LEFT_PAREN)
        
        init = None
        if not self.match(TokenType.SEMICOLON):
            init = self.parse_expression()
            self.consume(TokenType.SEMICOLON)
        
        condition = None
        if not self.match(TokenType.SEMICOLON):
            condition = self.parse_expression()
            self.consume(TokenType.SEMICOLON)
        
        increment = None
        if not self.match(TokenType.RIGHT_PAREN):
            increment = self.parse_expression()
            self.consume(TokenType.RIGHT_PAREN)
        
        body = self.parse_statement()
        
        return ASTNode(ASTNodeType.FOR_STMT, [init, condition, increment, body])
    
    def parse_return_statement(self) -> ASTNode:
        """Parse return statement"""
        self.consume(TokenType.RETURN)
        value = None
        if not self.match(TokenType.SEMICOLON):
            value = self.parse_expression()
            self.consume(TokenType.SEMICOLON)
        return ASTNode(ASTNodeType.RETURN_STMT, [value])
    
    def parse_expression(self) -> ASTNode:
        """Parse expression"""
        return self.parse_assignment()
    
    def parse_assignment(self) -> ASTNode:
        """Parse assignment expression"""
        expr = self.parse_logical_or()
        
        if self.match(TokenType.ASSIGN):
            right = self.parse_assignment()
            return ASTNode(ASTNodeType.ASSIGNMENT, [expr, right])
        
        return expr
    
    def parse_logical_or(self) -> ASTNode:
        """Parse logical OR expression"""
        expr = self.parse_logical_and()
        
        while self.match(TokenType.OR):
            operator = self.current_token().value
            right = self.parse_logical_and()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_logical_and(self) -> ASTNode:
        """Parse logical AND expression"""
        expr = self.parse_equality()
        
        while self.match(TokenType.AND):
            operator = self.current_token().value
            right = self.parse_equality()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_equality(self) -> ASTNode:
        """Parse equality expression"""
        expr = self.parse_relational()
        
        while self.match(TokenType.EQUALS, TokenType.NOT_EQUALS):
            operator = self.current_token().value
            right = self.parse_relational()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_relational(self) -> ASTNode:
        """Parse relational expression"""
        expr = self.parse_additive()
        
        while self.match(TokenType.LESS, TokenType.LESS_EQ,
                        TokenType.GREATER, TokenType.GREATER_EQ):
            operator = self.current_token().value
            right = self.parse_additive()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_additive(self) -> ASTNode:
        """Parse additive expression"""
        expr = self.parse_multiplicative()
        
        while self.match(TokenType.PLUS, TokenType.MINUS):
            operator = self.current_token().value
            right = self.parse_multiplicative()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_multiplicative(self) -> ASTNode:
        """Parse multiplicative expression"""
        expr = self.parse_unary()
        
        while self.match(TokenType.STAR, TokenType.SLASH, TokenType.PERCENT):
            operator = self.current_token().value
            right = self.parse_unary()
            expr = ASTNode(ASTNodeType.BINARY_OP, [expr, operator, right])
        
        return expr
    
    def parse_unary(self) -> ASTNode:
        """Parse unary expression"""
        if self.match(TokenType.MINUS, TokenType.EXCLAIM):
            operator = self.current_token().value
            right = self.parse_unary()
            return ASTNode(ASTNodeType.UNARY_OP, [operator, right])
        
        return self.parse_primary()
    
    def parse_primary(self) -> ASTNode:
        """Parse primary expression"""
        token = self.current_token()
        
        if self.match(TokenType.INTEGER, TokenType.FLOAT_LIT,
                     TokenType.STRING, TokenType.CHAR_LIT):
            return ASTNode(ASTNodeType.LITERAL, value=token.value)
        
        if self.match(TokenType.IDENTIFIER):
            # Look ahead for function call or array access
            if self.current_token().type == TokenType.LEFT_PAREN:
                self.advance()
                args = []
                if self.current_token().type != TokenType.RIGHT_PAREN:
                    while True:
                        args.append(self.parse_expression())
                        if not self.match(TokenType.COMMA):
                            break
                self.consume(TokenType.RIGHT_PAREN)
                return ASTNode(ASTNodeType.FUNCTION_CALL, [token.value, args])
            elif self.current_token().type == TokenType.LEFT_BRACKET:
                self.advance()
                index = self.parse_expression()
                self.consume(TokenType.RIGHT_BRACKET)
                return ASTNode(ASTNodeType.ARRAY_ACCESS, [token.value, index])
            return ASTNode(ASTNodeType.IDENTIFIER, value=token.value)
        
        if self.match(TokenType.LEFT_PAREN):
            expr = self.parse_expression()
            self.consume(TokenType.RIGHT_PAREN)
            return expr
        
        self.error("Expected expression")

def print_ast(node: ASTNode, indent: str = "") -> None:
    """Helper function to print the AST"""
    print(f"{indent}{node.type}")
    if node.value is not None:
        print(f"{indent}  Value: {node.value}")
    if node.children:
        for child in node.children:
            if child is not None:  # Skip None children (e.g., in if statements without else)
                print_ast(child, indent + "  ")
