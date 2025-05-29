#include <iostream>
using namespace std;

int sumDigitOne(int n) {
    int sum = 0;

    while (n != 0) {
        int last = n % 10;

        sum += last;
        n /= 10;
    }

    return sum;
}

int sumDigitTwo(int n) {
    if (n == 0)
        return (n % 10);

    return (n % 10) + sumDigitTwo(n / 10);
}

int main() {
    cout << "First Approach: " << sumDigitOne(687) << endl;
    cout << "Second Approach: " << sumDigitTwo(687) << endl;
    return 0;
}