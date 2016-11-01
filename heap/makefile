main: main.o heap.o
	gcc -o main main.o heap.o
main.o: main.c heap.h
	gcc -c main.c
heap.o: heap.c heap.h
	gcc -c heap.c
