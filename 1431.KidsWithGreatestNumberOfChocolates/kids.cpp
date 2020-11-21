#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
public:

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       vector<bool> ans;
       int max{0};
       for(auto i : candies) {
           if(i > max) {
               max = i;
           }
       }

       for(auto i : candies) {
           if(i + extraCandies < max) {
               ans.push_back(false);
           }else {
               ans.push_back(true);
           }
       }
       return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i{}; i<n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    int extraCandies;
    cin >> extraCandies;

    Solution s;
    vector<bool> ans {s.kidsWithCandies(arr,extraCandies)};
    for(int i{}; i<n; i++) {
        cout << boolalpha << ans[i] << ' ';
    }cout << endl;
}