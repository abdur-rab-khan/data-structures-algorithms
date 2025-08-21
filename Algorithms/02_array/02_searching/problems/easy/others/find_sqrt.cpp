#include <bits/stdc++.h>
using namespace std;

/*
    <===================> Find Square Root of Integer <===================>

    ◎ Given an positive integer, task is to find square root. If "n" is not a perfect square simply
   return floor of √n

    Example:
            n = 4
            output = 2
            ◎ Explanation: The sqrt root of 4 is 2.

            n = 11
            output = 3
            ◎ Explanation: The square root of 11 lies in between 3 and 4 so floor of the square root
                            is 3.
*/

int sqrt_bs(int n) {
    int low = 1, high = n;
    int result = 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            result = mid;
            break;
        }

        if ((mid * mid) > n) {
            high = mid - 1;
        } else {
            result = mid;
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    cout << "Sqrt of 4 is: " << sqrt_bs(11) << endl;

    return 0;
}