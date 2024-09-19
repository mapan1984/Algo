all: test

count_sort: count_sort.o
	gcc -o count_sort count_sort.o
count_sort.o: count_sort.c
	gcc -c count_sort.c


test: count_sort
	./count_sort

.PHONY: clean
clean:
	rm -rf *.o count_sort

