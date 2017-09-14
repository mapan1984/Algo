"""
回溯法解01背包问题

c: 5
w: 1 2 2 3
p: 4 2 2 5
"""

"""
def back_trace(deep, res, length):
    if deep > length:
        print(res)
        return
    for i in [0,1]:
        res.append(i)
        back_trace(deep+1, res, length)
        res.pop()
"""


# 输入容量，物品重量，物品价格
capacity = int(input())
wights = [int(w) for w in input().split()]
prices = [int(p) for p in input().split()]

length = len(wights)

def back_trace(deep, left_capacity, max_res, plan):
    if deep >= length:
        print('deep: ', deep)
        print('plan: ', plan)
        print('res: ', max_res)
        return
    for i in [0, 1]:
        if i == 1:
            if left_capacity >= wights[deep]:
                left_capacity -= wights[deep]
                max_res += prices[deep]
                plan.append(i)

                back_trace(deep+1, left_capacity, max_res, plan)

                left_capacity += wights[deep]
                max_res -= prices[deep]
                plan.pop()
        else:
            plan.append(i)
            back_trace(deep+1, left_capacity, max_res, plan)
            plan.pop()


back_trace(0, capacity, 0, [])

