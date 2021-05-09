//
// Created by yash on 09/05/21.
//

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let oddStr = "";
    let evenStr = "";

    // For odd length
    for (let i = 0; i<s.length; i++) {
        let left = i-1;
        let right = i+1;

        let str = returnPalindromString(s,left,right);
        if (str.length > oddStr.length) {
            oddStr = str;
        }
    }

    // for even length

    for (let i = 0, j = 1; j < s.length; i++, j++) {
        if (s[i] == s[j]) {
            let left = i-1;
            let right = j+1;
            let str = returnPalindromString(s,left,right);
            if (str.length > evenStr.length) {
                evenStr = str;
            }
        } else {
            continue;
        }
    }

    return oddStr.length >= evenStr.length ? oddStr : evenStr;
};


/**
 * @param {string} s
 * @param {number} left
 * @param {number} right
 * @return {string}
 */
let returnPalindromString = function(s, left, right) {
    while (left >= 0 && right < s.length) {
        if (s[left] == s[right]) {
            left--;
            right++;
        } else {
            break;
        }
    }

    left += 1;
    right -= 1;

    let str = s.substr(left, (right - left) + 1);
    return str;
}