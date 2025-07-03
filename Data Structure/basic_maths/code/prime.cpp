#include <iostream>
using namespace std;

/*
    --> A number is a "prime" number, that is divisible by "ONE" or "ITSELF" and total number of
   divisor will "TWO".
*/

// Brute force method to find -- prime number  >> o(n)
string isPrimeNumber(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    return count != 2 ? "Number is not prime" : "Number is prime";
}

// Better approach: using factor method o(sqrt(n))
string isPrimeNumberSecond(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (n / i != i) {
                count++;
            }
        }

        if (count > 2)
            break;
    }

    return count != 2 ? "Number is not prime" : "Number is prime";
}

int main() {
    cout << isPrimeNumber(2) << endl;
    cout << isPrimeNumberSecond(6) << endl;
    cout << isPrimeNumberSecond(2) << endl;
    return 0;
}