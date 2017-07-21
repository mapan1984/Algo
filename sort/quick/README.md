### 快速排序

1. **分解**：数组A[p..r]被划分为两个(可能为空)子数组A[p..q-1]和A[q+1..r]，使得A[p..q-1]中的每一个元素都小于等于A[q]，而A[q]也小于等于A[q+1..r]中的每个元素。其中，计算下标q也是划分过程的一部分。
2. **解决**：通过递归调用快速排序，对子数组A[p..q-1]和A[q+1..r]进行排序。
3. **合并**：因为子数组都是原址排序，所以不需要合并操作：数组A[p..r]已经有序。

```
quicksort(A, p, r)
    if p < r
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)

partition(A, p, r)
    x = A[r]
    i = p-1
    for j = p to r-1
        if A[j] ≤ x
            i = i + 1
            exchange A[i] with A[j]
    exchange A[i+1] with A[r]
    return i+1
```

`partition`函数是可以选择多种，上列展示的单向划分，还可以多向划分，随机选择枢纽元素等。
