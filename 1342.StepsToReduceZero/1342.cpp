#include<iostream>
using namespace std;


int numberOfSteps (int num) {
    if (num == 0) return 0;

    int totalSteps {};
    if (num % 2 == 0) {
        totalSteps++;
        num = num / 2;
    } else {
        totalSteps++;
        num = num - 1;
    }
    int ans {numberOfSteps(num)};
    return totalSteps + ans;
}



int main() {
    int num;
    cin >> num;
    int ans {numberOfSteps(num)};
    cout << ans << endl;
}