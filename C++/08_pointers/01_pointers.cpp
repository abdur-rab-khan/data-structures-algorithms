#include <iostream>
using namespace std;

void update(int* ptr) {
    *ptr = 12121;
}

int main() {
    int x = 55;
    int* ptr = &x;

    cout << ptr << endl;  // Memory address of variable x.

    cout << *ptr << endl;  // Getting the value from memory address.

    *ptr = 66;  // We change the value from memory address of x.

    cout << x << endl;

    // Using pointer in fuction.
    update(&x);

    cout << x << endl;
    return 0;
}