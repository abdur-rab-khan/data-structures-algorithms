#include <math.h>

#include <iostream>
using namespace std;

int closestNumber(int n, int m) {
    int closest = 0;
    int minDifferent = INT_MAX;

    for (int i = n - abs(m); i <= n + abs(m); ++i) {
        if (i % m == 0) {
            int difference = abs(n - i);

            if (difference < minDifferent ||
                (difference == minDifferent && abs(i) > abs(closest))) {
                closest = i;
                minDifferent = difference;
            }
        }
    }

    return closest;
}

int main() {
    int n = 27, m = 4;

    if (m == 0) {
        cout << "Error: Number does not have to zero" << endl;
        return 1;
    }

    int closest = closestNumber(n, m);
    cout << "The Closest to " << n << " divisible by " << m << " is " << closest << endl;
    return 0;
}