#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char *argv[]) {
	Interpreter i;
	FILE *f;
	int length;

	if (argc != 2) {
		printf("usage: %s [file]\n", argv[0]);
		return 1;
	}

	f = fopen(argv[1], "r");
	fseek(f, 0, SEEK_END);
	length = ftell(f);
	i.input = malloc(length);

	fseek(f, 0, SEEK_SET);
	fread(i.input, 1, length, f);
	fclose(f);

	i.pc = 0;
	i.size = 256;
	i.pos = 0;
	i.memory = calloc(i.size, sizeof(int));

	i.state.state = NULL;
	i.state.bracket = 0;

	while (i.pc < length) {
		switch (i.input[i.pc]) {
			case '+':
				i.memory[i.pos]++;
				break;

			case '-':
				i.memory[i.pos]--;
				break;

			case '>':
				if (++i.pos >= i.size) i.memory = realloc(i.memory, i.size *= 2);
				break;

			case '<':
				if (i.pos != 0) i.pos--;
				break;

			case '[':
				i.state.state = &i.state;
				i.state.bracket = i.pc;
				break;

			case ']':
				if (i.memory[i.pos] == 0) i.state = *(InterpreterState *)i.state.state;
				else i.pc = i.state.bracket;
				break;

			case '.':
				fputc(i.memory[i.pos], stdout);
				break;

			case ',':
				i.memory[i.pos] = fgetc(stdout);
				break;

			default: break;
		}

		i.pc++;
	}

	return 0;
}
