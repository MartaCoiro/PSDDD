linkInt : bst.o main.o item-int.o stack-list.o list.o
	gcc bst.o main.o item-int.o stack-list.o list.o -o bst.exe

link : bst.o main.o item-string.o 
	gcc bst.o main.o item-string.o -o bst.exe

bst.o :
	gcc -c bst.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c
stack-list.o :
	gcc -c stack-list.c 
list.o :
	gcc -c list.c
main.o :
	gcc -c main.c


clean :
	rm	-f	bst.o main.o item-int.o item-string.o stack-list.o list.o bst.exe
