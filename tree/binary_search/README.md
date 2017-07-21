### 二叉搜索树

一棵二叉搜索树是以一颗二叉树来组织的，且对任何结点x，其左子树的关键字最大值不超过x.key，其右子树的关键字的最小值不低于x.key。

二叉搜索树上的基本操作所花费的时间与这棵树的高度成正比。对于有n个结点的一棵完全二叉树来说，这些操作的最坏运行时间为θ(lgn)。

### 遍历

使用**中序遍历**可以按序输出二叉搜索树中的所有关键字。

```
inorder_tree_walk(x)
    if x ≠ NIL
        inorder_tree_walk(x.left)
        print x.key
        inorder_tree_walk(x.right)
```

T(n) = θ(n)

### 查找

递归查找给定关键字的结点，x为树根指针，k为关键字：

```
// 失败返回NIL
search(x, k)
    if x == NIL or k == x.key
        return x

    if k < x.key
        return search(x.left, k)
    else
        return search(x.right, k)
```

迭代查找：

```
// 失败返回NIL
search(x, k)
    while x ≠ NIL and k ≠ x.key
        if k < x.key
            x = x.left
        else
            x = x.right
    return x
```

在高度为h的树中，T(n) = O(n)

### 最小、最大值

```
minimun(x)
    while x.left ≠ NIL
        x = x.left
    return x
```

```
maximun(x)
    while x.right ≠ NIL
        x = x.right
    return x
```

在高度为h的树中，T(n) = O(n)

### 后继和前驱

一个结点x的后继是大于x.key的最小关键字的结点。一棵二叉搜索树的结构允许我们通过没有任何关键字的比较来确定一个结点的后继：
1. 如果结点x的右子树非空，那么x的后继恰是x右子树的最左结点；
2. 如果结点x的右子树为空并有一个后继y，那么y就是x的最底层祖先，并且y的左孩子也是x的一个祖先。

```
// 失败返回NIL
successor(x)
    if x.right ≠ NIL
        return minimun(x.right)

    y = x.p
    while y ≠ NIL and x == y.right
        x = y
        y = y.p
    return y
```

一个结点x的前驱是小于x.key的最大关键字的结点。一棵二叉搜索树的结构允许我们通过没有任何关键字的比较来确定一个结点的前驱：
1. 如果节点x的左子树非空，那么x的前驱恰是x左子树的最右结点；
2. 如果结点x的左子树为空并由一个前驱y，那么y就是x的最底层祖先，并且y的右孩子也是x的一个祖先。

```
// 失败返回NIL
predecessor(x)
    if x.left ≠ NIL
        return maximun(x.left)

    y = x.p
    while y ≠ NIL and x == y.left
        x = y
        y = y.p
    return y
```

在高度为h的树中，T(n) = O(n)

### 插入和删除

```
insert(T, z)
    xp = NIL   // 保存x的父结点
    x = T.root
    while x ≠ NIL
        xp = x
        if z.key < x.key
            x = x.left
        else
            x = x.right

    // 现在x的位置即为插入v的位置

    z.p = xp
    if xp == NIL
        T.root = z  // tree T was empty
    elseif z.key < xp.key
        xp.left = z
    else
        xp.right = z
```

在一棵二叉搜索树T中删除一个结点z分为四种情况：
1. z没有左孩子；用右孩子(可以为NIL)来替换z。
2. z有一个左孩子但没有右孩子；用左孩子来替换z。
3. z有两个孩子，y为z的后继，且y是z的右孩子；用后继y替换z，*y的左孩子为z的左孩子*。
4. z有两个孩子，y为z的后继，y不是z的右孩子；先用y的右孩子替换y，再用y替换z，*y的右孩子为z的右孩子，y的左孩子为z的左孩子*。

```
// 在树T中用结点v来替换结点u
transplant(T, u, v)
    if u.p == NIL  // u is root of T
        T.root = v
    elseif u == u.p.left
        u.p.left = v
    else
        u.p.right = v

    if v ≠ NIL
        v.p = u.p

delete(T, z)
    if z.left == NIL  // z没有左孩子
        transplant(T, z, z.right)
    elseif z.right == NIL  // z有一个左孩子但没有右孩子
        transplant(T, z, z.left)
    else  // z有两个孩子
        y = minimun(z.right)  // y为z的后继
        if y.p ≠ z  // y不是z的右孩子
            transplant(T, y, y.right)
            y.right = z.right
            y.right.p = y
        transplant(T, z, y)  // y为z的右孩子
        y.left = z.left
        y.left.p = y
```

在高度为h的树中，T(n) = O(n)
