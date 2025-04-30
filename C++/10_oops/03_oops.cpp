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

    virtual void print() {}
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

    void print() override { cout << "Printing from base class" << endl; }
};

int main() {
    // A* ptr = new B(5, 5);

    // ptr->display();
    A* ptr = nullptr;
    B b1(5, 5);
    ptr = &b1;

    ptr->display();

    // Address of baseptr
    A* objectPtr = ptr;

    // Address of vptr
    void** vptr = *(void***)ptr;

    // Function pointer type (which expects A* as the parameter)
    typedef void (*FuncType)(A*);

    // Get the vtable function pointer (points to B::display)
    FuncType func1 = (FuncType)vptr[0];  // vptr[0] is the address of B::display()
    FuncType func2 = (FuncType)vptr[1];
    // Call the function via function pointer, passing `ptr` as the argument
    func1(ptr);  // Same as calling ptr->display()
    func2(ptr);

    return 0;
}