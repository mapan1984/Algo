#include "heap.h"

int main()
{
    int a[] = {2, 3, 1, 41, 23, 5, 4, 0};
    Heap h;

    init_heap(&h, sizeof(a)/sizeof(int), a);
    show_heap(&h);

    build_min_heap(&h);
    show_heap(&h);

    min_heap_sort(&h);
    show_heap(&h);

    build_max_heap(&h);
    show_heap(&h);

    max_heap_sort(&h);
    show_heap(&h);

    build_max_heap(&h);
    show_heap(&h);

    heap_extract_max(&h);
    show_heap(&h);

    max_heap_insert(&h, 90);
    show_heap(&h);

    max_heap_insert(&h, 100);
    show_heap(&h);

    max_heap_insert(&h, 9);
    show_heap(&h);

    return 0;
}
