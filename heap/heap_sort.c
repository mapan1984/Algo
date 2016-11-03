#include "heap.h"

/*
 * O(nlgn)
 */

void min_heap_sort(heap *h)
{
    build_min_heap(h);
    int len = h->length;
    int *base = h->base;
    int i;
    for(i=len; i >= 2; i--){
        swap(base+1, base+i);
        h->heap_size--;
        min_heapify(h, 1);
    }
}

void max_heap_sort(heap *h)
{
    build_max_heap(h);
    int len = h->length;
    int *base = h->base;
    int i;
    for(i=len; i >= 2; i--){
        swap(base+1, base+i);
        h->heap_size--;
        max_heapify(h, 1);
    }
}
