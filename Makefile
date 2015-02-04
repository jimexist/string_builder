CC=gcc
CCFLAGS=-g -O0 -Wall -Werror -ansi
LDFLAGS=-g -Wall

main: main.o string_builder.o

clean:
	\rm -f main *.o
	