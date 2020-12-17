#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void show(int *a, int len)
{
    int i = 0;
    while (i < len) {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
}

// 初始时：x[n] = {1, 2, 3, ..., n}
// n 为长度
// t 为第一元素下标
// 输出全排列
void back_track(int *x, int n, int t)
{
    if (t == n) {
        show(x, n);
    } else {
        int i;
        for (i=t; i<n; i++) {
            swap(x+t, x+i);
            back_track(x, n, t+1);
            swap(x+t, x+i);
        }
    }
}

int main()
{
    int t = 0;
    int x[] = {1, 2, 3};
    int len = sizeof(x) / sizeof(int);
    back_track(x, len, t);
    return 0;
}
