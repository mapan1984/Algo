#include "binary_search.h"

// binary search for target in array, return index
int binary_search(int *array, int target, int len)
{
    int low = 0;
    int high = len -1;
    while (low <= high) {
        int mid = (low+high) / 2;
        if (target < array[mid]) {
            high = mid - 1;
        } else if (target > array[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

