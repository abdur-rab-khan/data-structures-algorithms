// #include <iostream>

// using namespace std;

// class Test {
//    public:
//     // Constructor is created
//     Test() { cout << "Constructor is called" << endl; }

//     // Destructor is created
//     ~Test() { cout << "Destructor is called" << endl; }
// };

// int main() {
//     Test t1;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A {
//    public:
//     int* num;

//     A(int value) { num = new int(value); }

//     ~A() {
//         cout << "Destructor is called " << endl;
//         delete num;
//     }
// };

// int main() {
//     A* a1 = new A(55);

//     cout << "a1's num is " << *(a1->num) << endl;

//     delete a1;

//     cout << "After deleting " << endl;
//     cout << "a1's num is " << *(a1->num) << endl;
//     return 0;
// }

// Private Destructor
// #include <iostream>
// using namespace std;

// class Test {
//    private:
//     ~Test() {}

//    public:
//     friend void friendDestructor(Test* ptr) { delete ptr; }
// };

// int main() {
//     // Test t1; ⚠️ Error: Compiler try to find destructor, and there is no destructor.
//     Test* t1 = new Test();  // ✅ Here perfectly working, Because of dynamic allocation
//     // destructor is not call unless we delete the object.

//     friendDestructor(t1);
//     return 0;
// }

#include <iostream>

using namespace std;

class parent {
   private:
    ~parent() { cout << "destructor called" << endl; }

   public:
    parent() { cout << "constructor called" << endl; }
    void destruct() { delete this; }
};

int main() {
    parent* p;
    p = new parent;
    // destructor called
    p->destruct();

    return 0;
}
