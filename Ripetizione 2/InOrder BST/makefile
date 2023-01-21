linkInt : bst main item-int stack-list list
	gcc bst.o main.o item-int.o stack-list.o list.o -o bst.exe

link : bst main item-string 
	gcc bst.o main.o item-string.o -o bst.exe

bst :
	gcc -c bst.c

item-int :
	gcc -c item-int.c

item-string :
	gcc -c item-string.c

main :
	gcc -c main.c

stack-list :
	gcc -c stack-list.c 

list :
	gcc -c list.c
clean :
	rm	-f	bst.o main.o item-int.o item-string.o stack-list.o list.o bst.exe
