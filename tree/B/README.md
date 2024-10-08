### B树

一棵 B 树（B 即 Balanced，平衡的意思）是具有以下性质的有根树（根为 T.root）：

1. 每个结点 x 有下面属性：
    * x.n，当前存储在结点x中的关键字个数。
    * x.n 个关键字本身\\( x.key_1, x.key_2, ···, x.key_{x.n} \\)，以非降序存放，使得\\( x.key_1 ≤ x.key_2 ≤ ··· ≤ x.key_{x.n} \\)。
    * x.leaf，一个布尔值，为 TRUE 代表 x 是叶结点；FALSE 代表 x 为内部结点。
2. 每个内部节点 x 还包含 x.n + 1 个指向其孩子的指针\\( x.c_1, x.c_2, ···, x.c_{x.n+1} \\)。叶结点没有孩子，所以它们的\\( c_i \\)属性没有定义。
3. 关键字\\( x.key \\)对存储在各子树中的关键字范围加以分割：如果\\( k_i \\)为任意一个存储在以\\( x.c_i \\)为根的子树中的关键字，那么\\( k_1 ≤ x.key_1 ≤ k_2 ≤ x.key_2 ≤ ··· ≤ x.key_{x.n} ≤ k_{x.n+1} \\)。
4. 每个叶结点具有相同的深度，即树的高度 h。
5. 每个结点所包含的关键字个数有上界和下界。用一个被称为 B 树的**最小度**的固定整数t ≥ 2来表示这些界：
    * 除了根结点以外的每个结点必须至少有 t - 1 个关键字。因此，除了根结点以外的每个内部结点至少有 t 个孩子。如果树非空，根结点至少有一个关键字。
    * 每个结点至多可包含 2t - 1 个关键字。因此，一个内部结点至多可有 2t 个孩子。当一个结点恰好有 2t - 1 个关键字时，称该结点是满的。

B 树相比与 binary search 树，其不同点在于：

1. 树节点可以容纳多个值以及多个指向子节点的指针
2. 插入新值之后执行自平衡算法，保证树始终是平衡的

因此在存储相同多的数据的情况下，B 树可以有效降低树的高度，并且更容易利用磁盘顺序访问。
