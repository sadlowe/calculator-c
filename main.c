#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"

int main() {
    char input[256];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    const char *input_ptr = input;
    Token tokens[256];
    int token_index = 0;
    printf("Received input: '%s'\n", input);

    while (1) {
        tokens[token_index] = get_next_token(&input_ptr);
        if (tokens[token_index].type == TOKEN_END) break;
        token_index++;
    }

    Expr *expr = parse_expression(&input_ptr);

    double result = evaluate(expr);
    printf("Result: %.2f\n", result);

    free_expr(expr);


    return 0;
}
