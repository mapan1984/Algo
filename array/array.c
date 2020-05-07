#include "array.h"

int init_array(Array *a)
{
    a->base = (int*)malloc(sizeof(int)*10);
    if (a->base == NULL) {
        return -1;
    }
    a->len = ARINIT;
    a->top = 0;
    return 1;
}


/*
 * 操作：
 *      a[top] = n
 *      top++
 * 成功则返回新增元素下标，失败返回-1
 */
int array_append(Array *a, int n)
{
    if (a->base == NULL) {  // first time
        int ok = init_array(a);
        if (ok == -1) {
            return -1;
        }
    } else if (a->top >= a->len) {  // grow
        int *tmpb = (int *)realloc(a->base,
                            (ARGROW * a->len) * sizeof(int));
        if(tmpb == NULL){
            return -1;
        }
        a->len *= ARGROW;
        a->base = tmpb;
    }
    a->base[a->top] = n;
    return (a->top)++;
}

/*
 * 删除数组中第一个和n相同的数
 */
int array_remove(Array *a, int n)
{
    int i;
    for (i = 0; i < a->top; i++) {
        if (a->base[i] == n) {
            memmove(a->base+i, a->base+i+1,
                    (a->top-(i+1) * sizeof(int)));
            a->top--;
            return 1;
        }
    }
    return 0;
}

