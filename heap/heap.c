#include "heap.h"

void initheap(heap *h, int length)
{
    h->length = length;
    h->base = malloc((length+1) * sizeof(int)); // don't use x[0]
    h->heap_size = 0;
}

void swap(heap *h, int i, int j)
{
    int tmp = h->base[i];
    h->base[i] = h->base[j];
    h->base[j] = tmp;
}

void siftup(heap *h)
{
    int i = h->heap_size;
    int p;
    for(;;){
        /* invariant: heap(1, n) except perhaps
                      between i and its parent */
        if(i == 1){ 
            /* i is root of heap */
            break;
        }
        p = i / 2;
        if(h->base[p] <= h->base[i]){
            /* heap(1, n) */
            break;
        }
        swap(h, p, i);
        i = p;
    }
}

void siftdown(heap *h, int i)
{
    int n = h->heap_size;
    int c;
    for(;;){
        /* invariant: heap(1, n) except perhaps
                      i and its (0, 1 or 2) children */
        c = 2 * i;
        if(c > n){ // i is a leaf
            break;
        }else{ // c is the left child of i
            if(c+1 <= n){ // c+1 is the right child of i
                if(h->base[c+1] < h->base[c])
                    c++;
            }
            /* c is the lesser child of i */
            if(h->base[i] <= h->base[c]){
                /* heap(1, n) */
                break;
            }
            swap(h, c, i);
            i = c;
        }
    }
}

void build_min_heap(heap *h)
{
    int i = h->length / 2 + 1;
    for(; i > 0; i--){
        siftdown(h, i);
    }
}

void insert(heap *h, int t)
{
    if(h->heap_size >= h->length){
        printf("error");
    }
    h->heap_size++;
    h->base[h->heap_size] = t;
    /* heap(1, heap_size-1) */
    siftup(h);
    /* heap(1, heap_size) */
}

int extractmin(heap *h)
{
    if(h->heap_size < 1){
        printf("error");
    }
    int t = h->base[1];
    h->base[1] = h->base[h->heap_size--];
    /* heap(2, n) */
    siftdown(h, 1);
    /* heap(1, n) */
    return t;
}
