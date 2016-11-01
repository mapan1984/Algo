#include "binary_search.h"

void init_array(array *a){
    a->base = (int*)malloc(sizeof(int)*10);
    a->top = 0;
    a->len = 10;
}

void expend_array(array *a){
    a->base = (int*)realloc(a->base, sizeof(int)*(a->len+10));
    a->len += 10;
}

void array_append(array *a, int n){
    if(a->top == a->len-1){
        expend_array(a);
    }
    a->base[a->top++] = n;
}
