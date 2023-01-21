link: list.o main.o item-string.o stack-list.o parentesi.o
	gcc list.o main.o item-string.o stack-list.o parentesi.o -o stack.exe

link-arr:main.o item-string.o stack-list.o list.o parentesi.o 
	gcc main.o item-string.o stack-list.o  list.o parentesi.o -o  stack.exe
	
list.o:
	gcc -c list.c
main.o:
	gcc -c main.c
item-int.o:
	gcc -c item-int.c
item-string.o:
	gcc -c item-string.c
stack-array.o:
	gcc -c stack-array.c
stack-list.o:
	gcc -c  stack-list.c
parentesi.o:
	gcc -c parentesi.c
clean:
	rm -f list.o item-int.o item-string.o stack-int.o stack-array.o main.o stack-list.o list.o parentesi.o stack.exe