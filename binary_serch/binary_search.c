#include "binary_search.h"

int binary_search(int *a, int target, int len)
{
    int l = 0;
    int u = len -1;
    while(l <= u){
        int m = (l+u)/2;
        if(target < a[m]){
            u = m - 1;
        }else if(target > a[m]){
            l = m + 1;
        }else{
            return m;
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
    array a;
    init_array(&a);
    getnum("bs-1.txt", &a);
    int target = get_target();
    int m = binary_search(a.base, target, a.top);
    printf("%d", m);
    return 0;
}
