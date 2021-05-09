//
// Created by yash on 09/05/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        if (arr.empty()) {
            return;
        }

        vector<int> tmp;

        for (int i = 0; i<arr.size(); i++) {
            if (arr[i] != 0) tmp.push_back(arr[i]);
            else {
                tmp.push_back(0);
                tmp.push_back(0);
            }
        }

        for (int i = 0; i<arr.size(); i++) {
            arr[i] = tmp[i];
        }
    }
};

int main() {
    vector<int> arr;

    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Solution s;
    s.duplicateZeros(arr);
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}