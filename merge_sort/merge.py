#!/usr/bin/env python3
# encoding: utf-8

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

def merge(left,right,compare):
    result=[]
    i,j=0,0
    while i<len(left) and j<len(right):
        if compare(left[i],right[j]):
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    while (i<len(left)):
        result.append(left[i])
        i+=1
    while (j<len(right)):
        result.append(right[j])
        j+=1
    return result

def merge_sort(L,compare=operator.lt):
    if len(L)<2:
        return L[:]
    else:
        middle = int(len(L)/2)
        left=merge_sort(L[:middle], compare)
        right=merge_sort(L[middle:], compare)
        return merge(left,right,compare)

l = list(range(10))
random.shuffle(l)
print(merge_sort(l))
