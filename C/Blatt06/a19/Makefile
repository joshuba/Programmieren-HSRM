.PHONY: run clean

a19:a19.c
	cc -g -ansi -pedantic -Wall a19.c -o a19
	
valgrind:a19
	valgrind ./a19
	
run:a19
	./a19 3.5717178E-12

nemiver:a19
	nemiver ./a19
