# Calculator

This is a simple C calculator that evaluates mathematical expressions. It uses lexing and parsing techniques to process the input and perform basic arithmetic operations, handle parentheses, and support variables.

## Building and Compilation

1. Install a C compiler like GCC (MinGW for Windows or GCC for Linux/macOS).
2. Run `make` to compile the program:
    ```bash
    make
    ```

   If you don't have `make` installed, you can manually compile the program using GCC:
    ```bash
    gcc -Wall -std=c99 -o calculator main.c lexer.c parser.c evaluator.c
    ```

## Running the Program

After compilation, you can run the program with the following command:
```bash
./calculator
