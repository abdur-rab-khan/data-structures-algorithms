#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Count Prime in a Range L - R

/*
    >> Bruit Force Approach
*/
bool isPrime(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (n / i != i) {
                count++;
            }
        }
    }

    return count == 2;
}

void printPrimeCount(vector<vector<int>> q) {
    int count, l, r;
    for (int i = 0; i < q.size(); i++) {
        l = q[i][0], r = q[i][1];

        count = 0;
        for (int j = l; j <= r; j++) {
            if (isPrime(j)) {
                count++;
            }
        }

        cout << "The number of prime from " << l << " to " << r << " is: " << count << endl;
    }
}

/*
   >> Using Sieve of Eratosthenes -- o(max_r log log max_r) + o(max_r) + o(q)
   >> In the below solution we use "PREFIX-SUM" with Sieve of Eratosthenes to solve query problem.
        "PREFIX-SUM: " | 2 | 4 | 5 | 10 | 12 |  --> | 2 | 2 + 4 = 6 | 5 + 6 = 11 | 12 + 11 = 23 |

   >> Step 1: First we getSieve value.
   >> Step 2: Using prefix we some all primes number like in the example.
        EXAMPLE:- | 2 = 1 | 3 = 1 | 4 = 0 | 5 = 1 | 6 = 0 | 7 = 1 | 8 = 0 | 9 = 0 | 10 = 0 |
                --> | 2 >> 1 | 3 >> 1 + 1 = 2 | 4 >> 2 + 0 = 2 | 5 >> 3 | 6 >> 3 | 7 >> 4 | 8 >> 4 |
   9 >> 4 | 10 >> 4 |

   >> Step 3: Let's find some queries
        l = 3 , r = 8 | l = 5 , r = 10

        For First One: r[10] = 4, l[3 - 1] = 1 = 4 - 1 = 3;
        For Second One: r[10] = 4, l[5 - 1] = 1 = 4 - 2 = 2;
*/
vector<int> getSieve(int max_r) {
    vector<int> block(max_r + 1, 1);
    block[0] = block[1] = 0;

    for (int i = 2; i * i <= max_r; i++) {
        if (block[i] == 1) {
            for (int j = i * i; j <= max_r; j += i) {
                block[j] = 0;
            }
        }
    }

    return block;
}
void printPrimeCountSecond(vector<vector<int>> q) {
    int max_r = 0;

    for (int i = 0; i < q.size(); i++) {
        int l = q[i][0], r = q[i][1];

        if (max_r < r) {
            max_r = r;
        }
    }

    vector<int> sieve = getSieve(max_r);

    int count = 0;
    for (int i = 2; i < sieve.size(); i++) {
        count = count + sieve[i];

        sieve[i] = count;
    }

    for (int i = 0; i < q.size(); i++) {
        int l = q[i][0], r = q[i][1];

        int count = sieve[r] - sieve[l - 1];

        cout << "The number of prime from " << l << " to " << r << " is: " << count << endl;
    }
}

int main() {
    vector<vector<int>> q = {{4, 20}, {3, 20}};

    printPrimeCount(q);
    cout << endl;

    printPrimeCountSecond(q);
    return 0;
}