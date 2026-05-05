#include <bits/stdc++.h>

#include <cassert>
using namespace std;

/**
 * Counts the number of set bits (1s) in the binary representation of n.
 *
 * Uses Brian Kernighan's method: repeatedly clears the lowest set bit until
 * the number becomes zero.
 *
 * Example:
 * Input: n = 11 (1011b)
 * Output: 3
 *
 * Example:
 * Input: n = 128 (10000000b)
 * Output: 1
 *
 * Time Complexity: O(k) - k is the number of set bits (at most 32 for int)
 * Space Complexity: O(1)
 *
 * @param n Non-negative integer input
 * @return Count of set bits in n
 */
int countSetBits(int n) {
    int count = 0;

    while (n > 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}

int testCount = 1;
void submitForTesting(int n, int expected) {
    int setBits = countSetBits(n);

    assert(setBits == expected);
    cout << "Test no. " << testCount << " is successful " << endl;
    testCount++;
}

int main() {
    submitForTesting(11, 3);
    submitForTesting(2, 1);
    submitForTesting(128, 8);
    submitForTesting(2147483645, 30);

    return 0;
}
