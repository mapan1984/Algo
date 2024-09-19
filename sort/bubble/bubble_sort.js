const bubbleSort = array => {
    const length = array.length

    // 每次将最大的数字排至末尾
    for (let i = 0; i < length; i++) {
        let noSwap = true // 检测是否发生交换的哨兵
        for (let j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                const tmp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = tmp
                noSwap = false
            }
        }
        if (noSwap) {
            // 如果一轮排序没有发生交换，则已排好序
            break
        }
    }

    return array
}

module.exports = bubbleSort

if (require.main === module) {
    const readline = require('readline');

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('请输入一串数字，用空格分隔：', (inputString) => {
        const numbersArray = inputString.split(' ').map(Number);
        console.log(numbersArray);

        sortedArray = bubbleSort(numbersArray)
        console.log(sortedArray);

        rl.close();
    });
}
