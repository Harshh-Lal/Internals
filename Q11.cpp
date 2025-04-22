#include <iostream>
using namespace std;

class Mammals {
public:
    void print() { cout << "I am mammal" << endl; }
};

class MarineAnimals {
public:
    void print() { cout << "I am a marine animal" << endl; }
};

class BlueWhale : public Mammals, public MarineAnimals {
public:
    void print() { cout << "I belong to both categories" << endl; }
};

int main() {
    Mammals m;
    MarineAnimals ma;
    BlueWhale bw;
    m.print();        // I am mammal
    ma.print();       // I am a marine animal
    bw.print();       // I belong to both
    bw.Mammals::print();  // I am mammal
    bw.MarineAnimals::print(); // I am marine animal
    return 0;
}