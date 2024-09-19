#include <stdio.h>
#include <stdlib.h>

void show(int *a, int len)
{
    int i;
    printf("array = ");
    for(i = 0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


// 输入：
//     a[0..len]为待排序数组
//     r[0..len]用于保存结果
//     0 ≤ all elements of a[0..len] ≤ k
void count_sort(int *a, int *r, int len, int k)
{
    int i;

    // 申请并清零临时计数空间c[0..k]
    int *c = (int *)calloc(k+1, sizeof(int));

    for (i = 0; i < len; i++) {
        c[a[i]] = c[a[i]] + 1;
    }
    // show(c, k+1);

    // c[i] now contains the number of elements equal to i

    for (i = 1; i <= k; i++) {
        c[i] = c[i] + c[i-1];
    }
    // show(c, k+1);

    // c[i] now contains the number of elements less than or equal i

    for (i = len-1; i >= 0; i--) {
        r[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }

    // 释放临时计数空间c[0..k]
    free(c);
}

int main()
{
    int k = 5;
    int len = 8;
    int a[] = {2, 5, 3, 0, 2, 3, 0, 3};
    show(a, len);

    int b[8];

    count_sort(a, b, len, k);
    show(b, len);

    return 0;
}
