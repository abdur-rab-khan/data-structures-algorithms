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
| 📒 If "b" is divisor of "a", then "a" will be the multiple of "b".                                                                                | 
|                                                                                                                                                   |
|     🟦 Factor of 12 ("a") -> 1, 2, 3, 4, 6, 12                                                                                                    |
|                                                                                                                                                   |
|     🟦 Factor of 3 ("b") -> 1, 3, 6,                                                                                                              |
|                                                                                                                                                   |
|     🟦 Multiple of 3 ("b") -> 3, 6, 9, [12] // Proof "b" is divisor of "a", then "a" will be multiple of "b"                                      |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                  EUCLIDEAN ALGORITHM                                                              |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Euclidean algorithm helps us to find GCD by substracting from "a - b" or using "a % b", If "a" got fully subtracted or "b" got fully divided   |
|  without any remainder means that's the point where we say it's GCD.                                                                              |
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
        cout << "Factors of " << n << " are: ";
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
        cout << "Factors of " << n << " are: ";
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
        sFindFactor(3);
    }
}

// Finding primes
namespace prime {
    bool isPrime(int n){
        if(n <= 1) return false; // Number smaller than 1 will not a prime number.

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false; // If it's divisible by any number it can't be a prime
        }

        return true;
    }

    void main(){
        cout << "Is 7 is prime number: " << isPrime(7) << endl;
        cout << "Is 8 is prime number: " << isPrime(8) << endl;
    }
}

// Finding GCD
namespace gcd {
    // o(a)
    void bruteForce(int a, int b) {
        int ans = 1;

        for(int i = 1; i <= min(a, b); i++){
            if(a % i == 0 && b % i == 0){
                ans = i;
            }
        }

        cout << "GCD of " << a << " and " << b << " is: " << ans << endl;
    }

    void euclideanAlgorithm(int a, int b){
        cout << "The GCD of " << a << " and " << b << " is: ";
        
        while(b != 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        
        cout << a << endl;
    }

    int euclideanAlgorithmRec(int a, int b){
        if(b == 0) return a;
        
        return euclideanAlgorithmRec(b, a % b);
    }

    void main(){
        bruteForce(6, 12);
        euclideanAlgorithm(48, 18);
        euclideanAlgorithm(4, 6);
    }
}

// Finding LCM
namespace lcm {
    void bruteForce(int a, int b) {
        int mx = max(a, b);

        while(true){
            if(mx % a == 0 && mx % b == 0){
                break;
            }
            mx++;
        }

        cout << "LCM of " << a << " and " << b << " is: " << mx << endl;
    }

    void optimizedLCM(int a, int b){
        int gcd = gcd::euclideanAlgorithmRec(a, b);
        cout << "LCM of " << a << " and " << b << " is: " << ((a / gcd) * b) << endl;
    }

    void main() {
        bruteForce(4, 6);
        optimizedLCM(4, 6);
    }
}

void mainFunc(){
    factor::main(); // Calling factor
    prime::main(); // Calling Prime
    gcd::main(); // Calling GCD
    lcm::main(); // Calling LCM
}

int main() {
    mainFunc();
    return 0;
}