### 归并排序

归并排序算法遵循分治模式：

1. 分解：分解待排序的n个元素的序列成各具n/2个元素的两个子序列
2. 解决：使用归并排序递归地排序两个子序列
3. 合并：合并两个已排序的子序列已产生已排序的答案

### MERGE

MERGE的输入为A, p, q, r，其中A是一个数组，p, q和r是数组的下标，满足`p ≤ q < r`。该过程假设子数组`A[p..q]`和`A[q+1..r]`都已排好序，它合并这两个子数组形成单一的拍好序的子数组并代替当前的子数组`A[p..r]`。MERGE需要θ(n)的时间，其中`n=r-p+1`是待合并元素的总数。

```
MERGE(A, p, q, r)
    n1 = q - p + 1
    n2 = r - q
    let L[1..n1+1] and R[1..n2+1] be new arrays
    for i = 1 to n1
        L[i] = A[p+i-1]
    for j = 1 to n2
        R[j] = A[q+j]
    L[n1+1] = ∞
    R[n2+1] = ∞
    i, j = 1, 1
    for k = p to r
        if L[i] ≤ R[j]
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
```

### MERGE-SORT

```
MERGE-SORT(A, p, r)
    if p < r
        q = ⌊(p+r)/2⌋
        MERGE-SORT(A, p, q)
        MERGE-SORT(A, q+1, r)
        MERGE(A, p, q, r)
```
