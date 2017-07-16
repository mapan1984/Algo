all: heap test

heap:
	(cd ../heap/; make)

test: ../heap/heap.o priqueue.o test.o
	gcc -o test ../heap/heap.o priqueue.o test.o
test.o: test.c priqueue.h
	gcc -c test.c
priqueue.o: priqueue.c priqueue.h
	gcc -c priqueue.c

.PHONY: clean
clean:
	rm -f *.o *~

