#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Count the number of digits ----> Approach 1st
int countDigits(int n) {
    int count = 0;

    while (n != 0) {
        count += 1;
        n = n / 10;
    }

    return count;
}

// Count the number of digits ----> Approach 2nd (using logarithmic function)
int countDigitsSecond(int n) {
    return (int)(log10(n)) + 1;
}

// Reverse the give number --> 1234 (4321)
int revNumber(int n) {
    int rev = 0, lastDigits;

    while (n > 0) {
        lastDigits = n % 10;

        rev = (rev * 10) + lastDigits;

        n /= 10;
    }

    return rev;
}

// Find the palindrome of give number
// Explanation: The reverse of a number should equal to given number (121 --> 121 = true), (122 -->
// 221 = false)
string checkPalindrome(int n) {
    int lastDigit, copyN = n, rev = 0;

    while (copyN > 0) {
        lastDigit = copyN % 10;

        rev = (rev * 10) + lastDigit;

        copyN /= 10;
    }

    return (rev == n ? "true" : "false");
}

// Find armstrong numbers.
// Explanation: Sum of cube of all digits present in the number, that is equal to original number is
// armstrong numbers. Example: 371 --> (3^3 + 7^3 + 1^3 = 371 --> "armstrong"), 35 --> (3^3 + 5^3 =
// 134 --> "not a armstrong")
string checkArmstrong(int n) {
    int lastDigit, sum = 0, copyN = n;

    while (copyN > 0) {
        lastDigit = copyN % 10;

        sum += lastDigit * lastDigit * lastDigit;

        copyN /= 10;
    }

    return (sum == n ? "true" : "false");
}

// Print all divisors --> Approach 1st --> o(n)
// Explanation: Find out all the numbers which are divisible by given number without getting any
// remainders.
// Example: 4 --> (1, 2, 4)
void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << "  ";
        }
    }
    cout << endl;
}

/* Print all divisors --> approach 2st --> o(sqrt(n)) + o(no of factors * log(no of factors)) + n
Example: 36
-> 36 / 1 = 36 |==> 36 % 36 = 0
-> 36 / 2 = 18 |==> 36 % 18 = 0
-> 36 / 3 = 12 |==> 36 % 12 = 0
-> 36 / 4 = 9 |==> 36 % 9 = 0

-> 36 / 6 = 6 |==> 36 % 6  = 0

-> 36 / 9 = 4 |==> 36 % 4 = 0
-> 36 / 12 = 3 |==> 36 % 3 = 0
-> 36 / 18 = 2 |==> 36 % 2 = 0
-> 36 / 36 = 1 |==> 36 % 1 = 0

- You can see after "i" reaches the sqrt(n) the number is divisors are repeated.
- So logic behind it:
    1. if (n / i) = div <==> and "div" is fully divided without getting any remainders means "div"
and "i" both are divisible by "n".
    2. You see after reaching the sqrt(n) it gives the opposite divisors that we already find. -->
So this will going to be our limit.
*/
void printDivisorsSecond(int n) {
    vector<int> divisors;
    int div;

    for (int i = 1; i * i <= n; i++) {
        div = n / i;

        if (n % i != 0)
            continue;

        divisors.push_back(i);

        if (div != i) {
            divisors.push_back(div);
        }
    }

    sort(divisors.begin(), divisors.end());

    for (auto const it : divisors) {
        cout << it << "  ";
    }
}

/*
Check prime numbers -- Approach 1st o(n)
Explanation: A number which are divisible by itself or give number is called a prime number.

| Number | Divisor      | IsPrime |
| 1      | 1            |   True  |
| 2      | 1, 2         |   True  |
| 3      | 1, 3         |   True  |
| 4      | 1, 2, 4      |   False |
| 5      | 1, 5         |   True  |
| 6      | 1, 3, 6      |   False |
*/
string checkPrime(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            count++;
    }

    return (count <= 2) ? "true" : "false";
}

// Check prime numbers -- Approach 2nd o(sqrt(n))
// Explanation: Using factors - A factor is a number that totally divides the given number "n"
// without getting any remainder.
string checkPrimeSecond(int n) {
    int div, count = 0;

    for (int i = 1; i * i <= n; i++) {
        div = n / i;

        if (n % i != 0)
            continue;

        count++;

        if (div != i) {
            count++;
        }
    }

    return (count == 2) ? "true" : "false";
}

int main() {
    int num = 12345;

    cout << "The digits in " << num << " is " << countDigits(num) << endl;
    cout << "The digits in " << num << " is " << countDigitsSecond(num) << endl << endl;

    cout << "The reverse of " << num << " is " << revNumber(num) << endl << endl;

    cout << "Check " << num << " is palindrome: " << checkPalindrome(num) << endl;
    cout << "Check " << 121 << " is palindrome: " << checkPalindrome(121) << endl << endl;

    cout << "Check " << num << " is armstrong: " << checkArmstrong(num) << endl;
    cout << "Check " << 371 << " is armstrong: " << checkArmstrong(371) << endl << endl;

    printDivisors(36);
    printDivisorsSecond(36);

    cout << endl << "Check " << 4 << " is prime: " << checkPrime(4) << endl;
    cout << "Check " << 2 << " is prime: " << checkPrimeSecond(2) << endl;
    cout << "Check " << 5 << " is prime: " << checkPrimeSecond(5) << endl;
    cout << "Check " << 6 << " is prime: " << checkPrimeSecond(6) << endl;
    return 0;
}