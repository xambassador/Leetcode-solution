//
// Created by yash on 16/05/21.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int maximumCharacters {256};
        int mask[maximumCharacters];
        for (int i{}; i<256; i++) mask[i] = -1;
        int maximumLength {};
        int lastRepeatedPosition {-1};

        for (int i{}; i<s.size(); i++) {
            if (mask[s[i]] != -1 && lastRepeatedPosition < mask[s[i]]) lastRepeatedPosition = mask[s[i]];
            if (i - lastRepeatedPosition > maximumLength) maximumLength = i - lastRepeatedPosition;
            mask[s[i]] = i;
        }

        return maximumLength;
    }
};

int main() {
    string s {};
    cin >> s;
    Solution sol;
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;
}