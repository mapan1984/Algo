#include "heap.h"

int heap_max_num(Heap *h)
{
    return h->base[1];
}

int heap_extract_max(Heap *h)
{
    if(h->heap_size < 1){
        printf("heap underflow");
        exit(1);
    }

    int max = h->base[1];
    h->base[1] = h->base[h->heap_size];
    h->heap_size--;
    max_heapify(h, 1);
    return max;
}

void heap_increase_key(Heap *h, int index, int key)
{
    int *base = h->base;
    if(key < base[index]){
       printf("new key is smaller than current key"); 
       return;
    }
    base[index] = key;
    while(index > 1 && base[PARENT(index)] < base[index]){
        swap(base+PARENT(index), base+index);
        index = PARENT(index);
    }
}

int max_heap_insert(Heap *h, int key)
{
    h->heap_size++;
    if(h->heap_size > h->length){
        int *hb;
        hb = (int *)realloc(h->base, sizeof(int)*h->length+INC);
        if(hb == NULL){
            return -1;
        }
        h->base = hb;
        h->length += INC;
    }
    h->base[h->heap_size] = key;
    int index = h->heap_size;
    while(index > 1 && h->base[PARENT(index)] < h->base[index]){
        swap(h->base + PARENT(index), h->base + index);
        index = PARENT(index);
    }
    return index;
}

int heap_min_num(Heap *h)
{
    return h->base[1];
}

int heap_extract_min(Heap *h)
{
    if(h->heap_size < 1){
        printf("heap underflow");
        exit(1);
    }

    int min = h->base[1];
    h->base[1] = h->base[h->heap_size];
    h->heap_size--;
    min_heapify(h, 1);
    return min;
}

void heap_decrease_key(Heap *h, int index, int key)
{
    int *base = h->base;
    if(key > base[index]){
        printf("new key is lager than current key");
        return;
    }
    base[index] = key;
    while(index > 1 && base[PARENT(index)] > base[index]){
        swap(base+PARENT(index), base+index);
        index = PARENT(index);
    }
}

int min_heap_insert(Heap *h, int key)
{
    h->heap_size++;
    if(h->heap_size > h->length){
        int *hb;
        hb = (int *)realloc(h->base, sizeof(int)*(h->length+INC));
        if(hb == NULL){
            return -1;
        }
        h->base = hb;
        h->length += INC;
    }
    h->base[h->heap_size] = key;
    int index = h->heap_size;
    while(index > 1 && h->base[PARENT(index)] > h->base[index]){
        swap(h->base + PARENT(index), h->base + index);
        index = PARENT(index);
    }
    return index;
}
