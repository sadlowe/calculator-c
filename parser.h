#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"  

typedef struct Expr {
    enum { EXPR_NUMBER, EXPR_OPERATOR } type;
    union {
        double number;
        struct {
            char op;
            struct Expr *left, *right;
        } op;
    };
} Expr;

Expr* parse_expression(const char **input);
Expr* parse_term(const char **input);
Expr* parse_factor(const char **input);

#endif 
