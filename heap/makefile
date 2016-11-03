main: main.o heap.o heap_sort.o priqueue.o
	gcc -o main main.o heap.o heap_sort.o priqueue.o
main.o: main.c heap.h
	gcc -c main.c
heap.o: heap.c heap.h
	gcc -c heap.c
priqueue.o: priqueue.c heap.h
	gcc -c priqueue.c
heap_sort.o: heap_sort.c heap.h
	gcc -c heap_sort.c
clean:
	rm *.o *.exe
