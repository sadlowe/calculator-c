#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "lexer.h"

Token get_next_token(const char **input) {
    // Skip whitespace, including newline and carriage return
    while (**input == ' ' || **input == '\t' || **input == '\n' || **input == '\r') {
        (*input)++;
    }

    if (**input == '\0') {
        // End of input
        return (Token){TOKEN_END, 0};
    }

    if (isdigit(**input)) {
        double value = strtod(*input, (char **)input); // Read a number
        return (Token){TOKEN_NUMBER, value};
    }

    if (**input == '+' || **input == '-' || **input == '*' || **input == '/') {
        char op = **input;
        (*input)++;
        return (Token){TOKEN_OPERATOR, op};
    }

    if (**input == '(') {
        (*input)++;
        return (Token){TOKEN_LPAREN, 0};
    }

    if (**input == ')') {
        (*input)++;
        return (Token){TOKEN_RPAREN, 0};
    }

    // If we reach this point, it's an invalid token
    printf("Invalid token: '%c'\n", **input);  // Debugging line
    return (Token){TOKEN_INVALID, 0};
}




