#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 "o(log n)"
/**
 * Checks if n is a power of two using recursion.
 *
 * Repeatedly divides n by 2 until it reaches 2 (power of two) or falls below
 * 1 (not a power of two).
 *
 * Example:
 * Input: n = 16
 * Output: true
 *
 * Example:
 * Input: n = 7
 * Output: false
 *
 * Time Complexity: O(log n) - One division per recursion level
 * Space Complexity: O(log n) - Call stack depth
 *
 * @param n Integer to check
 * @return True if n is a power of two, otherwise false
 */
bool isPowerOfTwo1(int n) {
    if (n == 2)
        return true;

    if (n <= 0)
        return false;

    return isPowerOfTwo1(n / 2);
}

// APPROACH 2 "o(1)"
/**
 * Checks if n is a power of two using bit manipulation.
 *
 * A power of two has exactly one set bit. The expression (n & (n - 1))
 * clears the lowest set bit, so it becomes zero only for powers of two.
 *
 * Example:
 * Input: n = 32
 * Output: true
 *
 * Example:
 * Input: n = 3
 * Output: false
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * @param n Integer to check
 * @return True if n is a power of two, otherwise false
 */
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