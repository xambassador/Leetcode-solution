#include<iostream>
#include<vector>
using namespace std;


void help(vector<int>& nums, int psum, int start, int end, vector<int>& output) {
    if(start > end) return;

    int currentSum {nums[start] + psum};
    output.push_back(currentSum);
    help(nums, currentSum, start+1, end, output);
}


vector<int> runningSum(vector<int>& nums) { 
    vector<int> output;
    help(nums, 0,0,nums.size()-1, output);
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
    vector<int> output {runningSum(input)};
    for(int i{}; i<output.size(); i++) {
        cout << output[i] << " ";
    }cout << endl;
}