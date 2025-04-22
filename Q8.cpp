#include <iostream>
using namespace std;

class Cinema {
    int seats[3] = {100, 100, 100}; // 1pm, 5pm, 8:30pm
public:
    void bookSeats(int performance, int num) {
        if (seats[performance] >= num) {
            seats[performance] -= num;
            cout << "Booking successful!" << endl;
        } else {
            cout << "Not enough seats!" << endl;
        }
    }
    void showRemaining(int performance) {
        cout << "Remaining seats: " << seats[performance] << endl;
    }
};

int main() {
    Cinema cine;
    cine.bookSeats(0, 5); // Book 5 seats for 1pm
    cine.showRemaining(0); // 95
    return 0;
}