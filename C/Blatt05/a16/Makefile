.PHONY: run clean

all:a16

textfun.o: textfun.c textfun.h
	cc -c -g -ansi -pedantic -Wall textfun.c
	
a16.o: a16.c textfun.h
	cc -c -g -ansi -pedantic -Wall a16.c

a16: a16.o textfun.o
	cc -g -ansi -pedantic -Wall textfun.o a16.o -o a16
	
	
run: a16
	./a16 kunft=yo Haus=Unterkunft

nemiver: a16
	nemiver ./a16 kunft=yo Haus=Unterkunft
