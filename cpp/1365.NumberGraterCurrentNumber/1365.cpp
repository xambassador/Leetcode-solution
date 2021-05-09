#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// O(n^2) approach
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans;
    for (int i{}; i<nums.size(); i++) {
        int cnt {};
        for (int j{}; j<nums.size(); j++) {
            if (i == j) continue;
            if (nums[j] < nums[i]) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    cin >> n;
    for (int i{}; i<n; i++) {
        int el;
        cin >> el;
        nums.push_back(el);
    }
    vector<int> ans {smallerNumbersThanCurrent(nums)};
    for (auto i : ans) {
        cout << i << " ";
    }cout << endl;
}