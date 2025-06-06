#include <iostream>
using namespace std;

// Finding LCM approach one.
int LCM(int a, int b) {
    int greaterNum = max(a, b);
    int smallerNum = min(a, b);

    for (int i = greaterNum;; i += greaterNum) {
        if (i % smallerNum == 0) {
            return i;
        }
    }
}

// Finding LCM approach two (Using GCD).

// Finding LCM approach three.

int main() {
    int a = 4, b = 6;

    cout << "LCM of " << a << " " << b << " is " << LCM(a, b) << endl;
    return 0;
}