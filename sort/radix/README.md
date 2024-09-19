假设n个d位的元素存放在数组A中，其中1位是最低位，第d位是最高位。

```
radix_sort(A, d)
    for i = 1 to d
        use a stable sort to sort array A on digit i
```

给定n个d位数，其中每一个数位有k个可能的取值。如果radix_sort使用的稳定排序方法耗时θ(n+k)，那么它就可以在θ(d(n+k))时间内将这些数排好序。
