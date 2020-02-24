all: Suduku

Suduku: Suduku.o
	gcc -Wall -Werror -fsanitize=address -std=c99 Suduku.c -o Suduku
Suduku.o: Suduku.c
	gcc -Wall -Werror -fsanitize=address -std=c99 Suduku.c

clean:
	rm -rf *o Suduku

