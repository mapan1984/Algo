#ifndef __HEAP_H_
#define __HEAP_H_

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
} heap;

#define PARENT(i) ((i)/2)
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i) + 1)

void swap(int *m, int *n);
void init_heap(heap *h, int len, int *array);
void show_heap(heap *h);
void max_heapify(heap *h, int i);
void min_heapify(heap *h, int i);
void build_max_heap(heap *h);
void build_min_heap(heap *h);
void max_heap_sort(heap *h);
void min_heap_sort(heap *h);
int heap_max_num(heap *h);
int heap_min_num(heap *h);
int heap_extract_max(heap *h);
int heap_extract_min(heap *h);
void heap_increase_key(heap *h, int index, int key);
void heap_decrease_key(heap *h, int index, int key);
void max_heap_insert(heap *h, int key);
void min_heap_insert(heap *h, int key);

#endif
