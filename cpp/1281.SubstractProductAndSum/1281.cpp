#include<iostream>
using namespace std;

class Solution {
public:

    int product(int n) {
        if (n == 0 || n == 1) return 1;
        int t {n % 10};
        int ans {product(n/10)};
        return ans * t;
    }

    int sum(int n) {
        if (n == 0) return 0;
        int t {n % 10};
        int ans {sum(n / 10)};
        return ans + t;
    }

    int subtractProductAndSum(int n) {
        return product(n) - sum(n);
    } 
};


int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.subtractProductAndSum(n) << endl;

}