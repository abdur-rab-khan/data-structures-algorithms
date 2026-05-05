#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 "o(log n)"
bool isPowerOfTwo1(int n) {
    if (n == 2)
        return true;

    if (n <= 0)
        return false;

    return isPowerOfTwo1(n / 2);
}

// APPROACH 2 "o(1)"
bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;

    return (n & n - 1) == 0;
}

// Test Cases
int testCount = 0;
void submitForTesting(int n, bool expected, bool (*fn)(int n)) {
    testCount++;
    bool checkPowerOfTwo = fn(n);

    assert(checkPowerOfTwo == expected);
    cout << "Test no. " << testCount << " is done." << endl;
}

int main() {
    submitForTesting(16, true, isPowerOfTwo1);
    submitForTesting(32, true, isPowerOfTwo1);
    submitForTesting(7, false, isPowerOfTwo1);
    submitForTesting(3, false, isPowerOfTwo1);

    submitForTesting(16, true, isPowerOfTwo);
    submitForTesting(32, true, isPowerOfTwo);
    submitForTesting(7, false, isPowerOfTwo);
    submitForTesting(3, false, isPowerOfTwo);

    return 0;
}