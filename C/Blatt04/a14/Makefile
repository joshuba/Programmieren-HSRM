.PHONY: run clean

all:a14

list.o: list.c list.h
	cc -c -g -ansi -pedantic -Wall list.c
	
a14.o: a14.c list.h
	cc -c -g -ansi -pedantic -Wall a14.c

a14: a14.o list.o
	cc -g -ansi -pedantic -Wall list.o a14.o -o a14
	
	
run: a14
	./a14 kunft=yo Haus=Unterkunft
