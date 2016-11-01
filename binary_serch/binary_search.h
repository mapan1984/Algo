#ifndef __BINARY_SEARCH_H_
#define __BINARY_SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define flase 0

typedef struct{
    int *base;
    int top;
    int len;
}array;

void init_array(array *a);
void expend_array(array *a);
void array_append(array *a, int n);
int getnum(char const *name, array *a);

#endif
