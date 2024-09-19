const insertSort = array => {
    /*
     * sorted: array[0..i)
     * wait sort: array[i..length)
     * insert array[i] into array[0..i)
     */
    for (let i = 1; i < array.length; i++) {
        let j = i
        let tmp = array[i]
        while (j > 0 && array[j - 1] > tmp) {
            array[j] = array[j - 1]
            j--
        }
        array[j] = tmp
    }

    return array
}

module.exports = insertSort

if (require.main === module) {
    const readline = require('readline');

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('请输入一串数字，用空格分隔：', (inputString) => {
        const numbersArray = inputString.split(' ').map(Number);
        console.log(numbersArray);

        sortedArray = insertSort(numbersArray)
        console.log(sortedArray);

        rl.close();
    });
}
