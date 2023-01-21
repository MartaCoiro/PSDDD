link:item-int.o main.o stack-array.o
	gcc  item-int.o main.o stack-array.o -o dinamic.exe

link-str:item-string.o main.o stack-array.o
	gcc  item-string.o main.o stack-array.o -o dinamic.exe

main.o:
	gcc -c main.c
item-int.o:
	gcc -c item-int.c
item-string.o:
	gcc -c item-string.c
stack-array.o:
	gcc -c  stack-array.c
clean: 
	rm -f *.o *.exe
