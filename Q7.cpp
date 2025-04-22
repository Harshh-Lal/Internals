#include <iostream>
using namespace std;

class SimpleCircle {
    int itsRadius;
public:
    SimpleCircle() : itsRadius(5) {}
    SimpleCircle(int r) : itsRadius(r) {}
    SimpleCircle(const SimpleCircle& other) : itsRadius(other.itsRadius) {}
    int getRadius() const { return itsRadius; }
    void setRadius(int r) { itsRadius = r; }
    SimpleCircle& operator++() { // Prefix
        ++itsRadius;
        return *this;
    }
    SimpleCircle operator++(int) { // Postfix
        SimpleCircle temp(*this);
        itsRadius++;
        return temp;
    }
    SimpleCircle& operator=(const SimpleCircle& other) {
        itsRadius = other.itsRadius;
        return *this;
    }
};

int main() {
    SimpleCircle c1;
    SimpleCircle c2(9);
    ++c1;
    c2++;
    cout << "c1: " << c1.getRadius() << endl; // 6
    cout << "c2: " << c2.getRadius() << endl; // 10
    c1 = c2;
    cout << "c1 after assignment: " << c1.getRadius() << endl; // 10
    return 0;
}