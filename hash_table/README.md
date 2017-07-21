## 散列表

在最坏情况下，从散列表中查找一个元素的时间为θ(n)，然而在一些合理的假设下，在散列表中查找一个元素的平均时间为O(1)。

假设散列表为T[0..m-1]，具有关键字key的元素x被存放在表的T[hash(key)]中。如果两个关键字映射到一个槽中(发生冲突)，我们需要解决冲突。

## 散列函数

一个好的散列函数应(近似的)满足简单均匀散列假设：每个关键字都被等可能地散列到m个槽位中的任何一个，并与其他关键字已散列到哪个槽位无关。

### 除法散列法

通过取k除以m的余数，将关键字k映射到m个槽中的某一个上，即散列函数为：

    h(k) = k mod m

m的选取：一个不太接近2的整数幂的素数

### 乘法散列法

分为两步：
1. 用关键字k乘上常数A(0 ˂ A ˂ 1)，并提取kA的小数部分
2. 用m乘以这个值，在向下取整

散列函数为：

    h(k) = ⌊m(kA mod l)⌋

这里`kA mod l`是取kA的小数部分，即`kA - ⌊kA⌋`

### 全域散列法

## 解决冲突

### 链接法

链接法中，把散列到同一个槽中的所有元素都放在一个表中。

```
insert(T, x)
    insert x at the head of list T[h(x.key)]

search(T, k)
    search for an element with key k in list T[h(k)]

delete(T, x)
    delete x from the list T[h(x.key)]
```

### 开放寻址法

    h: U X {0, 1, ···， m-1} → {0, 1, ···, m-1}

```
insert(T, x)
    i = 0
    repeat
        j = h(x.key, i)
        if T[j] == NIL
            T[j] = x
            return j
        else
            i = i + 1
    until i == m
    error "hash table overflow"
```

```
search(T, k)
    i = 0
    repeat
        j = h(k, i)
        if T[j].key == k
            return T[j]
        i = i + 1
    until T[j] == NIL or i == m
    return NIL
```

