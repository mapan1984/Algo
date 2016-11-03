#!/usr/bin/env python3
# encoding: utf-8

"""
   0 1 2 3 4 5 6 7 8 col
 0
 1
 2
 3
 4
 5
 6
 7
 8

 row
"""
import time

n = 5         # 棋盘大小
sol = [0]*n   # 已放置皇后的列号 sol[row] = col
count = 0     # 解法总数


def dfs(row):
    """递归函数，试探row行皇后可以放置的列的位置"""
    global count
    for col in range(n):   # 依次试探每一列
        ok = True
        for i in range(row):   # <row, col>
            if col == sol[i] or col - sol[i] == row - i \
                             or col - sol[i] == i -row:
                ok = False     # <row, col> 与 <i, sol[i]> 冲突
                break
               
        if not ok:
            continue

        if row == n - 1:
            count += 1
            print(sol)
        else:
            sol[row] = col
            dfs(row + 1)

st = time.time()
dfs(0)
et = time.time()

print("Total solutions: %d" % count)
print("Elapsed time: %f seconds" % (et-st))
