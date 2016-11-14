#include "heap.h"

/*
 * O(nlgn)
 */

void min_heap_sort(Heap *h)
{
    build_min_heap(h);
    int heap_size = h->heap_size;
    int *base = h->base;
    int i;
    for(i=heap_size; i >= 1; i--){
        swap(base+1, base+i);
        h->heap_size--;
        min_heapify(h, 1);
    }
}

void max_heap_sort(Heap *h)
{
    build_max_heap(h);
    int heap_size = h->heap_size;
    int *base = h->base;
    int i;
    for(i=heap_size; i >= 1; i--){
        swap(base+1, base+i);
        h->heap_size--;
        max_heapify(h, 1);
    }
}
