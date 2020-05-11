#include "./array.h"

/* 返回随机序数组 */
int *rlist(int start, int end, int num)
{
    static int first_time = TRUE;
    if (first_time) {
        first_time = FALSE;
        srand((unsigned int)time(NULL));
    }

    int *a = (int*)malloc(sizeof(int) * num);
    if (a == NULL) {
        printf("malloc error!");
        return NULL;
    }

    int i;
    for (i=0; i<num; i++) {
        a[i] = rand() % (end-start+1) + start;
    }
    return a;
}

void show(int *a, int len)
{
    int i;
    printf("array = ");
    for (i=0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
