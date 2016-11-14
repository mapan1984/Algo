var insertSort = function(array){

    var newArray = array,
        length = array.length,
        i, j;

    /* 
     * sorted: newArray[0..i)
     * wait sort: newArray[i..length)
     * insert newArray[i] into newArray[0..i)
     */
    for (i=1; i<length; i++){
        j = i;
        tmp = newArray[i]; 
        while(j>0 && newArray[j-1]>tmp){
            newArray[j] = newArray[j-1];
            j--;
        }
        newArray[j]=tmp;
    }

    return newArray;
}
