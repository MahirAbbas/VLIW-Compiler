from enum import Enum
from dataclasses import dataclass
from typing import List, Optional

class TokenType(Enum):
    # Keywords
    AUTO = 'auto'
    BREAK = 'break'
    CASE = 'case'
    CHAR = 'char'
    CONST = 'const'
    CONTINUE = 'continue'
    DEFAULT = 'default'
    DO = 'do'
    DOUBLE = 'double'
    ELSE = 'else'
    ENUM = 'enum'
    EXTERN = 'extern'
    FLOAT = 'float'
    FOR = 'for'
    GOTO = 'goto'
    IF = 'if'
    INT = 'int'
    LONG = 'long'
    REGISTER = 'register'
    RETURN = 'return'
    SHORT = 'short'
    SIGNED = 'signed'
    SIZEOF = 'sizeof'
    STATIC = 'static'
    STRUCT = 'struct'
    SWITCH = 'switch'
    TYPEDEF = 'typedef'
    UNION = 'union'
    UNSIGNED = 'unsigned'
    VOID = 'void'
    VOLATILE = 'volatile'
    WHILE = 'while'
    
    # Literals
    IDENTIFIER = 'IDENTIFIER'
    INTEGER = 'INTEGER'
    FLOAT_LIT = 'FLOAT'
    STRING = 'STRING'
    CHAR_LIT = 'CHAR'
    
    # Operators
    PLUS = '+'
    MINUS = '-'
    STAR = '*'
    SLASH = '/'
    PERCENT = '%'
    AMPERSAND = '&'
    PIPE = '|'
    CARET = '^'
    TILDE = '~'
    EXCLAIM = '!'
    ASSIGN = '='
    LESS = '<'
    GREATER = '>'
    PLUS_EQ = '+='
    MINUS_EQ = '-='
    STAR_EQ = '*='
    SLASH_EQ = '/='
    PERCENT_EQ = '%='
    AMPERSAND_EQ = '&='
    PIPE_EQ = '|='
    CARET_EQ = '^='
    LESS_EQ = '<='
    GREATER_EQ = '>='
    EQUALS = '=='
    NOT_EQUALS = '!='
    PLUS_PLUS = '++'
    MINUS_MINUS = '--'
    ARROW = '->'
    AND = '&&'
    OR = '||'
    
    # Delimiters
    COMMA = ','
    SEMICOLON = ';'
    COLON = ':'
    DOT = '.'
    ELLIPSIS = '...'
    LEFT_PAREN = '('
    RIGHT_PAREN = ')'
    LEFT_BRACKET = '['
    RIGHT_BRACKET = ']'
    LEFT_BRACE = '{'
    RIGHT_BRACE = '}'
    
    # Special
    WHITESPACE = 'WHITESPACE'
    NEWLINE = 'NEWLINE'
    COMMENT = 'COMMENT'
    EOF = 'EOF'

@dataclass
class Token:
    type: TokenType
    value: str
    line: int
    column: int

