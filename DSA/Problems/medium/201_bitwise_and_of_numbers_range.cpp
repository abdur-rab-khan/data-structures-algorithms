#include <bits/stdc++.h>
using namespace std;

/*
    0 = 0000
    1 = 0001
    2 = 0010
    3 = 0011
    4 = 0100
    5 = 0101

-> Notic: Something, At every position from right to left the "0/1" frequency happen by 2's power
            mean.
            
            At first bit, see 0 -> 1 -> 0 -> 1 -> 0 (1)
            At second bit, see 0 -> 0 -> 1 -> 1 -> 0 -> 0 (2)
            At third bit, see 0 -> 0 -> 0 -> 0 -> 1 -> 1 -> 1 -> 1 (4)
            At fourth bit, see 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 1 (8)

-> This is the real intuition behind this is, If i got a range like (5, 7) mean at 3 bit we'll get the bit which are common.
    So that we can directly check when both numbers are common at that place we can say we got a position where every bits are common
    At that we'll construct AND bitwise number using the number and shift to right by how after how many iteration we got this.

*/

/*
* Lower bits keep flipping as numbers increase, so they always die in AND. Only the common high bits between left and right survive.

Approach:
    Shift both left and right right until they are equal, count the shifts.
    Shift back left by count to restore position.

Why it works:
    Once left == right, only the bits that were never different remain. Shifting back puts them in the correct position.

Complexity — Time: O(32) = O(1), Space: O(1)
*/

/*
Let's see using example:
    5 = 0 1 0 1
    7 = 1 1 1 0


    * Iteration 0:
        0 1 0 0 (left) <<= 1   👉 1 0 1 0
        1 1 1 0 (right) <<= 1  👉 1 1 1 0

    * Iteration 1:
        1 0 1 0 (left) <<= 1   👉 0 1 0 0
        1 1 0 0 (right) <<= 1  👉 1 1 0 0

    * Iteration 2:
        0 1 0 0 (left) <<= 1   👉 1 0 0 0
        1 1 0 0 (right) <<= 1  👉 1 0 0 0

    🟡 left == right ✅ -> Means only bits remain who is similar on both.

    🟡 left << 2 -> 1 0 0 0 ✅ Answer is four.
*/

int rangeBitwiseAnd(int left, int right) {
    int count = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }

    return left << count;
}

int testCount = 1;
void submitForTesting(int left, int right, int expected) {
    int output = rangeBitwiseAnd(left, right);

    assert(output == expected);
    cout << "Test case no. " << testCount << " is done" << endl;
    testCount++;
}

int main() {
    submitForTesting(5, 7, 4);
    submitForTesting(0, 0, 0);
    submitForTesting(1, 2147483647, 0);

    return 0;
}