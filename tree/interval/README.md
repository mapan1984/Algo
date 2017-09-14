### 区间树

把一个[t1, t2]表示成一个对象a，其中属性a.low = t1为低端点，属性a.high为高端点。任何两个区间a和b必属于下列三者之一：
1. a和b重叠(a.low ≤ b.high 且 b.low ≤ a.high)
2. a在b的左边(a.high ˂ b.low)
3. a在b的右边(b.high ˂ a.low)
