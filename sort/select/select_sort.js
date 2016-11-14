var selectsort = function (array){

    var newArray = array,
        length = array.length,
        indexMin;

    for(var i=0; i<length-1; i++){
        indexMin = i;

        // find the index of min element in newarray[i, length)
        for(var j=i; j<length; j++){
            if(newArray[indexMin] > newArray[j]){
                indexMin = j;
            }
        }
        if(i !== indexMin){ //swap
            var tmp = newArray[i];
            newArray[i] = newArray[indexMin];
            newArray[indexMin] =tmp;
        }
    }

    return newArray;
};
