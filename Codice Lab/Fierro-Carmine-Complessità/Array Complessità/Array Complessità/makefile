link : array.o utils.o main.o item-int.o
	gcc array.o utils.o main.o item-int.o -o array.exe

linkStr : array.o utils.o main.o item-string.o
	gcc array.o utils.o main.o item-string.o -o array.exe

array.o :
	gcc -c array.c

utils.o :
	gcc -c utils.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c

main.o : 
	gcc -c main.c

clean : 
	rm -f array.o utils.o main.o item-int.o item-string.o array.exe

