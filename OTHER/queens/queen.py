#!/usr/bin/env python3

"""
Solutions of Eight queens chess problem by backtracking
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

count = 0        # 解法总数

def dfs0(row):
    """
    试探row行皇后可以放置的列col的位置
    如果有解，记录sol[row]=col，并继续下一行(row+1)的试探
    """
    global count

    # 如果当前试探row大于size-1，说明得到一个可行解
    if row > size - 1:
        count += 1
        print(sol)

    # 对row行依次试探每一列[0..row], <row, col>
    for col in range(size):
        conflict = False
        for i_row in range(row):
            if col == sol[i_row] \
               or abs(col - sol[i_row]) == abs(row - i_row):
                # <row, col> 与 <i_row, sol[i_row]> 冲突
                conflict = True
                break

        if conflict:
            continue
        else:
            sol[row] = col
            dfs0(row + 1)

def dfs1(row):
    global count

    if row > size - 1:
        count += 1

    for col in range(size):
        pie_no = row + col
        na_no = size - 1 - row + col
        if shu[col] or pie[pie_no] or na[na_no]:
            continue
        else:
            shu[col] = pie[pie_no] = na[na_no] = True
            dfs1(row+1)
            shu[col] = pie[pie_no] = na[na_no] = False


if __name__ == '__main__':
    size = int(input("size: "))   # 棋盘大小

    # 解法1：利用sol检查冲突
    # sol = [None]*size   # 已放置皇后的列号 sol[row] = col
    # st = time.time()
    # dfs0(0)
    # et = time.time()

    # 解法2：利用棋子所在的竖，撇，捺检查冲突
    shu = [False] * size
    pie = [False] * (2*size-1)
    na = [False] * (2*size-1)
    st = time.time()
    dfs1(0)
    et = time.time()


    print("Total solutions: %d" % count)
    print("Elapsed time: %f seconds" % (et-st))
