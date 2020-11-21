#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

    // using merge sort
    int merger(vector<int>& arr, int start, int mid, int end) {
        int n {(mid-start) + 1};
        int m {(end-(mid+1)) + 1};

        // create left array
        vector<int> left;
        for(int i{start}; i<=mid; i++) {
            left.push_back(arr[i]);
        }

        //create right array
        vector<int> right;
        for(int i{mid+1}; i<=end; i++) {
            right.push_back(arr[i]);
        }
        
        // first count pairs
        int i{0}, pairCnt{0};
        while(i < n) {
            int j{0};
            while(j < m) {
                if(right[j] == left[i]) {
                    pairCnt += 1;
                }
                j++;
            }
            i++;
        }

        // now merge both sorted array in to tmp 
        vector<int> tmp;
        int j{0};
        i = 0;
        while(i < n && j < m) {
            if(left[i] <= right[j]) {
                tmp.push_back(left[i]);
                i++;
            }else {
                tmp.push_back(right[j]);
                j++;
            }
        }

        while(i < n) {
            tmp.push_back(left[i]);
            i++;
        }

        while(j < m) {
            tmp.push_back(right[j]);
            j++;
        }
        
        // Now copy all tmp content into original array
        for(int i{start}, j{0}; i<=end; i++, j++) {
            arr[i] = tmp[j];
        }

        return pairCnt;
    }

    int help(vector<int>& arr, int start, int end) {
        int ans {0};
        if(start < end) {
            int mid {(start+end) / 2};
            int lans {help(arr,start, mid)};
            int rans {help(arr,mid+1, end)};
            int myAns {merger(arr,start,mid, end)};
            return lans + rans + myAns;
        }
        return ans; 
    } 

    // using map

    int help_map(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans {0};
        for(auto i:nums) {
            ans = ans + map[i]++;
        } 
        return ans;
    }

    int numIdenticalPairs(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
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

    Solution s;
    int ans {s.numIdenticalPairs(arr)};
    cout << ans << endl;

    int ans1 {s.help_map(arr)};
    cout << ans1 << endl;
}