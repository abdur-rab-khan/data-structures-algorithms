#include <iostream>
using namespace std;

// Brute Force Approach o(n)
long long findExpo(int x, int n) {
    long long ans = 1;

    while (n > 0) {
        ans = ans * x;
        n--;
    }

    return ans;
}

/*
    >> Approach second -- o(log₂ n)
    >> It is more optimized and efficient way to find exponential.
    >> Explanation:
                    For 2^7 = 128:
                        n = 7;
                        ans = 1, 2, 4, 16;
                        x = 1 * 2 * 4 * 16 = 128;

                        2 * 2^6 = 2^6;
                        (2^2) * 2^6/2 = (4)^3;
                        4 * 4^2 = 16^1;
                        16 * 16^1/2 = 16 * 1;
*/

template <typename T>
T findExpoSecond(T x, int n) {
    int m = n;
    T ans = 1;
    n = abs(n);

    while (n >= 1) {
        if (n % 2 == 0) {
            // Even
            x = x * x;
            n = n / 2;
        } else {
            // Odd
            ans = ans * x;
            n = n - 1;
        }
    }

    return m < 0 ? T(1) / ans : ans;
}

int main() {
    cout << "2^64: " << findExpo(2, 20);
    cout << endl << "2^64: " << findExpoSecond<float>(2, -20);
    return 0;
}