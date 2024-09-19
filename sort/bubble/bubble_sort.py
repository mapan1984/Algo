def bubble_sort(array):
    length = len(array)

    # 每次将最大的数字排至末尾
    for i in range(length):
        no_swap = True  # 检测是否发生交换的哨兵
        for j in range(length - 1 - i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
                no_swap = False

        if no_swap:
            # 如果一轮排序没有发生交换，则已排好序
            break

    return array


if __name__ == '__main__':
    input_string = input("请输入一串数字，用空格分隔：")
    numbers_list = list(map(int, input_string.split()))
    print(numbers_list)

    s_array = bubble_sort(numbers_list)
    print(s_array)
