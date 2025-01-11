// parser.c
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

Expr* parse_expression(const char **input) {
    Expr *left = parse_term(input);
    printf("Left expression parsed.\n");

    Token token = get_next_token(input);
    while (token.type == TOKEN_OPERATOR && (token.value == '+' || token.value == '-')) {
        printf("Processing operator: %c\n", token.value);  // Debugging line
        Expr *op = malloc(sizeof(Expr));
        op->type = EXPR_OPERATOR;
        op->op.op = token.value;
        op->op.left = left;
        op->op.right = parse_term(input);
        left = op;

        token = get_next_token(input);
    }

    // Debugging line to ensure the correct flow
    if (token.type == TOKEN_END) {
        printf("End of input reached, parser complete.\n");
    }

    // If we have a token that is not TOKEN_END, something went wrong
    if (token.type != TOKEN_END) {
        printf("Unexpected token after expression: %d\n", token.type);
        exit(1);
    }

    return left;
}





Expr* parse_term(const char **input) {
    Expr *left = parse_factor(input);

    Token token = get_next_token(input);
    while (token.type == TOKEN_OPERATOR && (token.value == '*' || token.value == '/')) {
        Expr *op = malloc(sizeof(Expr));
        op->type = EXPR_OPERATOR;
        op->op.op = token.value;
        op->op.left = left;
        op->op.right = parse_factor(input);
        left = op;

        token = get_next_token(input);
    }

    return left;
}

Expr* parse_factor(const char **input) {
    Token token = get_next_token(input);
    if (token.type == TOKEN_NUMBER) {
        Expr *expr = malloc(sizeof(Expr));
        expr->type = EXPR_NUMBER;
        expr->number = token.value;
        return expr;
    }

    if (token.type == TOKEN_LPAREN) {
        Expr *expr = parse_expression(input);
        token = get_next_token(input);
        if (token.type != TOKEN_RPAREN) {
            printf("Expected ')'\n");
            exit(1);
        }
        return expr;
    }

    printf("Invalid token during parsing\n");
    exit(1);
}
