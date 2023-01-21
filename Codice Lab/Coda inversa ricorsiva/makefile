link: item-int.o list.o queue-list.o main.o
	gcc item-int.o list.o queue-list.o main.o -o coda.exe
link-str:item-string.o list.o queue-list.o main.o
	gcc item-string.o list.o queue-list.o main.o -o coda.exe

item-int.o:
	gcc -c item-int.c
item-string.o:
	gcc -c item-string.c
list.o:
	gcc -c list.c 
queue-list.o:
	gcc -c queue-list.c
main.o:
	gcc -c main.c
clean :
	rm -f item-int.o item-string.o list.o queue-list.o main.o coda.exe


