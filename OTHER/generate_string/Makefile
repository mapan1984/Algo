all: gs error 

gs: generate_string.o ../error_api/error_api.o
	gcc -o gs generate_string.o ../error_api/error_api.o
generate_string.o: generate_string.c ../error_api/error_api.h
	gcc -c generate_string.c

error:
	(cd ../error_api/; make)

.PHONY: clean
clean:
	rm -f *.o *~
