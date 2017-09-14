### 顺序统计树

在O(lgn)时间内确定任何的顺序统计量。在O(lgn)时间内计算一个元素的**秩**，即它在集合线性序中的位置。

顺序统计树T只是简单地在每个结点上存储附加信息的一棵红黑树，在红黑树的结点x中，除了通常属性x.key, x.color, x.p, x.left和x.right之外，还包括另一个属性x.size，这个属性包含了已x为根的子树（包括x本身）的（内）结点数，即这棵子树的大小。

如果定义哨兵的大小为0，也就是设置`T.nil.size`为0，则有等式`x.size = x.left.size + x.right.size + 1`。

因为在树中可以有相同关键字的结点，重新定义一个原始的秩为中序遍历树时输出的位置。

### 顺序统计查询

返回已`x`为根的子树中包含第`i`小关键字的结点。

```
os_select(x, i)
    r = x.left.size + 1  // r为x的秩
    if i == r
        return x
    elseif i < r
        return os_select(x.left, i)
    else
        return os_select(x.right, i-r)
```

时间复杂度T(n) = O(lgn)

### 确定一个元素的秩

给定指向顺序统计树T中结点x的指针，过程`os_rank`返回对T中序遍历对应的线性序中x的位置。

```
os_rank(T, x)
    r = x.left.size + 1
    y = x
    while y ≠ T.root
        if y == y.p.right
            r = r + y.p.left.size + 1
        y = y.p
    return r
```

时间复杂度T(n) = O(lgn)

### 对子树规模的维护

