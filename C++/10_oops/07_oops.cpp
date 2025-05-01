#include <iostream>
using namespace std;

class A {
   public:
    int num;

    // To Copy constructor work we have to define constructor first.
    A() {}

    // Creating copy constructor.
    A(const A& obj) {
        cout << "Copy contractor is called " << endl;
        num = obj.num;
    }
};

int main() {
    A a1;
    a1.num = 55;
    cout << "The value of a1's num is " << a1.num << endl;
    cout << "Address of a1's num is " << &(a1.num) << endl;

    // Creating another object using a1
    // Copy constructor calling
    A a2(a1);
    cout << "The value of a2's num is " << a1.num << endl;
    cout << "Address of a2's num is " << &(a2.num) << endl;
    return 0;
}