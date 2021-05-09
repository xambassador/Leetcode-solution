//
// Created by yash on 09/05/21.
//
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let i = 0;
    let j = 0;

    let tmp = [];

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            tmp.push(nums1[i]);
            i++;
        } else {
            tmp.push(nums2[j]);
            j++;
        }
    }

    while (i < m) {
        tmp.push(nums1[i]);
        i++;
    }

    while (j < n) {
        tmp.push(nums2[j]);
        j++;
    }

    for (let i = 0; i < tmp.length; i++) {
        nums1[i] = tmp[i];
    }
};



let nums1 = [1,2,3,0,0,0];
let m = 3;
let nums2 = [2,5,6];
let n = 3;

merge(nums1,m,nums2,n);
console.log(nums1);