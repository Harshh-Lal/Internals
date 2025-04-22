#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int code;
public:
    Person(string n, int c) : name(n), code(c) {}
    virtual void display() {
        cout << "Name: " << name << "\nCode: " << code << endl;
    }
};

class Account : virtual public Person {
protected:
    double pay;
public:
    Account(string n, int c, double p) : Person(n, c), pay(p) {}
    void updatePay(double p) { pay = p; }
    void display() override {
        Person::display();
        cout << "Pay: $" << pay << endl;
    }
};

class Admin : virtual public Person {
protected:
    int experience;
public:
    Admin(string n, int c, int e) : Person(n, c), experience(e) {}
    void updateExp(int e) { experience = e; }
    void display() override {
        Person::display();
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Master : public Account, public Admin {
public:
    Master(string n, int c, double p, int e) 
        : Person(n, c), Account(n, c, p), Admin(n, c, e) {}
    void display() override {
        Account::display();
        Admin::display();
    }
};

int main() {
    Master m("John", 123, 75000, 8);
    m.display();
    m.updatePay(80000);
    m.updateExp(9);
    m.display();
    return 0;
}