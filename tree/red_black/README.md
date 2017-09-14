### 红黑树

红黑树是许多“平衡”搜索树中的一种，可以保证在最坏情况下基本动态集合操作的时间复杂度为O(lgn)。

一棵红黑树是满足以下**红黑性质**的[二叉搜索树](https://github.com/mapan1984/Toys/tree/master/tree/binary_search)：
1. 每个结点或是红色的，或是黑色的。
2. 根结点是黑色的。
3. 每个叶结点(NIL)是黑色的。
4. 如果一个结点是红色的，则它的两个子结点都是黑色的。
5. 对每个结点，从该结点到其所有后代结点的简单路径上，均包含相同数目的黑色节点。

从某个结点x出发（不含该结点）到达一个叶结点的任意一条简单路径上的黑色结点个数称为该结点的**黑高**(black-height)，记为bh(x)。

定义红黑树的黑高为其根结点的黑高。

一棵由n个内部结点的红黑树的高度至多为2lg(n+1)。

### 左旋、右旋

左、右旋操作要保持二叉搜索树的性质`α ˂ x.key ˂ β ˂ y.key ˂ γ`。

```
    |                                                |
    y       <==== left_rotate(T, x)  =====           x
   / \                                              / \
  x   γ     ===== right_rotate(T, y) ====>         α   y
 / \                                                  / \
α   β                                                β   γ
```

下面为left_rotate的伪代码，假设`x.right ≠ T.nil`且根结点的父结点为`T.nil`。

```
left_rotate(T, x)
    y = x.right   // set y

    x.right = y.left  // turn y's left subtree into x's right subtree
    if y.left ≠ T.nil
        y.left.p = x

    y.p = x.p  // link x's parent to y
    if x.p == T.nil
        T.root = y
    elseif x == x.p.left
        x.p.left = y
    else
        x.p.right = y

    y.left = x  // put x on y's left
    x.p = y
```

下面为right_rotate的伪代码，假设`y.left ≠ T.nil`且根结点的父结点为`T.nil`。

```
right_rotate(T, y)
    x = y.left   // set x

    y.left = x.right  // turn x's right subtree into y's left subtree
    if x.right ≠ T.nil
        x.right.p = y

    x.p = y.p  // link y's parent to x
    if y.p == T.nil
        T.root = x
    elseif y == y.p.left
        y.p.left = x
    else
        y.p.right = x

    x.right = y  // put y on x's right
    y.p = x
```

### 插入

在O(lgn)时间内完成向一棵含n个结点的红黑树中插入一个新结点，调用`rb_insert`将结点z插入树T内，就好像T是一棵普通的二叉搜索树一样，然后将z着为红色。为保证红黑性质能继续保持，调用一个辅助程序`rb_insert_fixup`来对结点重新着色并旋转。

```
rb_insert(T, z)
    xp = T.nil  // 用于保存x的父节点
    x = T.root
    while x ≠ T.nil
        xp = x
        if z.key < x.key
            x = x.left
        else
            x = x.right

    // 现在x的位置即为插入z的位置

    z.p = xp
    if xp == T.nil
        T.root = z   // tree T was empty
    elseif z.key < xp.key
        xp.left = z
    else
        xp.right = z

    z.left = T.nil
    z.right = T.nil
    z.color = RED
    rb_insert_fixup(T, z)
```

```
rb_insert_fixup(T, z)
    while z.p.color == RED
        if z.p == z.p.p.left
            y = z.p.p.right   // y是z的叔结点
            if y.color == RED  // case 1: z的叔结点y是红色的
                z.p.color = BLACK      // case 1
                y.color = BLACK        // case 1
                z.p.p.color = RED      // case 1
                z = z.p.p              // case 1
            elseif z = z.p.right  // case 2: z的叔结点y是黑色的且z是一个右孩子
                z = z.p                // case 2
                left_rotate(T, z)      // case 2
            z.p.color = BLACK          // case 3: z的叔结点y是黑色的且z是一个左孩子
            z.p.p.color = RED          // case 3
            right_rotate(T, z.p.p)     // case 3
        else(same as then clause with "right" and "left" exchanged)
    T.root.color = BLACK
```

### 删除
