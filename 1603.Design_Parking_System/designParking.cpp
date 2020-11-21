#include<iostream>
using namespace std;
 
class ParkingSystem {
    int big;
    int medium;
    int small;
    
    public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(big != 0) {
                big -= 1;
                return true;
            }else {
                return false;
            }
        }else if(carType == 2) {
            if(medium != 0) {
                medium -= 1;
                return true;
            }else {
                return false;
            }
        }else if(carType == 3) {
            if(small != 0) {
                small -= 1;
                return true;
            }else {
                return false;
            }
        }
    }
};


int main() {
    int big, medium, small;
    cin >> big >> medium >> small;
    ParkingSystem* ps {new ParkingSystem(big, medium, small)};
    int q;
    cin >> q;
    while(q--) {
        int car;
        cin >> car;
        bool ans {ps->addCar(car)};
        cout << boolalpha <<  ans << endl;
    }
}