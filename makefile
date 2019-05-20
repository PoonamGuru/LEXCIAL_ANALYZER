lexical.out : main.o  color.o   file_handling.o word_parse.o
	      gcc -o lexical.out main.o  color.o   file_handling.o word_parse.o

main.o : main.c
	 gcc -c main.c

color.o : color.c
	gcc -c color.c

file_handling.o : file_handling.c
	          gcc -c  file_handling.c

word_parse.o :  word_parse.c
		gcc -c word_parse.c

clean : 
	rm *.o  *.out



