default: array.o read_num.o

objects = array.o read_num.o

# 使用之前的动态数组
INC := -I ../array

# 使用之前的动态数组
array.o: ../array/array.c ../array/array.h
	gcc $(INC) -c ../array/array.c -o array.o

read_num.o: read_num.c read_num.h ../array/array.h
	gcc $(INC) -c read_num.c -o read_num.o

.PHONY: clean
clean:
	-rm $(objects)
