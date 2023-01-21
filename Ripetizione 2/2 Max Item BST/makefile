linkInt : bst main item-int 
	gcc bst.o main.o item-int.o -o bst.exe

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


clean :
	rm	-f	bst.o main.o item-int.o item-string.o bst.exe
