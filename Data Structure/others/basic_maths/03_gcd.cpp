#include <iostream>
using namespace std;

/*
    >> GCD of two number is the greater common divisor that divide both numbers.
    >> Example: 8, 18

    8 = 2, 4, 8,
    18 = 2, 6, 9

    GCD WILL >> 2
*/

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
    cout << endl << "GCD " << findGCDEuclid(11, 13);
    return 0;
}