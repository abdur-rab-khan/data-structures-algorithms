#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getSieve(int n) {
    vector<int> sieve(n + 1);

    for (int i = 2; i <= n; i++)
        sieve[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (sieve[j] != j)
                    continue;

                sieve[j] = i;
            }
        }
    }

    return sieve;
}

/*
    >> 1. Here we use Smallest Prime Factor method to find Prime Numbers. So like in previous query
   based question we use same logic here.
   >> 2. Pre-Computation: But the small changes is instead of using 0 we use smallest prime factor
   at that place.
   >> 3. Finally we divide the query with given smaller factor division perform until it will
   become 1.
    >> Time Complexity is: o(N log log N) + (Q + log₂ N)
    >> Space Complexity is: o(N)

    Example:-
        For: 12 --> | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
        >> Step 1: Check is number is prime if yes that find there smaller prime factors. once the
   prime allocated smaller prime factor we can't change it.
        >> | 2 | 3 | 4 = 2 | 5 | 6 = 2 | 7 | 8 = 2| 9 | 10 = 2 | 11 | 12 = 2 |
        --> | 2 | 3 | 4 = 2 | 5 | 6 = 2 | 7 | 8 = 2 | 9 = 3 | 10 = 2 | 11 | 12 = 2 |

        >> 12 = 2 | 12
            6 = 2 | 6
                3 | 3
                  | 1

            --> Prime factors are 2, 2, 3
 */
void printSmallestPrimeFactor(vector<int> query) {
    int max = *max_element(query.begin(), query.end());

    // o(N log log N)
    vector<int> sieve = getSieve(max);

    for (auto q : query) {
        cout << "Prime numbers of " << q << " are: ";
        while (q != 1) {
            cout << sieve[q] << " ";
            q = q / sieve[q];
        }
        cout << endl;
    }
}

int main() {
    printSmallestPrimeFactor({30, 16, 17});
    return 0;
}