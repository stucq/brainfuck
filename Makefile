brainfuck: src/main.o
	$(CC) src/main.o -o brainfuck

src/main.o: src/main.c src/main.h
	$(CC) src/main.c -c -o src/main.o 

.PHONY: clean
clean: src/main.o
	rm -f src/main.o
