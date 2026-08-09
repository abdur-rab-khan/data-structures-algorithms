
#include "../../dsa_utils.h"

using namespace std;

/*
 * To solve the problem, We need to know about "Digital Root", it's the final single digit
 * we get after repeatedly finding the "digit sum" — where we sum the digits one by one
 * until it become single digit like this:
 *     🔸 "256" = 2 + 5 + 6 = 13
 *     🔸 "13" = 1 + 3 = 4
 *
 * But, there is trick to solve without doing one by one using loops or recursion, So the trick is number "9", So if you try to find remainder of base 10 like "1 % 9 = 1", "10 % 9 = 1", "100 % 9 = 1",
 * Which means If we find remainder of 256 or 2 + 5 + 6 will be the same because of it, that's why we can easily find the digits sum.
 *
 * But digital root only goes from 1 to 9 (never 0, unless num itself is 0). So we fix the
 * case where num is a multiple of 9 — normally num % 9 gives 0 there, but digital root
 * should be 9 in that case.
 */
int addDigits(int num) {
    if (num == 0) {
        return 0;
    } else if (num % 9 == 0) {
        return 9;
    } else {
        return num % 9;
    }
}

int main() {
    print(addDigits(256), "The digits sum of 256 is: ");
    return 0;
}
