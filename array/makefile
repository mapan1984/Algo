all: array.o

array.o: array.c array.h
	gcc -c array.c

.PHONY: test clean
test: 
	gcc -c test.c
	gcc -o test test.o array.o
	./test

clean:
	rm -f *.o *~
