#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    A prime factor is a number which are completely divide "n". And the number is also prime.
    For Example: 60
    Divisors from 1 - 60: 1 - 60:
        1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 36, 60
    Prime between all divisor:
        2, 3, 5
*/
bool isPrime(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (n / i != i)
                count++;
        }

        if (count > 2)
            break;
    }

    return count == 2;
}

/*
    APPROACH (1)
        >> It will firstly find is the given number is divisor or not, if YES -- than it will check
            is prime for both divisor and corresponding divisor.
        --------------------------------------------------------------------------------------------
        >> TIME COMPLEXITY: o(sqrt(n) + sqrt(i) * sqrt(n / i))
*/
void printAllPrimeFactors(int n) {
    vector<int> primes = {};

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i))
                primes.push_back(i);

            if (n / i != i) {
                if (isPrime(n / i)) {
                    primes.push_back(n / i);
                }
            }
        }
    }

    sort(primes.begin(), primes.end());
    for (auto const n : primes) {
        cout << n << " ";
    }
    cout << endl;
}

/*
    APPROACH (2)
        >> In this approach we use traditional school one approach. Where we check a number is
            divisible if yes than divide "n" with i util it will un-divisible.
            -- There is one more thing we have to see, we run from 2 to sqrt of n. because the prime
                factor of n will same as prime factor of sqrt of (n).
        --------------------------------------------------------------------------------------------
        >> TIME COMPLEXITY: o(sqrt(n) * log n)
        --------------------------------------------------------------------------------------------
        Example:
                -- For 36 -- sqrt(36) = 6
                2 | 36 → 36 ÷ 2 = 18
                2 | 18 → 18 ÷ 2 = 9
                3 | 9  → 9 ÷ 3 = 3
                3 | 3  → 3 ÷ 3 = 1

                -- Prime factors are: 2,3

                2 | 6 → 6 ÷ 2 = 3
                3 | 3 → 3 ÷ 3 = 1

                -- Prime factors are: 2,3
*/
void printAllPrimeFactorsSecond(int n) {
    vector<int> primes = {};

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);

            // Let's divide n until it will become un-divisible by i.
            while (n % i == 0)
                n = n / i;
        }
    }

    if (n != 1)
        primes.push_back(n);

    for (auto const n : primes) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    printAllPrimeFactors(780);
    printAllPrimeFactorsSecond(780);
    return 0;
}