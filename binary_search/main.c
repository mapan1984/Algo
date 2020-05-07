#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "read_num.h"
#include "binary_search.h"

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
    getnum("./resources/bs-1.txt", &a);
    int target = get_target();
    int m = binary_search(a.base, target, a.top);
    printf("%d", m);
    return 0;
}
