```
randomized_select(A, p, r, i)
    if p == r
        return A[p]

    q = partition(A, p, r)
    k = q-p+1
    if i == k  // the pivot value is the answer
        return A[q]
    elseif i < k
        return randomized_select(A, p, q-1, i)
    else
        return randomized_select(A, q+1, r, i-k)
```

O(n)
