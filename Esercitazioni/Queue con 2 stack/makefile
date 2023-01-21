link: list.o main.o item-int.o queue-list.o stack-list.o 
	gcc list.o main.o item-int.o queue-list.o stack-list.o -o main.exe

link-arr: main.o item-string.o queue-array.o stack-list.o
	gcc main.o item-string.o queue-array.o stack-list.o -o main.exe

link-stack: main.o item-int.o queue-stack.o stack-list.o list.o
	gcc main.o item-int.o queue-stack.o stack-list.o list.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

queue-list.o:
	gcc -c queue-list.c

queue-array.o:
	gcc -c queue-array.c
queue-stack.o:
	gcc -c queue-stack.c
list.o:
	gcc -c list.c
stack-list.o:
	gcc -c stack-list.c
clean:
	rm -f *.o main.exe
