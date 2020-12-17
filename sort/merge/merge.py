#!/usr/bin/env python3

import random
import operator

"""
split each element into partitions of size 1
recursively merge adjancent partitions
    for i = leftPartStartIndex to rightPartLastIndex
        if leftPartHeadValue <= rightPartHeadValue:
            copy leftPartHeadValue
        else:
            copy rightPartHeadValue;
        Increase InvIdx
copy elements back to original array
"""


def merge_r(left, right):
    if not left:
        return right
    if not right:
        return left
    if left[0] < right[0]:
        return [left[0]] + merge(left[1:], right)
    else:
        return [right[0]] + merge(left, right[1:])



def merge(left, right, compare):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if compare(left[i], right[j]):
            result.append(left[i])
            i = i + 1
        else:
            result.append(right[j])
            j = j + 1
    while i < len(left):
        result.append(left[i])
        i = i + 1
    while j < len(right):
        result.append(right[j])
        j = j + 1
    return result


def merge_sort(L, compare=operator.lt):
    if len(L) < 2:
        return L[:]
    else:
        middle = int(len(L)/2)
        left = merge_sort(L[:middle], compare)
        right = merge_sort(L[middle:], compare)
        return merge(left, right, compare)


l = list(range(10))
random.shuffle(l)
print(merge_sort(l))
