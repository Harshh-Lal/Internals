#include <iostream>
using namespace std;

class Vehicle {
protected:
    double mileage;
    double price;
public:
    Vehicle(double m, double p) : mileage(m), price(p) {}
};

class Car : public Vehicle {
protected:
    double ownershipCost;
    int warranty;
    int seating;
    string fuelType;
public:
    Car(double m, double p, double oc, int w, int s, string f)
        : Vehicle(m, p), ownershipCost(oc), warranty(w), seating(s), fuelType(f) {}
};

class Audi : public Car {
    string model;
public:
    Audi(double m, double p, double oc, int w, int s, string f, string mod)
        : Car(m, p, oc, w, s, f), model(mod) {}
    void print() {
        cout << "Audi Model: " << model << "\nMileage: " << mileage << "\nPrice: $" << price << endl;
    }
};

int main() {
    Audi a(15.5, 50000, 55000, 5, 5, "Petrol", "A4");
    a.print();
    return 0;
}