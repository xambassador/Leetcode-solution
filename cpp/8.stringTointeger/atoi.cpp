#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

const long long int MAX = numeric_limits<int>::max();
const long long int MIN = numeric_limits<int>::min();

int myAtoi(string str) {
    // If string is empty, no conversion
    if(str.empty()) return 0;
    
    // ans = for final answer
    // i = for traverse on each character of string
    // isNegative = for verify that number is negative or not
    int ans{0};
    int i{0};
    bool isNegative{false};

    // Remove white spaces
    for(; i < str.length() && isspace(str[i]); ++i);

    // Boundry check
    if(i == str.length()) return 0;

    // Check for + or - sign
    if(str[i] == '-' || str[i] == '+') {
        isNegative = (str[i] == '-');
        ++i;
    }

    // Check for digits
    for(; i<str.length() && isdigit(str[i]); ++i) {
        int number{str[i] - '0'};
        
        // Check for integer overflow
        if(ans > (MAX - number)/10) {
            return isNegative ? MIN : MAX;
        }
        
        ans = ans * 10 + number;
    } 
    return isNegative ? -ans : ans;
}



int main(){
    string s;
    cin >> s;
    int ans{myAtoi(s)};
    cout << ans << endl;
}