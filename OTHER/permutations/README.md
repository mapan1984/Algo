permutation([a, b, c])
    = {
        a, permutation([b, c])
        b, permutation([a, c])
        c, permutation([a, b])
    }
