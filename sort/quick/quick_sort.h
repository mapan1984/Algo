#ifndef __QUICK_SORT_H_
#define __QUICK_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../array.h"

void swap(int *x, int *y);
int partition_one_way(int *a, int l, int u);
int partition_two_way(int *a, int l, int u);
int partition(int *a, int l, int u);
void quick_sort(int *a, int l, int u);

#endif
