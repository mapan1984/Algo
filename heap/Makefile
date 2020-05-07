default: run

objects = test.o heap.o

test: $(objects)
	gcc -o test $(objects)

test.o: test.c heap.h
	gcc -c test.c
heap.o: heap.c heap.h
	gcc -c heap.c

run: test
	./test

.PHONY: clean
clean:
	rm -rf test $(objects)
