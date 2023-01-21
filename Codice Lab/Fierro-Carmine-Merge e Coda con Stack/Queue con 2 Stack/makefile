link : list main item-int stack-list queue-stack 
	gcc list.o main.o item-int.o stack-list.o queue-stack.o -o queue

linkArr : list main item-string stack-array queue-stack 
	gcc main.o item-string.o stack-array.o queue-stack.o -o queue

list :
	gcc -c list.c

item-int :
	gcc -c item-int.c

item-string :
	gcc -c item-string.c

main :
	gcc -c main.c

queue-stack :
	gcc -c queue-stack.c

stack-list:
	gcc -c stack-list.c

stack-array:
	gcc -c stack-array.c

clean :
	rm -f list.o main.o item-int.o item-string.o	stack-array.o	queue-stack.o stack-list.o queue.exe
