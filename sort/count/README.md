### 计数排序

计数排序假设n个输入元素中的每一个都是在0到k区间内的一个整数，其中k为某个整数。当k=O(n)时，排序的运行时间为θ(n)。

假设输入是是个数组A[1..n]，A.length=n。R[1..n]存放排序的输出，C[0..k]提高临时存储空间(存储计数)。

```
counting_sort(A, R, k)
    for i = 0 to k  // 清零临时存储空间C[0..k]
        C[i] = 0

    for j = 1 to A.length
        C[A[j]] = C[A[j]] + 1

    // C[i] now contains the number of elements equal to i

    for i = 1 to k
        C[i] = C[i] + C[i-1]

    // C[i] now contains the number of elements less than or equal to i

    for j = A.length downto 1
        R[C[A[j]]] = A[j]
        C[A[j]] = C[A[j]] - 1
```

时间复杂度T(n) = θ(k) + θ(n) + θ(k) + θ(n) = θ(k+n)，在实际工作中，当k = O(n)时，我们一般会采用计数排序，这是的运行时间为θ(n)。

计数排序是稳定的，具有相同的元素在输出数组中的相对次序与他们在输入数组中的相对次序相同。
