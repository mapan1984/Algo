#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// 展示长度为len的数组a
void show(int *a, int len)
{
    int i;
    printf("array = ");
    for (i=0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* 返回一个指向包含n个范围在start-end之间的随机数的数组的指针 */
int *rlist(int start, int end, int num)
{
    static int first_time = TRUE;
    if(first_time){
        first_time = FALSE;
        srand((unsigned int)time(NULL));
    }

    int *a = (int*)malloc(sizeof(int) * num);
    if(a == NULL){
        printf("malloc error!");
        return NULL;
    }

    int i;
    for(i=0; i<num; i++){
        a[i] = rand() % (end-start+1) + start;
    }
    return a;
}

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
    while (lpos < lend) {
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
    if(left < right){
        center = (left + right) / 2;
        msort(a, t, left, center);
        msort(a, t, center+1, right);
        merge(a, t, left, center+1, right);
    }
}

// 排序元素数目为n的数组a
void merge_sort(int *a, int n)
{
    int *t = (int *)malloc(n * sizeof(int));

    if (t != NULL) {
        msort(a, t, 0, n-1);
        free(t);
    } else {
        printf("No space for tmp array!");
    }
}

int main()
{
    int i;
    time_t start = time(NULL);
    for (i=0; i<1000; i++) {
        int *a = rlist(0, 1000, 5000000);
        merge_sort(a, 1000);
        free(a);
    }
    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);
    return 0;
}
