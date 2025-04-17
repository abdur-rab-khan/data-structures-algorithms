#include <iostream>
using namespace std;

int* getDanglingPointer() {
    int num = 42;

    return &num;
}

int main() {
    int* x = new int(11);

    delete x;

    *x = 52;

    cout << "Value is::- " << *x << endl;

    int* danglingPtr = getDanglingPointer();

    cout << danglingPtr << endl;
    return 0;
}