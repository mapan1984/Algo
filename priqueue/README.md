### 优先队列

优先队列是一种用来维护由一组元素构成的集合S的数据结构，其中每一个元素都有一个相关的值，称为**关键字**(key)。

一个最大优先队列支持以下操作：
1. insert(S, x)：把元素x插入集合S中。这一操作等价与S=S∪{x}
2. maximun(S)：返回S中具有最大关键字的元素
3. extract_max(S)：去掉并返回S中具有最大关键字的元素
4. increase_key（S, x, k)：将元素x的关键字值增加到k，这里假设k的值不小于x的原关键字
