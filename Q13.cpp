#include <iostream>
using namespace std;

class Marks {
protected:
    int roll;
    string name;
    double marks;
    static int rollCounter;
public:
    Marks(string n, double m) : name(n), marks(m) {
        roll = ++rollCounter;
    }
    virtual double getMarks() { return marks; }
};
int Marks::rollCounter = 0;

class Physics : public Marks {
public:
    Physics(string n, double m) : Marks(n, m) {}
};

class Chemistry : public Marks {
public:
    Chemistry(string n, double m) : Marks(n, m) {}
};

class Mathematics : public Marks {
public:
    Mathematics(string n, double m) : Marks(n, m) {}
};

int main() {
    Physics p("Alice", 90);
    Chemistry c("Bob", 85);
    Mathematics m("Charlie", 95);
    cout << "Physics Marks: " << p.getMarks() << endl;
    return 0;
}