CC=gcc
CFLAGS=-g -O0 -Wall -Werror -Wextra -pedantic -ansi
LDFLAGS=-g -Wall

main: main.o string_builder.o

clean:
	-rm -f main *.o

