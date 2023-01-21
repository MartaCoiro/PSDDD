link: item-string.o BTree.o queue-list.o list.o stack-list.o  main.o
	gcc item-string.o BTree.o queue-list.o list.o  stack-list.o main.o  -o main.exe

link-int: item-int.o BTree.o queue-list.o list.o stack-list.o main.o
	gcc item-int.o BTree.o queue-list.o list.o stack-list.o main.o  -o main.exe

queue-list.o:
	gcc -c queue-list.c
stack-list.o:
	gcc -c stack-list.c
list.o:
	gcc -c list.c
main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

BTree.o:
	gcc -c BTree.c

clean:
	rm -f *.o main.exe
