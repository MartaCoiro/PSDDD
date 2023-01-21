linkInt : bst.o main.o item-int.o stack-array.o
	gcc bst.o main.o item-int.o stack-array.o -o bst.exe

link : bst.o main.o item-string.o stack-array.o
	gcc bst.o main.o item-string.o stack-array.o -o bst.exe

bst.o :
	gcc -c bst.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c

main.o :
	gcc -c main.c
stack-array.o:
	gcc -c stack-array.c

clean :
	rm	-f	bst.o main.o item-int.o item-string.o stack-array.o bst.exe
