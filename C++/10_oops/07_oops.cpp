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

class B {
   public:
    int* num;

    //    Creating Constructor and assign the value of it.
    B(int* val) { num = val; }

    // Creating copy constructor and assign the value from obj.
    B(const B& obj) { num = obj.num; }

    ~B() { delete num; }
};

int main() {
    A a1;
    a1.num = 55;
    cout << "The value of a1's num is " << a1.num << endl;
    // Creating another object using a1
    // Copy constructor calling
    A a2(a1);
    cout << "The value of a2's num is " << a1.num << endl;

    // Dynamic Allocation of an object.
    int* num = new int(55);

    B* obj1 = new B(num);
    cout << "Obj1's num is " << *(obj1->num) << endl;

    // Using copy constructor
    B obj2(*obj1);

    cout << "obj'2 num is " << *(obj2.num) << endl;

    cout << "Printing Address " << endl;
    cout << "Address of obj'1 num is " << obj1->num << endl;
    cout << "Address of obj'2 num is " << obj2.num << endl;

    delete obj1;

    cout << "obj'2 num is " << *(obj2.num) << endl;
    return 0;
}