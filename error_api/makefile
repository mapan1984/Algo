main: main.o error_api.o
	gcc -o main main.o error_api.o
main.o: main.c error_api.h
	gcc -c main.c
error_api.o: error_api.c error_api.h
	gcc -c error_api.c

clean:
	rm -f *.o *~
