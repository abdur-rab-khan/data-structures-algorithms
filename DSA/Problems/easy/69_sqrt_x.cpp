#include <bits/stdc++.h>
using namespace std;

/*
    * This Problem is about performing "sqrt" without using any build-in methods like "pow".
    * To do this we need to solve manually, Basically here we use "Binary Search" on Answer method.
    * Instead of looping through every number we'll directly "o(log n)" time at every iteration.
    *
    * There is an edge case for solving with "8", We can't directly solve "2 * 2 = 8 because 2 * 2 = 4" and "2.8 * 2.8 = 8".
    * As calculation become smaller than target, means like "end" number will be the "sqrt" not directly but by using decimal number we can find it. 
    * Example: 8: -> 2
    * Example: 4 -> 2
*/
int sqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int start = 2;
    int end = x;
    int mid = -1;

    while (start <= end) {
        mid = start + (end - start) / 2;
        long long square = static_cast<long long>(mid) * mid;

        if (square == x) {
            return mid;
        }

        if (square > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return end;
}

int testCount = 1;
void submitForTesting(int x, int expected) {
    int s = sqrt(x);

    assert(s == expected);
    cout << "Test no. " << testCount++ << " is done" << endl;
}

int main() {
    submitForTesting(8, 2);
    submitForTesting(4, 2);

    return 0;
}