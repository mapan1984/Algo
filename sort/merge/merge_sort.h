#ifndef __MERGE_SORT_H_
#define __MERGE_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int t[], int lpos, int rpos, int rend);
void msort(int a[], int t[], int left, int right);
void merge_sort(int *a, int left, int right);

#endif
