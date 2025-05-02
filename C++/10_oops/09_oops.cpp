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

#include <iostream>
using namespace std;

class A {
   public:
    int* num;

    A(int value) { num = new int(value); }

    ~A() {
        cout << "Destructor is called " << endl;
        delete num;
    }
};

int main() {
    A* a1 = new A(55);

    cout << "a1's num is " << *(a1->num) << endl;

    delete a1;

    cout << "After deleting " << endl;
    cout << "a1's num is " << *(a1->num) << endl;
    return 0;
}