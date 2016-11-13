all: gs error 

gs: generate_string.o ../error_api/error_api.o
	gcc -o gs generate_string.o ../error_api/error_api.o
generate_string.o: generate_string.c
	gcc -c generate_string.c

error:
	(cd ../error_api/; make)

clean:
	rm -f *.o *~
	(cd ../error_api/; make clean)
