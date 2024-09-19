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

    // 初始化随机数组
    int num = 30;
    int min = 0;
    int max = 100;
    int *a = rlist(min, max, num);
    show(a, num);

    // 归并排序
    merge_sort(a, 0, num - 1);
    show(a, num);

    // 释放数组空间
    free(a);

    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);

    return 0;
}
