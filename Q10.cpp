#include <iostream>
using namespace std;

class Employee {
    int age, yearsOfService;
    double salary;
public:
    Employee(int a, int y, double s) : age(a), yearsOfService(y), salary(s) {}
    int getAge() const { return age; }
    int getYOS() const { return yearsOfService; }
    double getSalary() const { return salary; }
    void setAge(int a) { age = a; }
    void setYOS(int y) { yearsOfService = y; }
    void setSalary(double s) { salary = s; }
    int salaryInThousands() { return static_cast<int>(salary / 1000 + 0.5); }
};

int main() {
    Employee emp1(30, 5, 75000);
    Employee emp2(25, 2, 50000);
    cout << "Emp1 Salary: " << emp1.salaryInThousands() << "k" << endl; // 75k
    return 0;
}