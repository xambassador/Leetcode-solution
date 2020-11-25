#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
    public:
    unordered_map<char, int> map;

    int romanToInt(string s) {
        
        map.insert(make_pair('I', 1));   
        map.insert(make_pair('V', 5));   
        map.insert(make_pair('X', 10));   
        map.insert(make_pair('L', 50));   
        map.insert(make_pair('C', 100));   
        map.insert(make_pair('D', 500));   
        map.insert(make_pair('M', 1000));   

        int decimal {0};
        for(int i{}; i<s.length(); i++) {
            if(i > 0 && map[s[i]] > map[s[i-1]]) {
                decimal += map[s[i]] - 2*map[s[i-1]];
            }else {
                decimal += map[s[i]];
            }
        }
        return decimal;
    }
};


int main() {
    string s;
    cin >> s;

    Solution o;
    int ans {o.romanToInt(s)};
    cout << ans << endl;
}