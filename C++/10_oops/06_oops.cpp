#include <iostream>
using namespace std;

class Base {
   public:
    Base() { cout << "Base Class Constructor is called " << endl; }
    int size;
};

class Derived : public Base {
   public:
    Derived() {
        cout << "Derived Class Constructor is called " << endl;
        Base::size = 55;
    }
};

class A : public Base {
    //  Compiler define a default constructor of Base.
    // and inserts stub to call A constructor
    // Compiler won't be initialize any data on Base Class
};

class B : public Base {
   public:
    B() {  // User defined default constructor of B
        // Compiler insert stub to call Base's constructor
        cout << "B constructor " << endl;
        // Compiler won't be initialize any data of Base
    }
};

int main() {
    Derived d1;
    A a1;
    B b1;

    cout << d1.size << endl;
    return 0;
}