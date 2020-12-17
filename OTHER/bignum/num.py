from itertools import zip_longest


def add(s1, s2):
    res = []
    carry = 0
    for a, b in zip_longest(reversed(s1), reversed(s2), fillvalue=0):
        print(a,b,carry)
        c = int(a) + int(b) + carry
        if c >= 10:
            carry = 1
            res.append(str(c - 10))
        else:
            carry = 0
            res.append(str(c))
    return ''.join(reversed(res))


class Num:
    def __init__(self, value):
        if isinstance(value, str):
            self.value = value
        elif isinstance(value, Num):
            self.value = value.value

    def __add__(self, value):
        if isinstance(value, str):
            return Num(add(self.value, value))
        elif isinstance(value, Num):
            return Num(add(self.value, value.value))

    def __sub__(self, value):
        return self.value - value

    def __str__(self):
        return f'Num: {self.value}'


n = Num('0')

# print(n - '1')
print(n + '1')

print(add('123', '12345678'))

