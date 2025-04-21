#include <iostream>
#include <string>
using namespace std;

class account {
protected:
    string name;
    long acc_number;
    string type;
    double balance;
public:
    void initialize(string n, long an, string t, double bal) {
        name = n;
        acc_number = an;
        type = t;
        balance = bal;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void display() {
        cout << "Balance: $" << balance << endl;
    }
    virtual void compute_interest() {} // Overridden in sav_acct
    virtual void withdraw(double amount) = 0; // Pure virtual
    virtual void check_min_balance() {} // Overridden in cur_acct
};

class sav_acct : public account {
    double rate = 0.04; //4% annual interest
public:
    void compute_interest() override {
        balance += balance * rate;
    }
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

class cur_acct : public account {
    double min_balance = 500.0;
    double service_charge = 10.0;
public:
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            check_min_balance();
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
    void check_min_balance() override {
        if (balance < min_balance) {
            balance -= service_charge;
            cout << "Service charge applied." << endl;
        }
    }
};

// Example usage
int main() {
    sav_acct s;
    s.initialize("Alice", 1001, "savings", 1000);
    s.deposit(500);
    s.compute_interest();
    s.display();
    return 0;
}