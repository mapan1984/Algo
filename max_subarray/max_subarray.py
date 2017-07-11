#!/usr/bin/python3

""" 最大子数组问题的分治法解决
在数组的一系列值中，找到连续和最大的子数组
"""

import random


inf = float('Inf')
ninf = float('-Inf')

def high_index(a):
    """ return high index of a """
    return len(a) - 1

def mid_index(a):
    """ return mid index of a """
    return (0 + high_index(a)) // 2

def find_max_crossing_subarray(a, low, mid, high):
    """ 找到包含中点的子数组最大和
    返回这个子数组的区间[max_left, max_right]
                    与最大和left_sum+right_sum
    """

    left_sum = ninf
    sum = 0
    max_left = mid
    for i in range(mid, low-1, -1):
        sum = sum + a[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i

    right_sum = ninf
    sum = 0
    max_right = mid
    for j in range(mid+1, high+1):
        sum = sum + a[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j

    return max_left, max_right, left_sum+right_sum

def find_max_subarray(a, low, high):
    """找到数组的最大子数组"""
    if low == high:
        return low, high, a[low]
    else:
        mid = (low + high) // 2
        left_low, left_high, left_sum = find_max_subarray(a, low, mid)
        right_low, right_high, right_sum = find_max_subarray(a, mid+1, high)
        cross_low, cross_high, cross_sum = \
                find_max_crossing_subarray(a, low, mid, high)
        if left_sum > right_sum and left_sum > cross_sum:
            return left_low, left_high, left_sum
        elif right_sum > left_sum and right_sum > cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum


#a = list(range(-100, 100))
#random.shuffle(a)

a = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]

print(find_max_subarray(a, 0, high_index(a)))

