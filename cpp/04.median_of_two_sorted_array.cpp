//
// Created by yash on 09/05/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i {};
        int j {};
        int size1 {(int)nums1.size()};
        int size2 {(int)nums2.size()};
        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < size1) {
            arr.push_back(nums1[i]);
            i++;
        }

        while (j < size2) {
            arr.push_back(nums2[j]);
            j++;
        }

        int mid = (arr.size()) / 2;
        double ans = 0.00000;
        if (arr.size() % 2 == 0) {
            ans = ((double )arr[mid] + arr[mid-1]) / 2.0;
        } else {
            ans = (double )arr[mid];
        }

        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> nums1, nums2;
    for (int i{}; i<n; i++) {
        int x;
        cin >> x;
        nums1.push_back(x);
    }

    cin >> n;
    for (int i{}; i<n; i++) {
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    Solution s;
    double ans = s.findMedianSortedArray(nums1, nums2);
    cout << ans << endl;
}