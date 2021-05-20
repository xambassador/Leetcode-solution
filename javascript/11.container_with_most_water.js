/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let maxCoverArea = 0;
    let left = 0, right = height.length - 1;
    while (left < right) {
        let area = (right - left) * Math.min(height[left], height[right]);
        maxCoverArea = area > maxCoverArea ? area : maxCoverArea;

        if (height[left] < height[right]) {
            do {
                left++;
            } while (left < right && height[left-1] >= height[left]);
        } else {
            do {
                right--;
            } while (right > left && height[right+1] >= height[right]);
        }
    }
    return maxCoverArea;
};

console.log(maxArea([1,8,6,2,5,4,8,3,7]));