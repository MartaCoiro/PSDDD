link: item-string.o BTree.o main.o
	gcc  main.o item-string.o BTree.o -o main.exe

link-int: BTree.o main.o item-int.o
	gcc BTree.o main.o item-int.o -o main.exe

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
