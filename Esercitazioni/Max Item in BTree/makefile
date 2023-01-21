link: item-string.o BTree.o main.o stack-list.o list.o
	gcc  main.o item-string.o BTree.o stack-list.o list.o -o main.exe

link-str: BTree.o main.o item-string.o stack-list.o list.o
	gcc BTree.o main.o item-string.o stack-list.o list.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

BTree.o:
	gcc -c BTree.c
stack-list.o:
	gcc -c  stack-list.c
list.o:
	gcc -c list.c
clean:
	rm -f *.o main.exe
