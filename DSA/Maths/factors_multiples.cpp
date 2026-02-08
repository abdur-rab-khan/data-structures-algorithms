/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       FACTORS                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 "b" will be the factor of "a" if "b" completely divisible by "a". Without any "remainder" or "decimal". (a % b) == 0.                          |
|                                                                                                                                                   |
| 🟡 Factors are always smaller or equal to the number.                                                                                             |
|                                                                                                                                                   |
| 🟡 Every number has atleast two factors:                                                                                                          |
|    1. Itself                                                                                                                                      |
|    2. By 1                                                                                                                                        |
|                                                                                                                                                   |
| ⭐ KEY TAKEAWAY                                                                                                                                   |
|                                                                                                                                                   |
|    1. To find factors, We don't have to find check till n, So important thing is "if 2 is the factor if 6, then ( 6 / 2 = 3 ), 3 will also be a   |
|       factor of 6". So we can find till √6 instead of "n", it's save time and make algorithm more efficient.                                      |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       MULTIPLES                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 A "multiple" is the result of multiplying a number, It goes forward not backward.                                                              |
|                                                                                                                                                   |
| 🟡 Multiples are usually greater than the number. They can go to infinity.                                                                        |
|                                                                                                                                                   |
| 🟦 4 -> 4, 8, 12, 16, 20                                                                                                                          |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     PRIME NUMBERS                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 "a" is a PRIME NUMBER, If it's divisible by "1" or "itself". Means if a number has more than two factors, It can't be a prime number.          |
|                                                                                                                                                   |
| 🟦 PRIME NUMBER -> (2, 3, 5, 7, 11), NOT PRIME NUMBER [4 (factors) -> (1, 2, 4), 6 (factors) -> (1, 2, 4, 6)].                                    | 
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                            GCD or HCF (GREATEST COMMON DIVISOR)                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 "k" is the GCD of "a" and "b", If in the factor of both "a"  and "b", "k" is common and latest. GCD is the largest number that divides        |
|     both numbers.                                                                                                                                 |
|                                                                                                                                                   |
|     🟦 Factor of 12 ("a") -> 1, 2, 3, 4, [6], 12                                                                                                  |
|                                                                                                                                                   |
|     🟦 Factor of 18 ("b") -> 1, 2, 3, [6], 9, 18                                                                                                  |
|                                                                                                                                                   |
| 🟡 "6" is the GCD of "12" and "18"                                                                                                                |
|                                                                                                                                                   |
| ⭐ Best way to find GCD is using "Euclidean Algorithm --> gcd(a, b) = gcd(b, a % b)"                                                              |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                              LCM (LEAST COMMON MULTIPLE)                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 "k" is the LCM of "a" and "b", If in the multiple of both "a" and "b", "k" is common and smallest. GCD is the smallest number divisible by     |
|     both numbers.                                                                                                                                 |
|                                                                                                                                                   |
|     🟦 Multiple of 4 ("a") -> 4, 18, 12, 16, 20 ....                                                                                              |
|                                                                                                                                                   |
|     🟦 Multiple of 6 ("b") -> 6, 12, 18 ...                                                                                                       |
|                                                                                                                                                   |
| 🟡 "12" is the LCM of "4" and "6".                                                                                                                |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

// Finding factors
namespace factor {
    // Brute force -- method
    void bFindFactor(int n) {
        vector<int> factors;

        factors.push_back(1); // 1 will be the factor of all number.

        for(int i = 2; i <= n; i++){
            // If number is equal to n.
            if(i == n) {
                factors.push_back(n);
                break;
            }

            // If it's completely divisible by n -- it's factor.
            if(n % i == 0){
                factors.push_back(i);
            }
        }

        // Looping through all founded factors
        cout << "Factors are: ";
        for(const int& f: factors){
            cout << f << " ";
        }
        cout << endl;
    }

    // Using square root method
    void sFindFactor(int n) {
        vector<int> factors;

        for(int i = 1; i * i <= n; i++) {
            // If n is competently divisible by i -- it's a factor and n / i will also be a factor. 
            if(n % i == 0){
                factors.push_back(i);
                factors.push_back(n / i);
            }
        }

        // Looping through all founded factors
        cout << "Factors are: ";
        for(const int& f: factors){
            cout << f << " ";
        }
        cout << endl;
    }

    // Calling all factors
    void main() {
        // Using brute force method
        bFindFactor(12);
    
        // Using efficient method
        sFindFactor(12);
    }
}

int main() {
    factor::main(); // Calling factor

    return 0;
}