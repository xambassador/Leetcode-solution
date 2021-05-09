//
// Created by yash on 09/05/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 size = m + n
        int i {};
        int j {};

        vector<int> tmp;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                tmp.push_back(nums1[i]);
                i++;
            } else {
                tmp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            tmp.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            tmp.push_back(nums2[j]);
            j++;
        }

        for (int i{}; i<tmp.size(); i++) {
            nums1[i] = tmp[i];
        }
    }
};


int main() {
    vector<int> nums1, nums2;
    int s1, s2;
    int m, n;

    cin >> s1;
    for (int i{}; i<s1; i++) {
        int x;
        cin >> x;
        nums1.push_back(x);
    }

    cin >> m;

    cin >> s2;
    for (int i{}; i<s2; i++) {
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    cin >> n;

    Solution s;
    s.merge(nums1,m,nums2,n);

    for (auto i : nums1) {
        cout << i << " ";
    }cout << endl;
}