#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Move all zeros to end of array <================>

    ◉ Given an array "arr", Task is to move all "zeros" to the "end" of the "arr".
    ◉ While maintaining the relative order of all non-zero elements.

    <==================> Examples <================>

    ◉ Example 1: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
                 Output = [1, 2, 4, 3, 5, 0, 0, 0]

    ◉ Example 2: arr[] = [10, 20, 30]
                 Output = 10, 20, 30
*/

void moveAllZeros(vector<int>& arr) {
    int left = 0;
    int right = left + 1;

    while (right < arr.size()) {
        if (arr[left] == 0 && arr[right] != 0) {
            arr[left] = arr[right];
            arr[right] = 0;

            left++;
        } else {
            if (arr[left] != 0)
                left++;
        }

        right++;
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    vector<int> arr2 = {10, 20, 30};
    vector<int> arrEx = {0, 1, 2, 0, 0, 0, 1, 0, 0, 1, 4, 3, 0, 5, 0};

    moveAllZeros(arr);
    moveAllZeros(arr2);
    moveAllZeros(arrEx);

    for (const int n : arr)
        cout << n << " ";
    cout << "\n";

    for (const int n : arr2)
        cout << n << " ";
    cout << "\n";

    for (const int n : arrEx)
        cout << n << " ";
    cout << "\n";

    return 0;
}