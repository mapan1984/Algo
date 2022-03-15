# all: array.o
#
# array.o: array.c array.h
#         gcc -c array.c
#
# .PHONY: test clean
# test:
#         gcc -c test.c
#         gcc -o test test.o array.o
#         ./test
#
# clean:
#         rm -f *.o *~
#
default: test run

# compile our library source code into position-independent code (PIC)
array.o: array.c
	gcc -c -Wall -Werror -fpic array.c
# creat shared library from object file
libarray.so: array.o
	gcc -shared -o libarray.so array.o
# Linking with a shared library
# Telling GCC where to find the shared library
test: libarray.so test.c
	gcc -L. -Wall -o test test.c -larray

.PHONY: clean run

run: test
	LD_LIBRARY_PATH=`pwd` ./test

clean:
	rm -rf *.o *.so .tags test
