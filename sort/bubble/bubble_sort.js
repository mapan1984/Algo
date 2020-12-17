const bubbleSort = array => {
    const length = array.length
    let newArray = array
    let noSwap
    let tmp

    for (let i = 0; i < length; i++) {
        noSwap = true // 检测是否发生交换的哨兵
        for (let j = 0; j < length - 1 - i; j++) {
            if (newArray[j] > newArray[j + 1]) {
                tmp = newArray[j]
                newArray[j] = newArray[j + 1]
                newArray[j + 1] = tmp
                noSwap = false
            }
        }
        if (noSwap) {
            // 如果一轮排序没有发生交换，则已排好序
            break
        }
    }

    return newArray
}

module.exports = bubbleSort
