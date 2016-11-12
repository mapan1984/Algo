import time

def factorial1(n):
    ''' 返回n!，递归版本 '''
    n = int(n)
    if n == 0:
        return 1
    else:
        return n * factorial1(n-1)

def factorial2(n):
    ''' 返回n!，尾递归版本 '''
    def iter(n, x):
        n = int(n)
        x = int(x)
        if n == 0:
            return x
        else:
            return iter(n-1, x*n)
    return iter(n, 1)


def factorial3(n):
    ''' 返回n!，尾递归展开版本 '''
    n = int(n)
    x = 1
    while True:
        if n == 0:
            return x
        else:
            x = x * n
            n = n - 1

def show(fn, argv):
    ts = time.time()
    for i in range(1000):
        result = fn(argv)
    te = time.time()
    print("%s: \nresult = %s\ntime = %.6f ms\n\n" %
            (fn.__name__, result, (te-ts)))

if __name__ == "__main__":
    n = input("n = ")
    show(factorial1, n)
    show(factorial2, n)
    show(factorial3, n)