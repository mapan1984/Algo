#ifndef HEAP_H_
#define HEAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PARENT(i) ((i)>>1)
#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1) + 1)

typedef struct {
    int length;
    int heap_size;
    int *base;
} Heap;

// 基本操作
void swap(int *m, int *n);
void init_heap(Heap *h, int len, int *array);
void destroy_heap(Heap *h);
void show_heap(Heap *h);
void max_heapify(Heap *h, int i);
void min_heapify(Heap *h, int i);
void build_max_heap(Heap *h);
void build_min_heap(Heap *h);


#endif
