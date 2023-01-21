link: list.o main.o item-int.o queue-list.o
	gcc list.o main.o item-int.o queue-list.o -o main.exe

link-arr: main.o item-string.o queue-array.o
	gcc main.o item-string.o queue-array.o -o main.exe

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

list.o:
	gcc -c list.c

clean:
	rm -f *.o main.exe
