#include "heap.h"

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

    puts("build max heap");
    build_max_heap(h);
    show_heap(h);

    destroy_heap(h);
    return 0;
}
