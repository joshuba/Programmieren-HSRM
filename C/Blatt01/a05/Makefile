.PHONY: run clean run2

a05:a05.c
	cc -g -ansi -pedantic -Wall a05.c -o a05
	
a05_2:a05_2.c
	cc -g -ansi -pedantic -Wall a05_2.c -o a05_2
	
run:a05
	./a05
	
//CAT = Schreibe datei in standardeingabe und anschließend die ausgabe in datei
run2:a05_2
	cat text.txt | ./a05_2 >ergebnis.txt
	
clean:
	rm a05
