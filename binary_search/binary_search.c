#include "binary_search.h"

// binary search for target in array, return index
int binary_search(int *array, int target, int len)
{
    int low = 0;
    int high = len -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target < array[mid]){
            high = mid - 1;
        }else if(target > array[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int get_target()
{
    int target;
    printf("input target: ");
    scanf("%d", &target);
    return target;
}

int main()
{
    Array a;
    init_array(&a);
    getnum("bs-1.txt", &a);
    int target = get_target();
    int m = binary_search(a.base, target, a.top);
    printf("%d", m);
    return 0;
}
