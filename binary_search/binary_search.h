#ifndef __BINARY_SEARCH_H_
#define __BINARY_SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define flase 0

// 维持自身长度与首元素的数组
typedef struct{
    int *base;
    int top;
    int len;
} Array;

enum {
    ARINIT = 10, // Array初始长度
    ARGROW = 2  // Array每次扩充长度
};

void init_array(Array *a);
int array_append(Array *a, int n);
int getnum(char const *name, Array *a);

#endif
