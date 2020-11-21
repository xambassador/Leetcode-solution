#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> map;
        for(auto i : S) {
            map[i]++; 
        }
        int cnt{0};
        for(auto i : J) {
            cnt += map[i];
        }
        return cnt;
    }   
};


int main() {
    string j,s;
    cin >> j >> s;

    Solution o;
    int ans {o.numJewelsInStones(j,s)};
    cout << ans << endl;
}