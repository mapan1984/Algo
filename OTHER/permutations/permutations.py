def f(seqs, depth):
    if len(seqs) - 1 == depth:
        print(seqs)
        return
    for i in range(depth, len(seqs)):
        seqs[i], seqs[depth] = seqs[depth], seqs[i]
        f(seqs, depth + 1)
        seqs[i], seqs[depth] = seqs[depth], seqs[i]


f([1, 2, 3], 0)


def permute(nums):
    res = []

    def f(depth):
        if depth == len(nums) - 1:
            res.append(nums[:])
        for i in range(depth, len(nums)):
            nums[depth], nums[i] = nums[i], nums[depth]
            f(depth+1)
            nums[depth], nums[i] = nums[i], nums[depth]

    f(0)

    return res


print(permute([1, 2, 3]))
