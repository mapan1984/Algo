all: heap heap_sort

heap:
	(cd ../../heap/; make)

heap_sort: ../../heap/heap.o heap_sort.o
	gcc -o heap_sort ../../heap/heap.o heap_sort.o
heap_sort.o: heap_sort.c ../../heap/heap.h
	gcc -c heap_sort.c

.PHONY: clean
clean:
	rm -f *.o *~

