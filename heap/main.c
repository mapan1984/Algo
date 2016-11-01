#include "heap.h"

int random_num(int start, int end)
{
    static int first_time = TRUE;

    if(first_time){
        first_time = FALSE;
        srand((unsigned int)time(NULL));
    }

    return rand() % (end-start+1) + start;
}

int main()
{
    heap h;
    initheap(&h, 100);
    int i;
    for(i=1; i<100; i++){
        h.base[i] = random_num(1, 10);
    }
    for(i=1; i<100; i++){
        printf("%d", h.base[i]);
    }
    build_min_heap(&h);
    return 0;
}
