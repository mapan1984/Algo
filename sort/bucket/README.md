### 桶排序

假设输入是一个包含n个元素的数组A，且每个元素A[i]满足0 ≤ A[i] ˂ 1，此外，临时数组B[0..n-1]来存放链表(即桶)。

```
bucket_sort(A)
    n = A.length

    let B[0..n-1] be a new array

    for i = 0 to n-1
        make B[i] an empty list

    for i = 1 to n
        insert A[i] into list B[⌊nA[i]⌋]

    for i = 0 to n-1
        sort list B[i] with insertion sort

    concatenate the list B[0], B[1],...,B[n-1] together in order
```

桶排序假设输入数据服从均匀分布，平均情况下它的时间代价为O(n)。
