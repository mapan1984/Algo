#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/* 返回随机序数组 */
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
    for(i=0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
l         u
5 2 1 6 4 7
m i
5 2 1 6 4 7
  m i
5 2 1 6 4 7
    m i
5 2 1 6 4 7
    m   i
5 2 1 4 6 7
      m   i
5 2 1 4 6 7
      m   i
4 2 1 5 6 7
      m   i
*/


/*
 * for each (unsorted) partition
 *     set first element as pivot
 *     storeIndex = pivoIndex + 1
 *     
 *     for i = pivotIndex + 1 to rightmostIndex
 *         if element[i] < element[pivot]
 *             storeIndex++
 *             swap(i, storeIndex);
 *     swap(pivot, storeIndex)
 */

/* qsort1 单向划分 */
void qsort1(int *a, int l, int u)
{
    if(l >= u){
        return;
    }
    int m = l;
    int i;
    for(i=l+1; i <= u; i++){

        /* invariant: a[l+1...m] < a[l] <= a[m+1...i-1] */

        if(a[i] < a[l]){
            m++;
            swap(a+m, a+i);
        }
    }
    swap(a+l, a+m);

    /* a[l...m-1] < a[m] <= a[m+1...u] */

    qsort1(a, l, m-1);
    qsort1(a, m+1, u);
}

/* 
 * qsort3 双向划分 
 * 解决所有排序元素相同是复杂度为nlog2n的问题
 */
void qsort3(int *a, int l, int u)
{
    if(l >= u){
        return;
    }
    int t = a[l];
    int i = l;
    int j = u+1;
    for(;;){
        do{
            i++;
        }while(i <= u && a[i] < t);
        do{
            j--;
        }while(a[j] > t);
        if(i > j){
            break;
        }
        swap(a+i, a+j);
    }
    swap(a+l, a+j);
    qsort3(a, l, j-1);
    qsort3(a, j+1, u);
}

/* 
 * qsort4 双向划分，选择随机划分元素
 * 对任意输入的n元数组，期望运行时间正比与nlogn
 */
void qsort4(int *a, int l, int u)
{
    if(l >= u){
        return;
    }
    swap(a+l, a+rand()%(u-l+1)+l);
    int t = a[l];
    int i = l;
    int j = u+1;
    for(;;){
        do{
            i++;
        }while(i <= u && a[i] < t);
        do{
            j--;
        }while(a[j] > t);
        if(i > j){
            break;
        }
        swap(a+i, a+j);
    }
    swap(a+l, a+j);
    qsort4(a, l, j-1);
    qsort4(a, j+1, u);
}

int main()
{
    time_t start = time(NULL);

    int i;
    for(i=0; i<1000; i++){
        int *a = rlist(0, 1000, 5000000);
        qsort4(a, 0, 1000);
        free(a);
    }

    double space = difftime(time(NULL), start);
    printf("time = %f ms", space*0.001);

    return 0;
}
