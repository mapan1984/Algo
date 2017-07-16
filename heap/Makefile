objects = test.o heap.o

test: $(objects)
	gcc -o test $(objects)

test.o: test.c heap.h
	gcc -c test.c
heap.o: heap.c heap.h
	gcc -c heap.c

.PHONY: clean
clean:
	rm test $(objects)
