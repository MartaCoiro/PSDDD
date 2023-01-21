link-int: item-int.o list.o main.o automobile.o catalogo.o utils.o
	gcc item-int.o list.o main.o  automobile.o catalogo.o utils.o  -o linkedlist.exe
link-str: item-string.o list.o main.o automobile.o catalogo.o utils.o
	gcc item-string.o list.o main.o  automobile.o catalogo.o utils.o -o linkedlist.exe
link-auto: item-auto.o list.o main.o automobile.o catalogo.o utils.o
	gcc item-auto.o list.o main.o  automobile.o catalogo.o utils.o -o linkedlist.exe
item-int.o:
	gcc -c item-int.c
item-string.o:
	gcc -c item-string.c
item-auto.o:
	gcc -c item-auto.c
list.o:
	gcc -c list.c
main.o:
	gcc -c main.c
catalogo.o:
	gcc -c catalogo.c
automobile.o:
	gcc -c automobile.c
utils.o:
	gcc -c utils.c
clean:
	rm -f item-int.o item-string.o item-auto.o list.o main.o automobile.o catalogo.o utils.o linkedlist.exe