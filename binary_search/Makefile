default: test

objects = array.o read_num.o binary_search.o main.o

# 使用之前的动态数组
INC := -I ../array -I ../utils

# 使用之前的动态数组
array.o: ../array/array.c ../array/array.h
	gcc $(INC) -c ../array/array.c -o array.o

read_num.o: ../utils/read_num.c ../utils/read_num.h
	gcc $(INC) -c ../utils/read_num.c -o read_num.o

binary_search.o: binary_search.c binary_search.h
	gcc $(INC) -c binary_search.c

main.o: main.c
	gcc $(INC) -c main.c -o main.o

.PHONY: clean test
test: $(objects)
	gcc $(INC) -o test $(objects)
clean:
	rm -rf test $(objects)

