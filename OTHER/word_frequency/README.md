### 词频统计

输入一组词，统计词频，以word : count给出结果

### C++

C++使用了表中模板库的map。

*C++中map的实现使用平衡搜索树*

### C

C使用散列表维护结果

    bin
    [/]   word|count|next
    [1]-->[the|  1  |next]-->[in|2|NULL]
    [2]
    ...

假设待统计的词有29131个，使用于29131最接近的质数29989最为散列表大小，将乘数定义为31

### AWK

执行：

    awk -f word_count.awk
