void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

/* 单向划分 */
int partition_one_way(int *a, int l, int u) {
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

    return m;
}

/*
 * 双向划分
 * 解决所有排序元素相同时复杂度为 nlog2n 的问题
 */
int partition_two_way(int *a, int l, int u) {
    int t = a[l];
    int i = l;
    int j = u + 1;
    for (;;) {
        do {
            i++;
        } while (i <= u && a[i] < t);
        do {
            j--;
        } while (a[j] > t);
        if (i > j) {
            break;
        }
        swap(a+i, a+j);
    }
    swap(a+l, a+j);
    return j;
}

/*
 * 双向划分，并且选择随机划分元素
 * 对任意输入的n元数组，期望运行时间正比与nlogn
 */
int partition(int *a, int l, int u) {
    swap(a + l, a + rand() % (u - l + 1 ) + l);
    int t = a[l];
    int i = l;
    int j = u + 1;
    for (;;) {
        do {
            i++;
        } while (i <= u && a[i] < t);
        do {
            j--;
        } while (a[j] > t);
        if (i > j) {
            break;
        }
        swap(a + i, a + j);
    }
    swap(a + l, a + j);
    return j;
}


void quick_sort(int *a, int l, int u)
{
    if (l >= u) {
        return;
    }

    int j = partition(a, l, u);

    quick_sort(a, l, j-1);
    quick_sort(a, j+1, u);
}

