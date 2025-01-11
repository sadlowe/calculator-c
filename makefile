CC = gcc
CFLAGS = -Wall -std=c99

all: calculator

calculator: main.o lexer.o parser.o evaluator.o
	$(CC) $(CFLAGS) -o calculator main.o lexer.o parser.o evaluator.o

main.o: main.c lexer.h parser.h evaluator.h
	$(CC) $(CFLAGS) -c main.c

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h lexer.h
	$(CC) $(CFLAGS) -c parser.c

evaluator.o: evaluator.c evaluator.h
	$(CC) $(CFLAGS) -c evaluator.c

clean:
	rm -f *.o calculator
