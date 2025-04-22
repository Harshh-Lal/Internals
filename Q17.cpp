#include <iostream>
#include <string>
using namespace std;

// Base class RBI
class RBI {
public:
    static const float MIN_INTEREST_RATE;
    static const float MIN_BALANCE;
    static const float MAX_WITHDRAWAL_LIMIT;

    // Display RBI guidelines
    static void displayGuidelines() {
        cout << "\nRBI Guidelines:" << endl;
        cout << "Minimum Interest Rate: " << MIN_INTEREST_RATE << "%" << endl;
        cout << "Minimum Balance Allowed: Rs " << MIN_BALANCE << endl;
        cout << "Maximum Withdrawal Limit: Rs " << MAX_WITHDRAWAL_LIMIT << endl;
    }
};

const float RBI::MIN_INTEREST_RATE = 4.0;
const float RBI::MIN_BALANCE = 1000.0;
const float RBI::MAX_WITHDRAWAL_LIMIT = 50000.0;

// Base class for Account
class Account {
protected:
    float balance;
    string accountNumber;
    string accountType;

public:
    Account(string accountNum, float initialBalance) {
        accountNumber = accountNum;
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
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: Rs " << balance << endl;
    }

    virtual void applyInterest() = 0;  // Pure virtual function for interest application
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(string accountNum, float initialBalance, float rate)
        : Account(accountNum, initialBalance) {
        accountType = "Savings";
        if (rate >= RBI::MIN_INTEREST_RATE) {
            interestRate = rate;
        } else {
            interestRate = RBI::MIN_INTEREST_RATE;
            cout << "Interest rate is below RBI's minimum, using default rate of " << RBI::MIN_INTEREST_RATE << "%" << endl;
        }
    }

    void applyInterest() override {
        float interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest of Rs " << interest << " applied. New balance: Rs " << balance << endl;
    }
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(string accountNum, float initialBalance) : Account(accountNum, initialBalance) {
        accountType = "Current";
    }

    void withdraw(float amount) override {
        if (amount <= balance && amount <= RBI::MAX_WITHDRAWAL_LIMIT) {
            balance -= amount;
            cout << "Withdrew Rs " << amount << ". Current balance: Rs " << balance << endl;
        } else if (amount > RBI::MAX_WITHDRAWAL_LIMIT) {
            cout << "Withdrawal limit exceeded! Max limit is Rs " << RBI::MAX_WITHDRAWAL_LIMIT << endl;
        } else {
            cout << "Insufficient funds! Current balance: Rs " << balance << endl;
        }
    }

    void applyInterest() override {
        cout << "Current account does not accrue interest." << endl;
    }
};

// Customer Class
class Customer {
private:
    string name;
    string customerID;
    Account* account;  // Pointer to Account

public:
    Customer(string customerName, string id, Account* acc) : name(customerName), customerID(id), account(acc) {}

    void deposit(float amount) {
        account->deposit(amount);
    }

    void withdraw(float amount) {
        account->withdraw(amount);
    }

    void displayAccountDetails() {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        account->displayBalance();
    }

    void applyInterest() {
        account->applyInterest();
    }
};

// Derived class for SBI Bank
class SBI : public RBI {
private:
    string bankName;

public:
    SBI() : bankName("State Bank of India") {}

    void displayBankDetails() {
        cout << "Bank: " << bankName << endl;
    }
};

// Derived class for ICICI Bank
class ICICI : public RBI {
private:
    string bankName;

public:
    ICICI() : bankName("ICICI Bank") {}

    void displayBankDetails() {
        cout << "Bank: " << bankName << endl;
    }
};

// Derived class for PNB Bank
class PNB : public RBI {
private:
    string bankName;

public:
    PNB() : bankName("Punjab National Bank") {}

    void displayBankDetails() {
        cout << "Bank: " << bankName << endl;
    }
};

int main() {
    // Display RBI Guidelines
    RBI::displayGuidelines();

    // Creating Customer objects
    SBI sbiBank;
    Customer customer1("John Doe", "C001", new SavingsAccount("SA12345", 5000, 5));
    customer1.displayAccountDetails();
    customer1.deposit(1500);
    customer1.withdraw(3000);
    customer1.applyInterest();
    sbiBank.displayBankDetails();

    ICICI iciciBank;
    Customer customer2("Jane Smith", "C002", new CurrentAccount("CA12345", 10000));
    customer2.displayAccountDetails();
    customer2.deposit(2000);
    customer2.withdraw(5000);
    customer2.applyInterest();
    iciciBank.displayBankDetails();

    PNB pnbBank;
    Customer customer3("Alice Johnson", "C003", new SavingsAccount("SA67890", 8000, 4));
    customer3.displayAccountDetails();
    customer3.deposit(2500);
    customer3.withdraw(1500);
    customer3.applyInterest();
    pnbBank.displayBankDetails();

    return 0;
}