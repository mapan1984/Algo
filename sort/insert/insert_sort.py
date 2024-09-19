#!/usr/bin/env python3

import random


def insert_sort(array):
    for j in range(1, len(array)):
        i = j
        key = array[i]
        # array[0:j-1] is sorted
        # insert array[i] into array[0:i-1]
        while i > 0 and key < array[i-1]:
            array[i] = array[i-1]
            i = i - 1

        array[i] = key


if __name__ == "__main__":
    array = [i for i in range(101)]
    random.shuffle(array)
    print(array)

    insert_sort(array)
    print(array)
