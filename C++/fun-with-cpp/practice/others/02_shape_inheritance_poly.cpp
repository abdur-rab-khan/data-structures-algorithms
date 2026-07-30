#include <math.h>

#include <iostream>

using namespace std;

class Shape {
   public:
    virtual double area() = 0;
    virtual void printArea() = 0;  // enforce derived to define
    virtual ~Shape() {}            // virtual destructor
};

class Rectangle : public Shape {
    double length;
    double width;

   public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override { return length * width; }
    void printArea() { cout << "Area of Rectangle is " << area() << endl; }
};

class Circle : public Shape {
    double radius;
    const double pi = 3.1415;

   public:
    Circle(double r) : radius(r) {}
    double area() override { return pi * pow(radius, 2); }
    void printArea() { cout << "Area of a circle is " << area() << endl; }
};

int main() {
    Shape* circle1 = new Circle(2.2);
    Shape* rect1 = new Rectangle(25.5, 30.67);

    circle1->printArea();
    rect1->printArea();

    delete circle1;
    delete rect1;
    return 0;
}