#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (n / i != i)
                count++;
        }
    }

    return count == 2;
}

// Bruit force approach to find prime till n o(n * sqrt(n))
void printAllPrimeFirst(int n) {
    vector<int> primes = {};

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    cout << "Primes are: ";
    for (auto const n : primes) {
        cout << n << " ";
    }
}

/*
    >> Approach second using Sieve of Eratosthenes
    >> Here we create a block something like this:
        Example n = 10; | 2 = 1 | 3 = 1 | 4 = 1 | 5 = 1 | 6 = 1 | 7 = 1 | 8 = 1 | 9 = 1 | 10 = 1 |
    >> Then we run a loop from 2 to n and in the loop.
       We check where i == 1 if yes than make another loop from 2 * i to n and increase by j += i;
       These will be the divisible by 2 which mean they will not a prime number, than we make these
       number to 0;

    >> At the last of we get this | 2 = 1 | 3 = 1 | 4 = 0 | 5 = 1 | 6 = 0 | 7 = 1 | 8 = 0 | 10 = 0 |
*/

void printAllPrimesSecond(int n) {
    vector<int> primes(n + 1, 1);  // Initialize with size n+1, all set to 1
    primes[0] = primes[1] = 0;     // 0 and 1 are not prime

    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            for (int j = 2 * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    cout << endl << "Primes are: ";
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            cout << i << " ";
        }
    }
}

/*
    >> Let's make more optimization to above algo -- o(n) + o(n log log n)
    >> Their is two optimization here.
        1. We run second loop from 2 * i, which means:
            For i = 2;
            2 * 2 = 4;
            2 * 3 = 6;
            2 * 4 = 8;
            2 * 5 = 10;
            2 * 6 = 12; --> which is beyond so here we stop

            For i = 3;
            3 * 2 = 6; --> already find in 2 * 3 = 6
            3 * 3 = 9;
            3 * 4 = 12;  --> which is beyond so here we stop

            For i = 5;
            5 * 2 = 10; --> already find in 2 * 5 = 10
            5 * 3 = 15;  --> which is beyond so here we stop

            For i = 7;
            7 * 7 = 49  --> which is beyond so here we stop

            >> Is we have to run from i * 2, No instead of running from i * 2, We can run from i * i
        2. At the first loop we run from 2 to n; Is really want to run from 2 to n, No:
            >> We know that after 5 it will 7 which is run 7 * 7 = 49 than is beyond to 10, So
   instead of running from 2 to n we run till sqrt to n;
*/
void printAllPrimesThird(int n) {
    vector<int> primes(n + 1, 1);
    primes[0] = primes[1] = 0;

    // o(n log log n)
    for (int i = 2; i * i <= n; i++) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    // o(n)
    cout << endl << "Primes are: ";
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            cout << i << " ";
        }
    }
}

int main() {
    printAllPrimeFirst(100);
    printAllPrimesSecond(100);
    printAllPrimesThird(100);
    return 0;
}