#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

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
void merge(int a[], int t[], int lpos, int rpos, int right_end)
{
    int i, left_end, num_elements, tmp_pos;

    left_end = rpos - 1;
    tmp_pos = lpos;
    num_elements = right_end - lpos + 1;

    /* main loop */
    while(lpos <= left_end && rpos <= right_end){
        if(a[lpos] <= a[rpos]){
            t[tmp_pos++] = a[lpos++];
        }else{
            t[tmp_pos++] = a[rpos++];
        }
    }
    /* Copy rest of first half */
    while(lpos <= left_end){
        t[tmp_pos++] = a[lpos++];
    }
    /* Copy rest of second half */
    while(rpos <= right_end){
        t[tmp_pos++] = a[rpos++];
    }

    /* Copy t back */
    for(i = 0; i < num_elements; i++, right_end--){
        a[right_end] = t[right_end];
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

void merge_sort(int *a, int n)
{
    int *t = malloc(n * sizeof(int));

    if(t != NULL){
        msort(a, t, 0, n-1);
        free(t);
    }else{
        printf("No space for tmp array!");
    }
}

void show(int *a, int len)
{
    int i;
    printf("array = ");
    for(i=0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    time_t start = time(NULL);
    for(i=0; i<1000; i++){
        int *a = rlist(0, 1000, 5000000);
        merge_sort(a, 1000);
        free(a);
    }
    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);
    return 0;
}
