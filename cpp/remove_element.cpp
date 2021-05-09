//
// Created by yash on 09/05/21.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length {(int)nums.size()};
        int i {};

        while (i < length) {
            if (nums[i] == val) {
                nums[i] = nums[length - 1];
                length--;
            } else {
                i++;
            }
        }

        return length;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i{}; i<n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int val;
    cin >> val;

    Solution s;
    int ans = s.removeElement(nums, val);
    cout << ans << endl;
}