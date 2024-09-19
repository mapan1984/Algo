default: test


heap.o:
	make heap.o -C ../heap

priqueue.o: priqueue.c priqueue.h
	gcc -c priqueue.c

test.o: test.c priqueue.h
	gcc -c test.c

test: heap.o priqueue.o test.o
	gcc -o test ../heap/heap.o priqueue.o test.o
	./test

.PHONY: clean
clean:
	rm -rf test *.o *~
	make clean -C ../heap
