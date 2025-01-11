#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER, 
    TOKEN_OPERATOR, 
    TOKEN_LPAREN, 
    TOKEN_RPAREN, 
    TOKEN_END, 
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    double value;
} Token;

Token get_next_token(const char **input);

#endif 
