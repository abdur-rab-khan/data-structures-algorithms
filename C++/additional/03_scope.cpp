#include <iostream>

// #include "01_namespace.cpp"
using namespace std;

namespace first_namespace {
    void display(void* value, char type) {
        if (type == 'I') {
            cout << *(static_cast<int*>(value)) << endl;
        } else {
            cout << *(static_cast<string*>(value)) << endl;
        }
    }
}  // namespace first_namespace

namespace Math {
    namespace Addition {
        int addition(int a, int b) {
            return a + b;
        }
        int addition(int a, int b, int c) {
            return a + b + c;
        }
    }  // namespace Addition

    namespace Multiplication {
        int multi(int a, int b) {
            return a * b;
        }

        int multi(int a, int b, int c) {
            return a * b * c;
        }
    }  // namespace Multiplication
}  // namespace Math

namespace A {
    class B {
       public:
        int a = 5;
        int b = 10;

        void add() { cout << "A + B " << a + b << endl; }

        void multi() { cout << "A x B " << a * b << endl; }
    };
}  // namespace A
// using first_namespace::display;  // We can also get single things from namespace
using namespace first_namespace;
using namespace Math::Addition;

int main() {
    /*
        {
            int age = 5;
            cout << age << endl;
        }
    */

    // cout << age << endl; // Causing error value not defined.

    // NameSpace Scope
    int age = 21;
    string name = "Abdur Rab Khan";
    first_namespace::display(&age, 'I');
    first_namespace::display(&name, 'S');

    display(&name, 'S');

    // Nested Namespace;
    cout << (Math::Multiplication::multi(4, 4)) << endl;
    cout << (Math::Multiplication::multi(4, 4, 4)) << endl;

    cout << addition(4, 4) << endl;

    A::B obj;

    obj.add();
    obj.multi();

    cout << foo::getValue() << endl;
    return 0;
}