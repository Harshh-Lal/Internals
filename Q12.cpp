#include <iostream>
using namespace std;

class Fruit {
protected:
    static int totalFruits;
public:
    Fruit() { totalFruits++; }
    static int getTotal() { return totalFruits; }
};
int Fruit::totalFruits = 0;

class Apples : public Fruit {
    static int count;
public:
    Apples() { count++; }
    static int getCount() { return count; }
};
int Apples::count = 0;

class Mangoes : public Fruit {
    static int count;
public:
    Mangoes() { count++; }
    static int getCount() { return count; }
};
int Mangoes::count = 0;

int main() {
    Apples a1, a2;
    Mangoes m1;
    cout << "Apples: " << Apples::getCount() << endl; // 2
    cout << "Mangoes: " << Mangoes::getCount() << endl; // 1
    cout << "Total: " << Fruit::getTotal() << endl; // 3
    return 0;
}