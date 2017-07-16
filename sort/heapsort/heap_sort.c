#include "../../heap/heap.h"

void min_heap_sort(Heap *h)
{
    build_min_heap(h);
    int *base = h->base;
    int heap_size = h->heap_size;
    for ( ; heap_size >= 1; heap_size--) {
        swap(base+1, base+heap_size);
        h->heap_size--;
        min_heapify(h, 1);
    }
}

void max_heap_sort(Heap *h)
{
    build_max_heap(h);
    int *base = h->base;
    int heap_size = h->heap_size;
    for ( ; heap_size >= 1; heap_size--) {
        swap(base+1, base+heap_size);
        h->heap_size--;
        max_heapify(h, 1);
    }
}

int main()
{
    int a[] = {2, 3, 1, 41, 23, 5, 4, 0};
    Heap *h = (Heap *)malloc(sizeof(Heap));

    puts("init heap");
    init_heap(h, sizeof(a)/sizeof(int), a);
    show_heap(h);

    puts("build min heap");
    build_min_heap(h);
    show_heap(h);

    puts("min heap sort");
    min_heap_sort(h);
    show_heap(h);

    puts("build max heap");
    build_max_heap(h);
    show_heap(h);

    puts("max heap sort");
    max_heap_sort(h);
    show_heap(h);

    destroy_heap(h);

    return 0;
}
