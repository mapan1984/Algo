#include "quick_sort.h"

int main()
{
    time_t start = time(NULL);

    // for (int i=0; i<1000; i++) {
    //     int *a = rlist(0, 1000, 50000);
    //     show(a, 50000);
    //     quick_sort(a, 0, 1000);
    //     show(a, 50000);
    //     free(a);
    // }

    int *a = rlist(0, 1000, 10);
    show(a, 10);
    quick_sort(a, 0, 9);
    show(a, 10);
    free(a);

    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);

    return 0;
}
