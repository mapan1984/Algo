## 哈夫曼树

最优编码方案对应一棵满(full)二叉树，即每个非叶结点都有两个孩子结点。若C为字母表且所有字符的出现频率均为正数，则最优前缀码对应的树恰由|C|个叶结点，每个叶结点对应字母表中一个字符，且恰有|C|-1个内部结点。


假设有字符以及出现频率：

| 字符 | 频率 | 前缀编码 |
|------|------|----------|
| A    | 4    | 0        |
| B    | 2    | 10       |
| C    | 1    | 110      |
| D    | 1    | 111      |

         +
       0/ \1
       A   +
         0/ \1
         B   +
           0/ \1
           C   D

## 构造哈夫曼编码

C是一个n个字符的集合，其中每个字符c∈C都是一个对象，其属性c.freq给出了字符的出现频率。

```
huffman(C)
    n = |C|
    Q = prequeue(C)  // Q包含C中元素的最小队列
    for i = 1 to n-1
        allocate a new node z
        z.left = x = extract_min(Q)
        z.right = y = extract_min(Q)
        z.freq = x.freq + y.freq
        insert(Q, z)
    return extract_min(Q)
```

