#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    // custom binary search function
    int isFound(vector<int> v, int start, int end, int x) {
        if(start > end) {
            return 0;
        }

        int mid {(start+end)/2};
        int cnt {0};
        if(v[mid] == x) {
            cnt = 1;
            for(int i{mid+1}; i<=end; i++) {
                if(v[i] == x) {
                    cnt += 1;
                }
            }
            for(int i{mid-1}; i>= start; i--) {
                if(v[i] == x) {
                    cnt += 1;
                }
            }
        }

        else if(x < v[mid]) {
            cnt = isFound(v, mid+1, end,x);
        }

        else if(x > v[mid]) {
            cnt = isFound(v, start, mid-1, x);
        }
        return cnt;
    }

   
    int countNegatives(vector<vector<int>>& grid) {
        // int cnt {};
        // for(int i{}; i<grid.size(); i++) {
        //     vector<int> tmp {grid[i]};
        //     for(int j{-1}; j>=-100;j--) {
        //         int ans {isFound(tmp, 0, tmp.size()-1, j)};
        //         cnt += ans;
        //     }
        // }
        // return cnt;

        // using  upper bound function
        int count=0;
        for(const auto& v:grid)
            count += upper_bound(v.rbegin(),v.rend(),-1)-v.rbegin();
        return count;
    }
};

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int> > arr;
    for(int i{}; i<m; i++) {
        vector<int> v;
        for(int j{}; j<n; j++) {
            int data;
            cin >> data;
            v.push_back(data);
        }

        arr.push_back(v);
    }

    Solution s;
    int ans {s.countNegatives(arr)};
    cout << ans << endl;
}