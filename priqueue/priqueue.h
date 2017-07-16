#ifndef PRIQUEUE_H_
#define PRIQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#include "../heap/heap.h"

#define INC 10

int max_heap_insert(Heap *h, int key);
int heap_max_num(Heap *h);
int heap_extract_max(Heap *h);
void heap_increase_key(Heap *h, int index, int key);

int min_heap_insert(Heap *h, int key);
int heap_min_num(Heap *h);
int heap_extract_min(Heap *h);
void heap_decrease_key(Heap *h, int index, int key);

#endif
