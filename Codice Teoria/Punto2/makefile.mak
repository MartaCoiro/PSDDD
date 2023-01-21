link : point.o main.o
	gcc point.o main.o -o punto.exe
point :
	gcc -c point.c
main :
	gcc -c main.c
clean:
	rm -f point.o main.o punto.exe