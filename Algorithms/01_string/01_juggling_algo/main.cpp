#include <bits/stdc++.h>
using namespace std;

/*
    <======================> JUGGLING ALGORITHM <======================>
    ◉ So the idea behind this algorithm is to rotate array elements by using cycles (find using
   gcd).
    ◉ GCD helps to find greater number that is divisible by both of them.
    ◉ Each cycle starts from "i" and go (currIdx + d) % n till when (currIdx + d) % n reach "i".
    ◉ And Each time we exchange the currIdx to nextIdx we will in details ⬇️.
*/

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();

    d %= n;  // Handle cases where d > size of array

    int cycles = __gcd(n, d);

    // Process cycle
    for (int i = 0; i < cycles; i++) {
        int temp = arr[i];

        int currIdx = i, nextIdx;
        while (true) {
            nextIdx = (currIdx + d) % n;

            if (nextIdx == i)
                break;

            arr[currIdx] = arr[nextIdx];
            currIdx = nextIdx;
        }

        arr[currIdx] = temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int d = 2;

    rotateArr(arr, d);

    // Print the rotated array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}