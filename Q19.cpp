#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float breadth;

public:
    // Constructor 1: No parameters
    Rectangle() {
        length = 0;
        breadth = 0;
    }

    // Constructor 2: Two parameters (length and breadth)
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    // Constructor 3: One parameter (both length and breadth are the same)
    Rectangle(float side) {
        length = side;
        breadth = side;
    }

    // Function to calculate area
    float calculateArea() {
        return length * breadth;
    }
};

int main() {
    // Creating object with no parameters (length and breadth default to 0)
    Rectangle rect1;
    cout << "Area of Rectangle with no parameters: " << rect1.calculateArea() << endl;

    // Creating object with two parameters (length and breadth specified)
    Rectangle rect2(5.0, 3.0);
    cout << "Area of Rectangle with length 5 and breadth 3: " << rect2.calculateArea() << endl;

    // Creating object with one parameter (both length and breadth are the same)
    Rectangle rect3(4.0);
    cout << "Area of Square (both sides 4): " << rect3.calculateArea() << endl;

    return 0;
}