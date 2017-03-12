#include "binary_search.h"

void init_array(Array *a)
{
    a->base = (int*)malloc(sizeof(int)*10);
    a->len = ARINIT;
    a->top = 0;
}

int array_append(Array *a, int n)
{
    if(a->top >= a->len-1){ // grow
        int *ab = (int*)realloc(a->base, 
                        (ARGROW*a->len) * sizeof(int));
        if(ab == NULL){
            return -1;
        }
        a->len *= ARGROW;
        a->base = ab;
    }
    a->base[a->top] = n;
    return (a->top)++;
}
