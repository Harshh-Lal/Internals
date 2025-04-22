#include <iostream>
using namespace std;

class DB; // Forward declaration

class DM {
    float meters;
    float centimeters;

public:
    DM() : meters(0), centimeters(0) {}

    DM(float m, float cm) : meters(m), centimeters(cm) {}

    void getData() {
        cout << "Enter distance in meters and centimeters:\n";
        cout << "Meters: "; cin >> meters;
        cout << "Centimeters: "; cin >> centimeters;
    }

    void display() const {
        cout << "Distance: " << meters << " meters " << centimeters << " centimeters\n";
    }

    friend DM addDistance(const DM& d1, const DB& d2); // Friend function
};

class DB {
    float feet;
    float inches;

public:
    DB() : feet(0), inches(0) {}

    DB(float f, float in) : feet(f), inches(in) {}

    void getData() {
        cout << "Enter distance in feet and inches:\n";
        cout << "Feet: "; cin >> feet;
        cout << "Inches: "; cin >> inches;
    }

    void display() const {
        cout << "Distance: " << feet << " feet " << inches << " inches\n";
    }

    friend DM addDistance(const DM& d1, const DB& d2); // Friend function
};

// Friend function to add distances and return in DM (meters & centimeters)
DM addDistance(const DM& d1, const DB& d2) {
    // Convert both to centimeters
    float dmTotalCm = d1.meters * 100 + d1.centimeters;
    float dbTotalCm = d2.feet * 30.48 + d2.inches * 2.54;

    float totalCm = dmTotalCm + dbTotalCm;

    float meters = int(totalCm / 100);
    float centimeters = totalCm - (meters * 100);

    return DM(meters, centimeters);
}

int main() {
    DM metric;
    DB imperial;

    metric.getData();
    imperial.getData();

    DM result = addDistance(metric, imperial);

    cout << "\n--- Result (in Metric) ---\n";
    result.display();

    return 0;
}