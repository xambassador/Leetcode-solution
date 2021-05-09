//
// Created by yash on 09/05/21.
//

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let arr = [...nums1, ...nums2];
    arr.sort((a,b) => a - b);
    let mid = parseInt(arr.length / 2);
    if (arr.length % 2 == 0) {
        return (arr[mid] + arr[mid-1]) / 2.0;
    } else {
        return arr[mid];
    }
};

let a = [1,2];
let b = [3,4];

console.log(findMedianSortedArrays(a,b));