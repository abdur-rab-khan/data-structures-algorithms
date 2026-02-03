#include <bits/stdc++.h>
using namespace std;

/*
    <======================> POWER NUMBER <======================>

    ◎ Given a number n, find the value of "n" raise to the power of it's own reverse.

    ◎ EXAMPLE:

    Input n = 2;
    Output: 4
    Explanation: The reverse of 2 is 2, 2² = 4

    Input n = 10;
    Output: 10
    Explanation: The reverse of 10 is 1, 10¹ = 10
*/

class Solution {
   public:
    int reverseExponentiation(int n) {
        int rev = reverseNum(n);

        return pow(n, rev);
    }

    int reverseNum(int n, int rev = 0) {
        if (n == 0)
            return rev;

        int tempRev = (rev * 10) + (n % 10);

        return reverseNum(n / 10, tempRev);
    }
};

int main() {
    Solution revEx;

    cout << revEx.reverseExponentiation(20);

    return 0;
}