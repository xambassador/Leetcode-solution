//
// created by yash on 20/05/21
//

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const maxCharacters = 256;
    const mask = [];
    for (let i = 0; i<256; i++) mask.push(-1);

    let maximumLength = 0;
    let lastRepeatedCharacterPosition = -1;

    for (let i = 0; i<s.length; i++) {
        if (mask[s[i]] !== -1 && lastRepeatedCharacterPosition < mask[s[i]]) {
            lastRepeatedCharacterPosition = mask[s[i]]
        }
        if (i - lastRepeatedCharacterPosition > maximumLength) {
            maximumLength = i - lastRepeatedCharacterPosition;
        }
        mask[s[i]] = i;
    }

    return maximumLength;
};

console.log(lengthOfLongestSubstring("abcabcbb"));