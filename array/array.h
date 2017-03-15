#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * 维持自身长度与首元素的数组
 * [0][1][2][3][ ][ ][ ]
 * top = 4
 * len = 7
 */
typedef struct{
    int *base;  // array of int
    int top;  // current number of values
    int len;  // allocated number of values
} Array;

enum {
    ARINIT = 1, // Array初始长度
    ARGROW = 2  // Array每次扩充倍数
};

int array_append(Array *a, int n);
int array_remove(Array *a, int n);

#endif
