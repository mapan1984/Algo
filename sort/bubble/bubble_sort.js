var bubbleSort = function(array){

    var length = array.length,
        newArray = array,
        noSwap,
        tmp;

    for(var i=0; i<length; i++){
        noSwap = true; // 检测是否发生交换的哨兵
        for(var j=0; j<length-1-i; j++){
            if(newArray[j] > newArray[j+1]){
                tmp = newArray[j];
                newArray[j] = newArray[j+1];
                newArray[j+1] = tmp;
                noSwap = false;
            }
        }
        if(noSwap){ // 如果一轮排序没有发生交换，则已排好序
            break;
        }
    }

    return newArray;
};
