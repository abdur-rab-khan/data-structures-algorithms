#include <bits/stdc++.h>
using namespace std;

int fibonacciN(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return (fibonacciN(n - 1) + fibonacciN(n - 2));
}

int main() {
    int n = 8;

    cout << "Fibonacci of " << n << " is: " << fibonacciN(n) << endl;

    return 0;
}