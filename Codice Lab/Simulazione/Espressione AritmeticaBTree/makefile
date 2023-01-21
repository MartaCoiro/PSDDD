link: item-string.o list.o stack-list.o BTree.o main.o
	gcc item-string.o list.o stack-list.o BTree.o main.o -o exp.exe
item-string.o:
	gcc -c item-string.c
list.o:
	gcc -c list.c
stack-list.o:
	gcc -c stack-list.c
BTree.o:
	gcc -c BTree.c
main.o:
	gcc -c  main.c

clean :
	rm -f BTree.o main.o item-string.o	stack-list.o  list.o	exp.exe
