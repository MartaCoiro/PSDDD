link : list.o main.o	utils.o	item-int.o
	gcc list.o main.o 	utils.o	item-int.o -o listRec.exe

linkStr : list.o main.o	utils.o	item-string.o
	gcc list.o main.o	utils.o	item-string.o -o listRec.exe

linkStudente: list.o main.o utils.o item-struct.o
	gcc list.o main.o utils.o item-struct.o -o listRec.exe
list.o :
	gcc -c list.c

utils.o:
	gcc	-c	utils.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c
item-struct.o :
	gcc -c item-struct.c
main.o : 
	gcc -c main.c
clean : 
	rm -f list.o main.o item-int.o	utils.o	item-struct.o item-string.o listRec.exe