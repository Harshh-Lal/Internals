#include <iostream>
using namespace std;

class AddAmount {
private:
    int amount;

public:
    // Constructor without any parameter
    AddAmount() {
        amount = 50;  // Initial amount only
    }

    // Constructor with parameter to add to the initial amount
    AddAmount(int add) {
        amount = 50 + add;  // Add to initial amount
    }

    void displayAmount() {
        cout << "Final amount in Piggie Bank: $" << amount << endl;
    }
};

// Example usage
int main() {
    // Object with no additional amount
    AddAmount piggie1;
    piggie1.displayAmount();  // Should show $50

    // Object with additional amount
    AddAmount piggie2(70);
    piggie2.displayAmount();  // Should show $120

    return 0;
}