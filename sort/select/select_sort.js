const selectSort = array => {
    let length = array.length

    for (let i = 0; i < length - 1; i++) {
        // find the index of min element in array[i, length)
        let indexMin = i
        for (let j = i; j < length; j++) {
            if (array[indexMin] > array[j]) {
                indexMin = j
            }
        }

        if (i !== indexMin) {
            var tmp = array[i]
            array[i] = array[indexMin]
            array[indexMin] = tmp
        }
    }

    return array
}

module.exports = selectSort

if (require.main === module) {
    const readline = require('readline');

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('请输入一串数字，用空格分隔：', (inputString) => {
        const numbersArray = inputString.split(' ').map(Number);
        console.log(numbersArray);

        sortedArray = selectSort(numbersArray)
        console.log(sortedArray);

        rl.close();
    });
}
