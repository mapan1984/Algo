def combine(nums, m):
    res = []

    def backtrack(depth, cur):
        if len(cur) == m:
            res.append(cur[:])

        for i in range(depth, len(nums)):
            cur.append(nums[i])
            backtrack(i + 1, cur)
            cur.pop()

    backtrack(0, [])

    return res


print(combine([1, 2, 3, 4], 3))
