all: test

heap:
	make heap.o -C ../../heap

heap_sort: heap heap_sort.o
	gcc -o heap_sort ../../heap/heap.o heap_sort.o
heap_sort.o: heap_sort.c ../../heap/heap.h
	gcc -c heap_sort.c


test: heap_sort
	./heap_sort

.PHONY: clean
clean:
	rm -rf *.o *~ heap_sort
	make clean -C ../../heap

