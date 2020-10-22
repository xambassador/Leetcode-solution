#include<iostream>
#include<vector>
using namespace std;

void help(vector<int>& nums, int lstart, int lend, int rstart, int rend, vector<int>& output) {
    if(lstart > lend || rstart > rend) return;

    output.push_back(nums[lstart]);
    output.push_back(nums[rstart]);   
    help(nums, lstart+1, lend, rstart+1, rend, output); 
}


vector<int> shuffleArray(vector<int>& nums, int n) {
    vector<int> output;
    help(nums, 0,n-1, n, nums.size()-1, output);
    return output;
}


int main() {
    vector<int> input;
    int n;
    cin >> n;
    for(int i{}; i<n; i++) {
        int d;
        cin >> d;
        input.push_back(d);
    }
    int x;
    cin >> x;
    vector<int> out {shuffleArray(input,x)};
    for(int& i : out) {
        cout << i << " ";
    }cout << endl;
}   