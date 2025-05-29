#include <iostream>
using namespace std;

int revNumOne(int n) {
    int rev = 0;

    while (n > 0) {
        rev = (rev * 10) + n % 10;

        n /= 10;
    }

    return rev;
}

int revNumTwo(int n, int revNum = 0) {
    if (n == 0) {
        return revNum;
    }

    revNum = (revNum * 10) + (n % 10);
    return revNumTwo(n / 10, revNum);
}

int main() {
    cout << "Reverse of " << "12345 " << "is " << revNumOne(12345) << endl;
    cout << "Reverse of " << "12345 " << "is " << revNumTwo(12345) << endl;
    return 0;
}