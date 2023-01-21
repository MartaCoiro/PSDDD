linkInt : bst.o main.o item-int.o list.o
	gcc bst.o main.o item-int.o list.o -o bst.exe

link : bst.o main.o item-string.o list.o
	gcc bst.o main.o item-string.o list.o -o bst.exe

bst.o :
	gcc -c bst.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c

main.o :
	gcc -c main.c
list.o:
	gcc -c list.c

clean :
	rm	-f	bst.o main.o item-int.o item-string.o list.o bst.exe
