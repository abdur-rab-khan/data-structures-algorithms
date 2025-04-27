#include <iostream>
using namespace std;

class A {
   protected:
    int a;
    int b;

   public:
    A(int a, int b) {
        this->a = a;
        this->b = b;
    }

    virtual void display() {
        cout << "Base Class Called \n";
        cout << "A " << this->a << endl;
        cout << "B " << this->b << endl;
    }
};

class B : public A {
   public:
    //    Call Constructor to initialize (int a, int b) and add them into parent class.
    B(int x, int y) : A(x, y) {}

    void display() override {
        cout << "Derived Class Called \n";
        cout << "A " << a << endl;
        cout << "B " << b << endl;
    }
};

int main() {
    // A* ptr = new B(5, 5);

    // ptr->display();
    A* a1;
    B b1(5, 5);

    a1 = &b1;

    a1->display();
    return 0;
}