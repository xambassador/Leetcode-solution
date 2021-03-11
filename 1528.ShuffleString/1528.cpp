#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
    static bool compare(pair<char,int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    }

    string restoreString(string s, vector<int>& indices) {
        vector<pair<char, int> > arr;
        int n {(int)s.length()};
        for (int i{}; i<n; i++) {
            arr.push_back(make_pair(s[i], indices[i]));
        } 
        
        sort(arr.begin(), arr.end(), this->compare);

        string ans {""};
        for (int i{}; i<n; i++) {
            ans += arr[i].first;
        }

        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> indices;
    for (int i{}; i<s.length(); i++) {
        int n;
        cin >> n;
        indices.push_back(n);
    }

    Solution s1;
    string ans {s1.restoreString(s,indices)};
    cout << ans << endl;
}