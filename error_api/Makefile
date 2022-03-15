all: error_api.o

error_api.o: error_api.c error_api.h
	gcc -c error_api.c

.PHONY: test clean
test: 
	gcc -c test.c
	gcc -o test test.o error_api.o
	./test

clean:
	rm -f *.o *~
