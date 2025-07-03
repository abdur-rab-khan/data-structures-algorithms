#include <iostream>
using namespace std;

void findGCD(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << "GCD of " << "(" << a << ", " << b << ")" << " is " << i;
            break;
        }
    }
}

// Using Euclid's Algorithms
int findGCDEuclid(int a, int b) {
    if (a < b)
        return a;

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    if (a == b)
        return a;

    return findGCDEuclid(a - b, b);
}

int main() {
    findGCD(9, 6);
    cout << endl << "GCD " << findGCDEuclid(9, 6);
    return 0;
}