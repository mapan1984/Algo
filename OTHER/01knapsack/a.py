"""
c: 5
w: 1 2 2 3
p: 4 2 2 5
"""

def get_plans(length):
    """得到代表所有情况的01序列"""
    plans = []
    for i in range(pow(2,length)):
        plan = bin(i)[2:].ljust(length, '0')
        # print(choose)
        plans.append(plan)
    return plans

# 输入容量，物品重量，物品价格
capacity = int(input())
wight = [int(w) for w in input().split()]
price = [int(p) for p in input().split()]


length = len(wight)
plans = get_plans(length)

# 在循环中比较每种情况，得出最优解
max_get = 0
for plan in plans:
    left = capacity
    cur_get = 0
    for n,p in enumerate(plan):
        if p == '1':
            if left >= wight[n]:
                left -= wight[n]
                cur_get += price[n]
    else:
        max_get = max(max_get, cur_get)

print(max_get)
