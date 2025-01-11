#include <stdio.h>
#include <stdlib.h>
#include "evaluator.h"

double evaluate(Expr *expr) {
    if (expr->type == EXPR_NUMBER) {
        return expr->number;
    }

    double left_value = evaluate(expr->op.left);
    double right_value = evaluate(expr->op.right);

    switch (expr->op.op) {
        case '+': return left_value + right_value;
        case '-': return left_value - right_value;
        case '*': return left_value * right_value;
        case '/': return left_value / right_value;
        default:
            printf("Unknown operator %c\n", expr->op.op);
            exit(1);
    }
}

void free_expr(Expr *expr) {
    if (expr->type == EXPR_OPERATOR) {
        free_expr(expr->op.left);
        free_expr(expr->op.right);
    }
    free(expr);
}
