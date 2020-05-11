#include "merge_sort.h"
#include "../array.h"

/* Lpos = start of left half; Rpos = start of right half */
void merge(int a[], int t[], int lpos, int rpos, int rend)
{
    int lend = rpos - 1;
    int tpos = lpos;


    /* main loop */
    while (lpos <= lend && rpos <= rend) {
        if (a[lpos] <= a[rpos]) {
            t[tpos++] = a[lpos++];
        } else {
            t[tpos++] = a[rpos++];
        }
    }

    /* Copy rest of first half */
    while (lpos <= lend) {
        t[tpos++] = a[lpos++];
    }

    /* Copy rest of second half */
    while (rpos <= rend) {
        t[tpos++] = a[rpos++];
    }

    /* Copy t back */
    for (; rend >= 0; rend--) {
        a[rend] = t[rend];
    }
}

void msort(int a[], int t[], int left, int right)
{
    int center;
    if (left < right) {
        center = (left + right) / 2;
        msort(a, t, left, center);
        msort(a, t, center+1, right);
        merge(a, t, left, center+1, right);
    }
}

// 排序元素数目为n的数组a
void merge_sort(int *a, int left, int right)
{
    int *t = (int *)malloc((right - left + 1) * sizeof(int));

    if (t != NULL) {
        msort(a, t, left, right);
        free(t);
    } else {
        printf("No space for tmp array!");
    }
}

