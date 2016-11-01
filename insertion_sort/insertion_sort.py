#!/usr/bin/env python3

import random

def i_sort(l):
    for j in range(1, len(l)):
        i = j
        key = l[i]
        # l[0:j-1] is sorted
        while i > 0 and key < l[i-1]:
            l[i] = l[i-1]
            i = i - 1
        l[i] = key

l = [i for i in range(101)]
random.shuffle(l)
print(l)
i_sort(l)
print(l)
