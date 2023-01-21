main :  utils.o list.o  studente.o item-studente.o  classe.o data.o main.o
	gcc  utils.o list.o  studente.o item-studente.o  classe.o data.o main.o -o main

utils.o:
	gcc -c utils.c

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

data.o:
	gcc -c data.c

studente.o:
	gcc -c studente.c

item-studente.o:
	gcc -c item-studente.c

classe.o:
	gcc -c classe.c

clean:
	rm -f *.o main


