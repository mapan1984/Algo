#ifndef __HEAP_H_
#define __HEAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int length;
    int heap_size;
    int *base;
} heap;

void initheap(heap *h, int length);
void swap(heap *h, int l, int r);
void siftup(heap *h);
void siftdown(heap *h, int i);
void build_min_heap(heap *h);
void insert(heap *h, int t);
int extractmin(heap *h);

#endif
