objects = array.o read_num.o binary_search.o

binary_search: $(objects)
	gcc -o binary_search $(objects)

array.o: array.c binary_search.h
	gcc -c array.c
read_num.o: read_num.c binary_search.h
	gcc -c read_num.c
binary_search.o: binary_search.c binary_search.h
	gcc -c binary_search.c

.PHONY: clean
clean:
	-rm binary_search $(objects)
