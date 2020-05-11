#include "merge_sort.h"
#include "../array.h"

int main()
{
    time_t start = time(NULL);
    // for (int i=0; i<1000; i++) {
    //     int *a = rlist(0, 1000, 5000000);
    //     merge_sort(a, 1000);
    //     free(a);
    // }
    int *a = rlist(0, 1000, 10);
    show(a, 10);
    merge_sort(a, 0, 9);
    show(a, 10);
    free(a);
    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);
    return 0;
}
