#include <bits/stdc++.h>
using namespace std;

int binarySearchR(vector<int>& arr, int target, int left, int right) {
    // If space is exhausted
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // Check -- Whether arr[mid] == target
    if (arr[mid] == target)
        return mid;

    return (arr[mid] > target ? binarySearchR(arr, target, left, mid - 1)
                              : binarySearchR(arr, target, mid + 1, right));
}

int binarySearchL(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int x = 1;

    cout << x << " is found at: " << binarySearchR(arr, x, 0, arr.size() - 1) << "\n";
    cout << x << " is found at: " << binarySearchL(arr, x) << "\n";
    return 0;
}