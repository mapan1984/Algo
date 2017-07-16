#include "priqueue.h"

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

    puts("heap extract max");
    int max = heap_extract_max(h);
    printf("max = %d\n", max);
    show_heap(h);

    puts("max heap insert 90");
    max_heap_insert(h, 90);
    show_heap(h);

    puts("max heap insert 100");
    max_heap_insert(h, 100);
    show_heap(h);

    puts("max heap insert 9");
    max_heap_insert(h, 9);
    show_heap(h);

    destroy_heap(h);
    return 0;
}
