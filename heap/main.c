#include "heap.h"

int main()
{
    int a[] = {2, 3, 1, 41, 23, 5, 4, 0};
    Heap h;

    puts("init heap");
    init_heap(&h, sizeof(a)/sizeof(int), a);
    show_heap(&h);

    puts("build min heap");
    build_min_heap(&h);
    show_heap(&h);

    puts("min heap sort");
    min_heap_sort(&h);
    show_heap(&h);

    puts("build max heap");
    build_max_heap(&h);
    show_heap(&h);

    puts("max heap sort");
    max_heap_sort(&h);
    show_heap(&h);

    puts("build max heap");
    build_max_heap(&h);
    show_heap(&h);

    puts("heap extract max");
    heap_extract_max(&h);
    show_heap(&h);

    puts("max heap insert 90");
    max_heap_insert(&h, 90);
    show_heap(&h);

    puts("max heap insert 100");
    max_heap_insert(&h, 100);
    show_heap(&h);

    puts("max heap insert 9");
    max_heap_insert(&h, 9);
    show_heap(&h);

    return 0;
}
