default: run

objects = symtab.o test.o

test: $(objects)
	gcc -o test $(objects)

symtab.o: symtab.c symtab.h
	gcc -c symtab.c

test.o: test.c symtab.h
	gcc -c test.c

.PHONY: clean run
run: test
	./test
clean:
	rm -rf test $(objects)
