/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       FACTORS                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Factor mean a number who completely divides without any remainder, example 2 is the factor of 4 because 2 divides 4 without any remainder      |
|                                                                                                                                                   |
| 🔶 Every number have at-least two factors:                                                                                                        |
|    🔸 By Itself                                                                                                                                   |
|    🔸 By 1                                                                                                                                        |
|                                                                                                                                                   |
| ⭐ KEY TAKEAWAY                                                                                                                                   |
|                                                                                                                                                   |
|    🔸 If 2 is the factor of 6, mean 100% (6 / 2 = 3) is also be a factor of 6                                                                     |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>

using namespace std;

namespace factor {
    // Brute force -- method
    void bFindFactor(int n) {
        vector<int> factors;

        factors.push_back(1);  // 1 will be the factor of all number.

        for (int i = 2; i <= n; i++) {
            // If number is equal to n.
            if (i == n) {
                factors.push_back(n);
                break;
            }

            // If it's completely divisible by n -- it's factor.
            if (n % i == 0) {
                factors.push_back(i);
            }
        }

        // Looping through all founded factors
        cout << "Factors of " << n << " are: ";
        for (const int& f : factors) {
            cout << f << " ";
        }
        cout << endl;
    }

    // Using square root method
    void sFindFactor(int n) {
        vector<int> factors;

        for (int i = 1; i * i <= n; i++) {
            // If n is competently divisible by i -- it's a factor and n / i will also
            // be a factor.
            if (n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
            }
        }

        // Looping through all founded factors
        cout << "Factors of " << n << " are: ";
        for (const int& f : factors) {
            cout << f << " ";
        }
        cout << endl;
    }

    // Calling all factors
    void main() {
        // Using brute force method
        bFindFactor(12);

        // Using efficient method
        sFindFactor(3);
    }
}  // namespace factor

void mainFunc() {
    factor::main();  // Calling factor
}

int main() {
    mainFunc();
    return 0;
}
