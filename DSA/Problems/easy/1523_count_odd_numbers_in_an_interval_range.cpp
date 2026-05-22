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
int countOdds(int low, int high) {
    low = low == 0 ? low : low - 1;

    auto f = [](int n) { return n / 2 + (n % 2 == 0 ? 0 : 1); };

    return f(high) - f(low);
}

int main() {
    cout << "Total odds between 1 and 7 is: " << countOdds(1, 7) << endl;
    cout << "Total odds between 1 and 5 is: " << countOdds(1, 5) << endl;
    cout << "Total odds between 2 and 8 is: " << countOdds(2, 8) << endl;

    return 0;
}