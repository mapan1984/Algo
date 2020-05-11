default: run

objects = array.o merge_sort.o test.o

array.o: ../array.c ../array.h
	gcc -c ../array.c -o array.o
merge_sort.o: merge_sort.c merge_sort.h
	gcc -c merge_sort.c -o merge_sort.o
test.o: test.c merge_sort.h ../array.h
	gcc -c test.c -o test.o
test: $(objects)
	gcc -o test $(objects)

run: test
	./test

.PHONY: clean
clean:
	rm -rf test $(objects)
