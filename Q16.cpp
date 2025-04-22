#include <iostream>
#include <string>
using namespace std;

// Class to represent RBI guidelines
class RBI {
public:
    static const float MIN_INTEREST_RATE;
    static const float MIN_BALANCE;
    static const float MAX_WITHDRAWAL_LIMIT;

    // Static constants representing RBI guidelines
    static void displayGuidelines() {
        cout << "RBI Guidelines:" << endl;
        cout << "Minimum Interest Rate: " << MIN_INTEREST_RATE << "%" << endl;
        cout << "Minimum Balance Allowed: Rs " << MIN_BALANCE << endl;
        cout << "Maximum Withdrawal Limit: Rs " << MAX_WITHDRAWAL_LIMIT << endl;
    }
};

const float RBI::MIN_INTEREST_RATE = 4.0;
const float RBI::MIN_BALANCE = 1000.0;
const float RBI::MAX_WITHDRAWAL_LIMIT = 50000.0;

// Base class representing a generic bank account
class BankAccount {
protected:
    string accountHolder;
    float balance;
    string accountType;

public:
    BankAccount(string holder, float initialBalance) {
        accountHolder = holder;
        balance = initialBalance;
    }

    virtual void deposit(float amount) {
        balance += amount;
        cout << "Deposited Rs " << amount << ". Current balance: Rs " << balance << endl;
    }

    virtual void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs " << amount << ". Current balance: Rs " << balance << endl;
        } else {
            cout << "Insufficient funds! Current balance: Rs " << balance << endl;
        }
    }

    void displayBalance() {
        cout << "Account holder: " << accountHolder << endl;
        cout << "Balance: Rs " << balance << endl;
    }

    virtual void applyInterest() = 0;  // Pure virtual function for applying interest
};

// Derived class for savings account
class SavingsAccount : public BankAccount {
private:
    float interestRate;

public:
    SavingsAccount(string holder, float initialBalance, float rate) 
        : BankAccount(holder, initialBalance) {
        accountType = "Savings";
        // Interest rate must be at least the minimum rate set by RBI
        if (rate >= RBI::MIN_INTEREST_RATE) {
            interestRate = rate;
        } else {
            interestRate = RBI::MIN_INTEREST_RATE;
            cout << "Interest rate is below the minimum allowed by RBI. Using default rate of " << RBI::MIN_INTEREST_RATE << "%" << endl;
        }
    }

    void applyInterest() override {
        float interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest of Rs " << interest << " applied. New balance: Rs " << balance << endl;
    }
};

// Derived class for current account
class CurrentAccount : public BankAccount {
private:
    static const float PENALTY;

public:
    CurrentAccount(string holder, float initialBalance) 
        : BankAccount(holder, initialBalance) {
        accountType = "Current";
    }

    void withdraw(float amount) override {
        if (amount <= balance && amount <= RBI::MAX_WITHDRAWAL_LIMIT) {
            balance -= amount;
            cout << "Withdrew Rs " << amount << ". Current balance: Rs " << balance << endl;
        } else if (amount > RBI::MAX_WITHDRAWAL_LIMIT) {
            cout << "Withdrawal limit exceeded! Max withdrawal limit is Rs " << RBI::MAX_WITHDRAWAL_LIMIT << endl;
        } else {
            cout << "Insufficient funds! Current balance: Rs " << balance << endl;
        }
    }

    void applyPenalty() {
        if (balance < RBI::MIN_BALANCE) {
            balance -= PENALTY;
            cout << "Balance is below the minimum required. Penalty of Rs " << PENALTY << " applied. New balance: Rs " << balance << endl;
        }
    }

    void applyInterest() override {
        cout << "Current account does not accrue interest." << endl;
    }
};

const float CurrentAccount::PENALTY = 50.0;  // Penalty for falling below minimum balance

int main() {
    // Display RBI guidelines
    RBI::displayGuidelines();

    // Creating a Savings account and applying interest
    SavingsAccount savings("John Doe", 5000, 5);
    savings.displayBalance();
    savings.applyInterest();

    // Creating a Current account, making a withdrawal and applying penalty if necessary
    CurrentAccount current("Alice Smith", 800);
    current.displayBalance();
    current.withdraw(2000);  // Exceeds balance
    current.applyPenalty();  // Apply penalty for below minimum balance

    // Depositing into the current account
    current.deposit(2000);
    current.withdraw(2000);  // Now it's within the balance
    current.applyPenalty();  // Apply penalty if balance falls below minimum

    return 0;
}