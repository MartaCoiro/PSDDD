link-int: bst.o main.o item-int.o queue-array.o
	gcc -g bst.o main.o item-int.o queue-array.o -o main.exe

link-str: item-string.o bst.o main.o
	gcc -g main.o item-string.o bst.o -o main.exe

main.o:
	gcc -g -c main.c

item-int.o:
	gcc -g -c item-int.c

item-string.o:
	gcc -g -c item-string.c

bst.o:
	gcc -g -c bst.c

queue-array.o:
	gcc -g -c queue-array.c

clean:
	rm -f *.o main.exe
