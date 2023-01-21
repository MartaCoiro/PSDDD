link: list.o main.o item-int.o stack-array.o queue-2stack.o
	gcc list.o main.o item-int.o stack-array.o queue-2stack.o -o main.exe

link-arr: main.o item-string.o stack-array.o
	gcc main.o item-string.o stack-array.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c
	
stack-list.o:
	gcc -c stack-list.c
	
stack-array.o:
	gcc -c stack-array.c

queue-2stack.o:
	gcc -c queue-2stack.c

list.o:
	gcc -c list.c

clean:
	rm -f *.o main.exe
