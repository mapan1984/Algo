#include "heap.h"

void swap(int *m, int *n)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;
}

void init_heap(Heap *h, int len, int *array)
{
    h->length = len;
    h->heap_size = 0;
    h->base = (int *)malloc(sizeof(int) * (len+1)); // 下标从1开始
    if(array == NULL){
        return;
    }else{
        int i;
        for(i=1; i<=len; i++){
            h->base[i] = array[i-1];
        }
    }
}

void show_heap(Heap *h)
{
    int heap_size = h->heap_size;
    int len = h->length;
    int i;
    printf("[");
    for(i=1; i<=heap_size; i++){
        printf("%d ", h->base[i]);
    }
    printf("]\n");
    printf("(not in heap--> ");
    for(i; i<=len; i++){
        printf("%d ", h->base[i]);
    }
    printf(")\n\n");
}

/*
 * LEFT(i) is minor top heap
 * RIGHT(i) is minor top heap
 * shift down h->base[i] to let h->base[i] is minor top heap
 * O(lgn)
 */
void min_heapify(Heap *h, int i)
{
    int heap_size = h->heap_size;
    int *base = h->base;
    int c;
    for(;;){
        /* invariant: heap(1, n) except perhaps
                      i and its (0, 1 or 2) children */
        c = 2 * i;
        if(c > heap_size){ // i is a leaf
            break;
        }
        // c is the left child of i
        if(c+1 <= heap_size){ 
            // c+1 is the right child of i
            if(base[c+1] < base[c]){
                c++;
            }
        }
        /* c is the lesser child of i */
        if(base[i] <= base[c]){ // heap(1, n)
            break;
        }
        swap(base+c, base+i);
        i = c;
    }
}

void build_min_heap(Heap *h)
{
    h->heap_size = h->length;
    int i;
    for(i = h->length/2; i >= 1; i--){
        min_heapify(h, i);
    }
}

/*
 * LEFT(i) is heap
 * RIGHT(i) is heap
 * shift down h->base[i] let h->base[i] is heap
 * O(lgn)
 */
void max_heapify(Heap *h, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int heap_size = h->heap_size;
    int *base = h->base;
    int largest;
    if(l <= heap_size && base[l] > base[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= heap_size && base[r] > base[largest]){
        largest = r;
    }
    if(largest != i){
        swap(base + i, base + largest);
        max_heapify(h, largest);
    }
}

/*
 * O(n)
 */
void build_max_heap(Heap *h)
{
    h->heap_size = h->length;
    int i;
    for(i = h->length/2; i >= 1; i--){
        max_heapify(h, i);
    }
}
