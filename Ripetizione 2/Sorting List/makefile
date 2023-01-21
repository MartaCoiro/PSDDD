link-int: item-int.o list.o main.o utils.o
	gcc item-int.o list.o main.o utils.o -o linkedlist.exe
link-str: item-string.o list.o main.o
	gcc item-string.o list.o main.o -o linkedlist.exe
item-int.o:
	gcc -c item-int.c
item-string.o:
	gcc -c item-string.c
list.o:
	gcc -c list.c
main.o:
	gcc -c main.c
utils.o:
	gcc -c utils.c
clean:
	rm -f item-int.o item-string.o list.o main.o linkedlist.exe