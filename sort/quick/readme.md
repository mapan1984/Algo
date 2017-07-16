### quick sort

    quick_sort(list):
        pivot = list[random]
        left = []
        right = []
        for i in list:
            if i <= pivot:
                left.append(i)
            else:
                right.append(i)
        quick_sort(left)
        quick_sort(right)
