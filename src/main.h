#ifndef MAIN_H
#define MAIN_H

typedef struct {
	unsigned int bracket;
	void *state;
} InterpreterState;

typedef struct {
	char *input;
	unsigned int pc;

	unsigned int pos;
	unsigned int size;
	int *memory;

	InterpreterState state;
} Interpreter;

#endif /* MAIN_H */
