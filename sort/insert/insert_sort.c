#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void show(int *a, int len)
{
    int i;
    printf("array = ");
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 * mark first element as sorted
 * for each unsorted element
 *     'extract' the element
 *     for i = lastSortedIndex to 0
 *         if currentSortedElement > extractedElement
 *             move sorted element to the right by 1
 *         else
 *             insert extracted element
 */

void sort1(int *a, int len)
{
    int i, j;
    for (i = 1; i < len; i++) {
        for (j = i; j > 0 && a[j-1] > a[j]; j--) {
            swap(a+j-1, a+j);
        }
    }
}

void sort2(int *a, int len)
{
    int i, j;
    for (i = 1; i < len; i++) {
        for (j = i; j > 0 && a[j-1] > a[j]; j--) {
            int t = a[j-1];
            a[j-1] = a[j];
            a[j] = t;
        }
    }
}

void sort3(int *a, int len)
{
    int i, j;
    for (i = 1; i < len; i++) {
        int t = a[i];
        for (j = i; j > 0 && a[j-1] > t; j--) {
            a[j] = a[j-1];
        }
        a[j] = t;
    }
}

int main()
{
    int a[] = {2,1,8,5,6,9,0};
    int len = sizeof(a)/sizeof(int);
    printf("len=%d\n", len);

    show(a, len);
    //sort1(a, len);
    //sort2(a, len);
    sort3(a, len);
    show(a, len);

    return 0;
}
