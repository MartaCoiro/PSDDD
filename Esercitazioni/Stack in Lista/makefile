link-int: list.o main.o item-int.o stack-list.o 
	gcc list.o main.o item-int.o stack-list.o  -o stack.exe

link-arr: main.o item-string.o stack-array.o 
	gcc main.o item-string.o stack-array.o -o stack.exe
	
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
	gcc -c stack-list.c
clean:
	rm -f list.o item-int.o item-string.o stack-list.o stack-array.o main.o stack.exe