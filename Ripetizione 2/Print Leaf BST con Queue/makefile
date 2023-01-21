linkInt : bst main item-int queue-list list
	gcc bst.o main.o item-int.o queue-list.o list.o -o bst.exe

link : bst main item-string queue-list list
	gcc bst.o main.o item-string.o queue-list.o list.o -o bst.exe

bst :
	gcc -c bst.c

item-int :
	gcc -c item-int.c

item-string :
	gcc -c item-string.c

main :
	gcc -c main.c

queue-list :
	gcc -c queue-list.c

list :
	gcc -c list.c

clean :
	rm	-f	bst.o main.o item-int.o item-string.o queue-list.o list.o bst.exe
