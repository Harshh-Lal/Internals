#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Base Class
class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    float balance;

public:
    // Constructor for base class
    Account(string name, int accNo, string accType, float bal) {
        customerName = name;
        accountNumber = accNo;
        accountType = accType;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void displayBalance() const {
        cout << "Account Holder: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    float getBalance() const {
        return balance;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }

    void updateBalance(float newBalance) {
        balance = newBalance;
    }
};

// Derived class for Savings Account
class SavAcct : public Account {
public:
    // Constructor for SavAcct using base class constructor
    SavAcct(string name, int accNo, float bal)
        : Account(name, accNo, "Savings", bal) {}

    void computeInterest(float rate, int timeInYears) {
        float interest = balance * pow((1 + rate / 100), timeInYears) - balance;
        cout << "Interest of $" << interest << " added to your savings account.\n";
        deposit(interest);
    }
};

// Derived class for Current Account
class CurAcct : public Account {
    const float minBalance = 500.0;
    const float serviceCharge = 50.0;

public:
    // Constructor for CurAcct using base class constructor
    CurAcct(string name, int accNo, float bal)
        : Account(name, accNo, "Current", bal) {}

    void checkMinBalance() {
        if (balance < minBalance) {
            cout << "Balance below minimum. Imposing service charge of $" << serviceCharge << endl;
            if (balance > serviceCharge)
                balance -= serviceCharge;
            else
                balance = 0;
        } else {
            cout << "Minimum balance maintained.\n";
        }
    }
};

// Example usage
int main() {
    // Creating Savings Account object with constructor
    SavAcct savings("Alice", 1001, 1000.0);
    savings.deposit(500);
    savings.computeInterest(5.0, 2); // 5% interest for 2 years
    savings.withdraw(300);
    savings.displayBalance();

    cout << "\n";

    // Creating Current Account object with constructor
    CurAcct current("Bob", 2001, 400.0);
    current.deposit(200);
    current.withdraw(100);
    current.checkMinBalance();
    current.displayBalance();

    return 0;
}