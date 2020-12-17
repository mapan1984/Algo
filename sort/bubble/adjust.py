try:
    while True:
        s = input()
        sl = list(s)
        l = len(sl)
        for i in range(l):
            for j in range(l-1-i):
                if sl[j].isupper() and sl[j+1].islower():
                    sl[j], sl[j+1] = sl[j+1], sl[j]
        print("".join(sl))
except:
    pass
