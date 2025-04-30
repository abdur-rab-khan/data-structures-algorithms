#include <iostream>
using namespace std;

// Base class that is to be inherited
class Parent {
   public:
    int id_p;
    Parent(int x = 22) : id_p(x) {}
    void printID_p() { cout << "Base ID: " << id_p << endl; }
};

// Derived publicly inheriting from Base
// Class
class Child : public Parent {
   public:
    int id_c;
    Child(int x = 22) : id_c(x) {}
    void printID_c() { cout << "Child ID: " << id_c << endl; }
};

int main() {
    Child obj1;

    // An object of class child has all data members
    // and member functions of class parent
    // so we try accessing the parents method and data from
    // the child class object.
    obj1.id_p = 7;
    obj1.printID_p();

    // finally accessing the child class methods and data
    // too
    obj1.id_c = 91;
    obj1.printID_c();
    return 0;
}
