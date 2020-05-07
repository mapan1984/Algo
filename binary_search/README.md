### 算法描述

二分搜索算法在排好序的数组a[0..n-1]中寻找目标元素t，返回目标元素位置p(以0为首位置)。当p=-1时，目标t不在数组a[0..n-1]中；否则0≤p≤n-1)，且t=a[p]。

二分搜索通过不断缩小包含元素t的范围来解决问题，一开始，范围是整个数组，然后通过将t与数组的中间项进行比较并抛弃一半的范围来缩小范围。该过程持续进行，直到在数组中找到t或确定包含t的范围为空时为止。

算法框架如下：

``` c
int binary_search(int *array, int target, int len)
{
    int low = 0;
    int high = len -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target < array[mid]){
            high = mid - 1;
        }else if(target > array[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}
```

### 算法分析

对于二分查找，设初始问题规模为N，每次循环问题规模减为N/2，每次循环需进行一次判断和一次计算，复杂度为θ(1)；当N=1时，T(N)=1。

    T(N)=T(N/2)+θ(1)
    T(1)=θ(1)

运用迭代法展开：

    T(N)=T(N/2)+θ(1)
        =T(N/4)+2θ(1)
        =T(N/2^3  )+3θ(1)
        ……
        =T(N/2^K  )+Kθ(1)

当N=2^K时，可到达边界条件T(1)=θ(1)，此时K=log⁡N，所以时间复杂度T(N)=O(logN)。
