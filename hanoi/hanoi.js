/*
 how to move n disc from src to dst by aux
 1. move n-1 disc from src to aux by dst
 2. move n disc from src to dst
 3. move n-1 disc from aux to dst by src
 */

 var hanoi = function(disc, src, aux, dst){
     if(disc > 0){
         hanoi(disc - 1, src, dst, aux);
         console.log("move"+disc+" from "+src+" to "+"dst"); 
         hanoi(disc - 1, aux, src, dst);
     }
 };

 hanoi(3, "Src", "Aux", "Dst");
