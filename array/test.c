#include <assert.h>
#include "array.h"

int main()
{
    Array *a = (Array *)malloc(sizeof(Array));
    assert(a->base == NULL);
    int i;
    for (i=0; i<10; i++) {
        array_append(a, i);
        assert(a->base[i] == i);
    }
    return 0;
}
