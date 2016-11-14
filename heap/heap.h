#ifndef HEAP_H_
#define HEAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define INC 10

typedef struct {
    int length;
    int heap_size;
    int *base;
} Heap;

#define PARENT(i) ((i)>>1)
#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1) + 1)

void swap(int *m, int *n);
void init_heap(Heap *h, int len, int *array);
void show_heap(Heap *h);
void max_heapify(Heap *h, int i);
void min_heapify(Heap *h, int i);
void build_max_heap(Heap *h);
void build_min_heap(Heap *h);
void max_heap_sort(Heap *h);
void min_heap_sort(Heap *h);
int heap_max_num(Heap *h);
int heap_min_num(Heap *h);
int heap_extract_max(Heap *h);
int heap_extract_min(Heap *h);
void heap_increase_key(Heap *h, int index, int key);
void heap_decrease_key(Heap *h, int index, int key);
int max_heap_insert(Heap *h, int key);
int min_heap_insert(Heap *h, int key);

#endif
