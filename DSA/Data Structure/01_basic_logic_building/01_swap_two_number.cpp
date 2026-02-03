#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main() {
    int a = 12;
    int b = 22;

    cout << "Before Swap" << endl;
    cout << "A:- " << a << " B:- " << b << endl;

    swap(a, b);

    cout << "After Swap" << endl;
    cout << "A:- " << a << " B:- " << b << endl;
    return 0;
}