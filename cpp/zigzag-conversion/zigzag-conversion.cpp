#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1){
        return s;
    }        
    const int steps{2*numRows-2};
    string ans{""};
    for(int i{}; i<numRows; ++i){
        for(int j{i}; j<s.length(); j+=steps){
            ans.push_back(s[j]);
            if(0 < i && i < numRows - 1 && j+steps-2*i < s.length()){
                ans.push_back(s[j + steps - 2 * i]);
            }
        }
    }
    return ans;
}

int main(){
    string s{"PAYPALISHIRING"};
    int numRows;
    cin >> numRows;
    cout << convert(s,numRows) << endl;
}