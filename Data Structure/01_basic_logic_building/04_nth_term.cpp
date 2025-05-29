#include <iostream>
using namespace std;

int findNthTerm(int a1, int a2, int n) {
    int difference = a2 - a1, nth = a1;

    for (int i = 1; i < n; i++) {
        nth += difference;
    }

    return nth;
}

int nthTermofAp(int a, int b, int n) {
    int d = b - a;
    return (a + (n - 1) * d);
}

int main() {
    int a1 = 1, a2 = 3, n = 10;

    // Finding nth term
    int nth = findNthTerm(a1, a2, n);
    int nTerm = nthTermofAp(a1, a2, n);

    cout << "The nth term of " << a1 << ", " << a2 << " is " << nth << endl;
    cout << "The nth term of " << a1 << ", " << a2 << " is " << nTerm << endl;
    return 0;
}