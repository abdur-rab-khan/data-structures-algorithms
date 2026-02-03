#include <bits/stdc++.h>
using namespace std;

int sumNatural(int n) {
    if (n == 1)
        return 1;

    return n + sumNatural(n - 1);
}

int main() {
    int n = 5;
    cout << "Sum of " << n << " natural numbers: " << sumNatural(n);
    return 0;
}