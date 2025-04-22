#include <iostream>
using namespace std;

class Student {
    string name;
public:
    Student() : name("Unknown") {}
    Student(string n) : name(n) {}
    void display() { cout << "Name: " << name << endl; }
};

int main() {
    Student s1;
    Student s2("John");
    s1.display(); // Unknown
    s2.display(); // John
    return 0;
}