#include <bits/stdc++.h>
using namespace std;

/*
    * Okay, So the intuition behind this question is, between a to n there will n / 2 even or odd, because see the following:
        1 - 1 = 1
        1 - 2 = 1
        1 - 3 = 2
        1 - 4 = 2
        1 - 5 = 3
        1 - 6 = 3

        👉 See the pattern, After every two number number of odds increase by 2 means if we want to find odds between a to n will be n / 2, ""6 / 2 = 3"" --> But with ""5 / 2 = 2"" So if n is odd we need to add by 1.

    To find odds between 4 to 10, We'll find odds between 1 to 10 and 1 to 3 then we'll minus the odds between 1 to 10 with 1 to 3.
*/

// Counting how many odd numbers are exists between a range [low, high]
// Uses a prefix-count formula countOddsUpto(high) - countOddsUpto(low - 1);
int countOdds(int low, int high) {
    // Count odd numbers from 1 to num
    // Working by round off the number, So from 1 - 4 (there will be 4 / 2 -> odds)
    // If "high" is even it will give perfect number of odds/even but if it's odd than we have to make them even by increasing.
    auto countOddsUpto = [](int num) -> int {
        if (num <= 0) {
            return 0;
        }

        const int nearestEven = (num % 2 == 0) ? num : num + 1;
        return nearestEven / 2;
    };

    // Adjust low, So that always we get a minimum range 1 to n;
    const int adjustedLow = (low <= 0) ? 1 : low;
    return countOddsUpto(high) - countOddsUpto(adjustedLow - 1);
}

int main() {
    cout << "Total odds between 1 and 7 is: " << countOdds(1, 7) << endl;
    cout << "Total odds between 1 and 5 is: " << countOdds(1, 5) << endl;
    cout << "Total odds between 2 and 8 is: " << countOdds(2, 8) << endl;

    return 0;
}