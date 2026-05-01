#include <bits/stdc++.h>

#include <cassert>
using namespace std;

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
