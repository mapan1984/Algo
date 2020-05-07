#include <stdio.h>
#include <assert.h>
#include "array.h"

int main()
{
    Array *a = (Array *)malloc(sizeof(Array));
    assert(a->base == NULL);
    int i;
    for (i=0; i<20; i++) {
        array_append(a, i);
        assert(a->base[i] == i);
    }
    for (i=0; i<20; i++) {
        printf("%d\n", a->base[i]);
    }
    return 0;
}
