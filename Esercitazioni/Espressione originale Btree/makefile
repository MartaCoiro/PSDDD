link: item-string.o BTree.o main.o list.o stack-list.o
	gcc  main.o item-string.o BTree.o list.o stack-list.o -o main.exe

link-str: BTree.o main.o item-string.o list.o stack-list.o
	gcc BTree.o main.o item-string.o list.o stack-list.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

BTree.o:
	gcc -c BTree.c
list.o:
	gcc -c list.c
stack-list.o:
	gcc -c stack-list.c
clean:
	rm -f *.o main.exe
