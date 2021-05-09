//
// Created by yash on 09/05/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string& s) {
        string oddStr = "";
        string evenStr = "";
        int length {(int) s.length()};

        // For odd length
        for (int i{}; i<length; i++) {
            int left = i-1;
            int right = i+1;

            while (left >= 0 && right <= length-1) {
                if (s[left] == s[right]) {
                    left--;
                    right++;
                } else {
                    break;
                }
            }

            left = left + 1;
            right = right - 1;

            string str = s.substr(left, (right-left) + 1);
            if (str.length() > oddStr.length()) {
                oddStr = str;
            }
        }


        // for even length

        for (int i{}, j{1}; j<length; i++,j++) {
            if (s[i] == s[j]) {
                int left = i-1;
                int right = j+1;
                while (left >= 0 && right <= length - 1) {
                    if (s[left] == s[right]) {
                        left--;
                        right++;
                    } else {
                        break;
                    }
                }
                left = left + 1;
                right = right - 1;
                string str = s.substr(left, (right-left) + 1);
                if (str.length() > evenStr.length()) {
                    evenStr = str;
                }
            } else {
                continue;
            }
        }

        return oddStr.length() >= evenStr.length() ? oddStr : evenStr;
    }

};

int main() {
    string s;
    cin >> s;

    Solution sol;
    string ans = sol.longestPalindrome(s);
    cout << ans << endl;
}