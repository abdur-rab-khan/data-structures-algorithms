#include <functional>
#include <iostream>
using namespace std;

int multiply(int a, int b) {
    return a * b;
};

int calculate(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

void add() {
    cout << "Add is called" << endl;
}

void remove() {
    cout << "Remove is called" << endl;
}

void update() {
    cout << "Update is called" << endl;
}

int main() {
    int (*funcPtr)(int, int) = multiply;

    // Count function does not know how to print function pointer that is the reason they can't
    // print the address.
    printf("Memory Address of this function:- %p", funcPtr);
    cout << endl << "Memory Address of this function:- " << (int*)funcPtr << endl;
    cout << "Memory Address of this function:- " << reinterpret_cast<void*>(funcPtr) << endl
         << endl;

    cout << "The Multiplication of 2 x 2 is:- " << funcPtr(2, 2) << endl;
    cout << "The Multiplication of 4 x 4 is:- " << calculate(4, 4, funcPtr) << endl;

    void (*main[])() = {add, remove, update};

    int choice = 0;

    main[choice]();

    // Using std::function with lambda
    function<int(int, int)> func;

    func = multiply;

    cout << func(10, 10) << endl;
    return 0;
}