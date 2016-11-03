#include "heap.h"

int heap_max_num(heap *h)
{
    return h->base[1];
}

int heap_extract_max(heap *h)
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

void heap_increase_key(heap *h, int index, int key)
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

void max_heap_insert(heap *h, int key)
{
    h->heap_size++;
    if(h->heap_size > h->length){
        h->length += INC;
        h->base = (int *)realloc(h->base, sizeof(int)*h->length);
    }
    h->base[h->heap_size] = key;
    int index = h->heap_size;
    while(index > 1 && h->base[PARENT(index)] < h->base[index]){
        swap(h->base + PARENT(index), h->base + index);
        index = PARENT(index);
    }
}

int heap_min_num(heap *h)
{
    return h->base[1];
}

int heap_extract_min(heap *h)
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

void heap_decrease_key(heap *h, int index, int key)
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

void min_heap_insert(heap *h, int key)
{
    h->heap_size++;
    if(h->heap_size > h->length){
        h->length += INC;
        h->base = (int *)realloc(h->base, sizeof(int)*h->length);
    }
    h->base[h->heap_size] = key;
    int index = h->heap_size;
    while(index > 1 && h->base[PARENT(index)] > h->base[index]){
        swap(h->base + PARENT(index), h->base + index);
        index = PARENT(index);
    }
}
