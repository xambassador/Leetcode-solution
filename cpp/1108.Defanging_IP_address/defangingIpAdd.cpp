#include<iostream>
using namespace std;
 
class Solution {
public:
    string defangIPaddr(string address) {
        string output;
        for(auto i : address) {
            if(i != '.') {
                output.push_back(i);
            }

            else {
                output.push_back('[');
                output.push_back('.');
                output.push_back(']');
            }
        }   
        return output; 
    }
};

int main() {
    string address;
    cin >> address;
    
    Solution s;
    string ans {s.defangIPaddr(address)};
    cout << ans << endl;
}