import time
from functools import wraps


def logger(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        ts = time.time()
        for i in range(1000):
            result = fn(*args, **kwargs)
        te = time.time()
        print("function = {0}".format(fn.__name__))
        # print("arguments = {0}{1}".format(args, kwargs))
        print("return = {0}".format(result))
        print("time = %.3f ms" % (te - ts))
        return result
    return wrapper

def get_num(filename):
    fd = open(filename, "r")
    return map(int, fd.read().split(","))

@logger
def binary_search(num_list, target):
    l = 0
    u = len(num_list) - 1
    while l <= u:
        m = (l+u)//2
        if target > num_list[m]:
            l = m + 1
        elif target == num_list[m]:
            return m
        else:
            u = m - 1
    else:
        return -1

@logger
def sequential_search(num_list, target):
    for index, item in enumerate(num_list):
        if item == target:
            return index

if __name__ == "__main__":
    filename = input("filename：")
    num_list = list(get_num(filename))
    binary_search(num_list, 116)
    sequential_search(num_list, 116)