const insertSort = array => {
    let newArray = array
    let length = array.length
    let i
    let j

    /*
     * sorted: newArray[0..i)
     * wait sort: newArray[i..length)
     * insert newArray[i] into newArray[0..i)
     */
    for (i = 1; i < length; i++) {
        j = i
        let tmp = newArray[i]
        while (j > 0 && newArray[j - 1] > tmp) {
            newArray[j] = newArray[j - 1]
            j--
        }
        newArray[j] = tmp
    }

    return newArray
}
