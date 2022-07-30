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
    static selectionREC(arr){
        return [].concat(1)
    }

    static QSort(arr){
        if(arr.length<2)
        return arr
        // else if(arr.length ==2){
        //     if(arr[0] > arr[1])
        //     [arr[0], arr[1]] = [arr[1], arr[0]];
        //     return arr;
        // }
        else{
            let pivot=arr[0];
            // let left=arr.slice(1).filter(itm => itm <= pivot) , right=arr.slice(1).filter(itm => itm > pivot);
            let left=[], right=[]
            arr.slice(1).forEach(itm => {
                itm <= pivot?left.push(itm):right.push(itm);
            });
            // console.log(left, right)
            return [...Sort.QSort(left),pivot,...Sort.QSort(right)]
        }
    }
}

let arr=[3,93,675,354,45,38,7456,93]
console.log(Sort.QSort(arr))
// let newarr=Sort.selectionSort(arr)
// console.log(newarr)
// console.log(Sort.selectionREC(arr))