class Lexer:
    def __init__(self, text: str):
        self.text = text
        self.pos = 0
        self.line = 1
        self.column = 1
        self.current_char = self.text[0] if text else None
        
        # Keywords mapping
        self.keywords = {token_type.value: token_type 
                        for token_type in TokenType 
                        if token_type.value.isidentifier()}
    
    def error(self):
        raise Exception(f'Invalid character {self.current_char} at line {self.line}, column {self.column}')
    
    def advance(self):
        self.pos += 1
        if self.pos >= len(self.text):
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]
            if self.current_char == '\n':
                self.line += 1
                self.column = 1
            else:
                self.column += 1
    
    def peek(self) -> Optional[str]:
        peek_pos = self.pos + 1
        if peek_pos >= len(self.text):
            return None
        return self.text[peek_pos]
    
    def skip_whitespace(self):
        while self.current_char and self.current_char.isspace():
            self.advance()
    
    def skip_comment(self):
        if self.current_char == '/' and self.peek() == '/':
            # Single-line comment
            while self.current_char and self.current_char != '\n':
                self.advance()
        elif self.current_char == '/' and self.peek() == '*':
            # Multi-line comment
            self.advance()  # Skip /
            self.advance()  # Skip *
            while self.current_char:
                if self.current_char == '*' and self.peek() == '/':
                    self.advance()  # Skip *
                    self.advance()  # Skip /
                    break
                self.advance()
    
    def identifier(self) -> Token:
        result = ''
        column = self.column
        
        while self.current_char and (self.current_char.isalnum() or self.current_char == '_'):
            result += self.current_char
            self.advance()
        
        # Check if the identifier is a keyword
        token_type = self.keywords.get(result, TokenType.IDENTIFIER)
        return Token(token_type, result, self.line, column)
    
    def number(self) -> Token:
        result = ''
        column = self.column
        is_float = False
        
        while self.current_char and (self.current_char.isdigit() or self.current_char == '.'):
            if self.current_char == '.':
                if is_float:
                    self.error()
                is_float = True
            result += self.current_char
            self.advance()
        
        if is_float:
            return Token(TokenType.FLOAT_LIT, result, self.line, column)
        return Token(TokenType.INTEGER, result, self.line, column)
    
    def string(self) -> Token:
        result = ''
        column = self.column
        self.advance()  # Skip opening quote
        
        while self.current_char and self.current_char != '"':
            if self.current_char == '\\':
                self.advance()
                if self.current_char in {'n', 't', 'r', '\\', '"'}:
                    result += '\\' + self.current_char
                else:
                    self.error()
            else:
                result += self.current_char
            self.advance()
        
        if self.current_char == '"':
            self.advance()  # Skip closing quote
            return Token(TokenType.STRING, result, self.line, column)
        self.error()
    
    def char_literal(self) -> Token:
        result = ''
        column = self.column
        self.advance()  # Skip opening quote
        
        if self.current_char == '\\':
            self.advance()
            if self.current_char in {'n', 't', 'r', '\\', "'"}:
                result = '\\' + self.current_char
            else:
                self.error()
        else:
            result = self.current_char
        
        self.advance()
        if self.current_char != "'":
            self.error()
            
        self.advance()  # Skip closing quote
        return Token(TokenType.CHAR_LIT, result, self.line, column)
    
    def get_token(self) -> Token:
        while self.current_char:
            # Skip whitespace
            if self.current_char.isspace():
                self.skip_whitespace()
                continue
            
            # Skip comments
            if self.current_char == '/':
                next_char = self.peek()
                if next_char in {'/', '*'}:
                    self.skip_comment()
                    continue
            
            # Identifiers and keywords
            if self.current_char.isalpha() or self.current_char == '_':
                return self.identifier()
            
            # Numbers
            if self.current_char.isdigit():
                return self.number()
            
            # String literals
            if self.current_char == '"':
                return self.string()
            
            # Character literals
            if self.current_char == "'":
                return self.char_literal()
            
            # Multi-character operators
            if self.current_char + (self.peek() or '') in {'+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<=', '>=', '==', '!=', '++', '--', '->', '&&', '||', '...'}:
                column = self.column
                op = self.current_char + self.peek()
                self.advance()
                self.advance()
                if op == '...' and self.current_char == '.':
                    self.advance()
                return Token(TokenType(op), op, self.line, column)
            
            # Single-character operators and delimiters
            if self.current_char in {'+', '-', '*', '/', '%', '&', '|', '^', '~', '!', '=', '<', '>', ',', ';', ':', '.', '(', ')', '[', ']', '{', '}'}:
                column = self.column
                char = self.current_char
                self.advance()
                return Token(TokenType(char), char, self.line, column)
            
            self.error()
        
        return Token(TokenType.EOF, '', self.line, self.column)
    
    def tokenize(self) -> List[Token]:
        tokens = []
        while True:
            token = self.get_token()
            tokens.append(token)
            if token.type == TokenType.EOF:
                break
        return tokens
