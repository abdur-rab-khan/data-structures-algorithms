#include <bits/stdc++.h>
using namespace std;

int factorialN(int n) {
    if (n == 0)
        return 1;

    return n * factorialN(n - 1);
}

int main() {
    int n = 5;

    cout << "Factorial of " << n << " is: " << factorialN(n);

    return 0;
}