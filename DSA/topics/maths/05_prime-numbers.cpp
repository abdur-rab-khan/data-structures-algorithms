/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     PRIME NUMBERS                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Prime number is a number, who only divide by "1" or "itself", a number can't be a prime if they have more than "two" factors.                  |
|                                                                                                                                                   |
| 🔶 Example:                                                                                                                                       |
|           🔸 2, 3, 5, 7, 11 (PRIME NUMBERS)                                                                                                       |
|           🔸 1, 2, 4, 6, ... (NON PRIME NUMBERS)                                                                                                  |
|                                                                                                                                                   |
| 🔷 Key Takeaway                                                                                                                                   |
|                                                                                                                                                   |
|    🔹All the multiples of a prime number will be non-prime numbers, So 2 is prime all the multiple e.g 4, 6, 8, 16 these will not be a prime.     |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <vector>

#include "../../dsa_utils.h"

using namespace std;

// 🟡 Sieve of Eratosthenes
vector<int> getPrimeRange(int n) {
    vector<int> primes(n + 1, true);

    primes[0] = primes[1] = false;

    for (int i = 2; i <= n; i++) {
        if (primes[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;  // Number smaller than 1 will not a prime number.

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;  // If it's divisible by any number it can't be a prime
    }

    return true;
}

int main() {
    print(isPrime(7), "Is 7 is prime number: ");
    print(isPrime(8), "Is 8 is prime number: ");

    print(getPrimeRange(10), "Prime numbers between 2 to 10 are: ");

    return 0;
}
