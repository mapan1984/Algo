#include "heap.h"

void swap(int *m, int *n)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;
}

// 初始化length=len的堆，heap_size=0
// 如果提供初始数组，则以初始数组中的值代替堆中原先混乱的值
void init_heap(Heap *h, int len, int *array)
{
    h->length = len;
    h->heap_size = 0;
    h->base = (int *)malloc(sizeof(int) * (len+1)); // 下标从1开始
    if (array != NULL) {
        int i;
        for(i=1; i<=len; i++){
            h->base[i] = array[i-1];
        }
    }
}

void destroy_heap(Heap *h)
{
    free(h->base);
    free(h);
}

void show_heap(Heap *h)
{
    int i;
    int length = h->length;
    int heap_size = h->heap_size;
    printf("[");
    for (i=1; i<=heap_size; i++) {
        printf("%d ", h->base[i]);
    }
    printf("]\n");
    printf("(not in heap--> ");
    for (; i<=length; i++) {
        printf("%d ", h->base[i]);
    }
    printf(")\n\n");
}

/*
 * LEFT(i) is minor top heap
 * RIGHT(i) is minor top heap
 * shift down h->base[i] to let h->base[i] is minor top heap
 */
void min_heapify(Heap *h, int i)
{
    int c;
    int *base = h->base;
    int heap_size = h->heap_size;
    for (;;) {
        /* invariant: heap(1, n) except perhaps
                      i and its (0, 1 or 2) children */
        c = 2 * i;
        if (c > heap_size) { // i is a leaf
            break;
        }
        // c is the left child of i
        if (c+1 <= heap_size) {
            // c+1 is the right child of i
            if (base[c+1] < base[c]) {
                c++;
            }
        }
        /* c is the lesser child of i */
        if (base[i] <= base[c]) { // heap(1, n)
            break;
        }
        swap(base+c, base+i);
        i = c;
    }
}

// 由底向上的构建最小堆
void build_min_heap(Heap *h)
{
    h->heap_size = h->length;  // 必须在第一步完成，min_heapify中需要准确的heap_size
    int i;
    for (i = h->length/2; i >= 1; i--) {
        min_heapify(h, i);
    }
}

/*
 * LEFT(i) is heap
 * RIGHT(i) is heap
 * shift down h->base[i] let h->base[i] is heap
 */
void max_heapify(Heap *h, int i)
{
    int *base = h->base;
    int heap_size = h->heap_size;

    // 寻找i，LEFT(i), RIGHT(i)中有最大值的下标
    int largest;
    int l = LEFT(i);
    int r = RIGHT(i);
    if (l <= heap_size && base[l] > base[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= heap_size && base[r] > base[largest]) {
        largest = r;
    }

    // largest是最大值的下标
    if (largest != i) {
        swap(base + i, base + largest);
        max_heapify(h, largest);
    }
}

// 由底向上的构建最小堆
void build_max_heap(Heap *h)
{
    h->heap_size = h->length;
    int i;
    for (i = h->length/2; i >= 1; i--) {
        max_heapify(h, i);
    }
}
