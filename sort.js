'use strict';
class Sort{
    
    static #findSmallest(arr){
        let smlst=arr[0];
        let smlstIndex=0;
        for(let i=0;i<arr.length;++i){
            if(arr[i] < smlst){
                smlst=arr[i];
                smlstIndex=i
                }
        }
        // for(let itm of arr){
        return smlstIndex;
    }
    static selectionSort(arr){
        let newarr=[];
        const len=arr.length
        for(let i=0;i<len;i++){
            let index=Sort.#findSmallest(arr)
            newarr.push(arr[index]);
            arr.splice(index,1)
        }
        return newarr;
    }
}

let arr=[93,675,354,45,38,7456]
let newarr=Sort.selectionSort(arr)
console.log(newarr)
console.log(arr)