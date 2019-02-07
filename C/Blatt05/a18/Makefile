.PHONY: run clean

a18:a18.c
	cc -DDE -DSIZE=2 a18.c -o a18
	
valgrind:a18
	valgrind ./a18
	
run:a18
	./a18

nemiver:a18
	nemiver ./a18


