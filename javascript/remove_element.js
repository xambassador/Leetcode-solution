//
// Created by yash on 09/05/21.
//
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let len = nums.length;
    let i = 0;

    while (i < len) {
        if (nums[i] == val) {
            nums[i] = nums[len - 1];
            len--;
        } else {
            i++;
        }
    }
    return len;
};

let nums = [3,2,2,3]
let val = 3
removeElement(nums,val);
console.log(nums);