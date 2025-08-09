#include <bits/stdc++.h>
using namespace std;

/*
    <================> CHECK ARRAY SORTED <================>

    ◎ For this question, Task is to check whether give array is sorted or not.
    ◎ Before solving let's understand what is the meaning of sorted, So sorted mean every element
        from left always smaller than it right one.

    ◎ Example 1:
                arr = [10, 20, 30, 50, 60]
                result = true

    ◎ Example 2:
                arr = [10, 20, 5, 50, 60]
                result = false
*/

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }

    return true;
}

bool isSortedHelper(vector<int> arr, int n) {
    if (n == 0 || n == 1)
        return true;

    return arr[n - 1] >= arr[n - 2] && isSortedHelper(arr, n - 1);
}

bool isSortedR(const vector<int>& arr) {
    return isSortedHelper(arr, arr.size());
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    vector<int> arr2 = {10, 20, 3, 40, 1, 60};

    cout << "Is arr is sorted: " << (isSorted(arr) ? "true" : "false") << endl;
    cout << "Is arr is sorted: " << (isSorted(arr2) ? "true" : "false") << endl;

    // Using Recursive function
    cout << "Is arr is sorted: " << (isSortedR(arr) ? "true" : "false") << endl;
    cout << "Is arr is sorted: " << (isSortedR(arr2) ? "true" : "false") << endl;

    // Using build-in function
    cout << "Is arr is sorted: " << (is_sorted(arr.begin(), arr.end()) ? "true" : "false") << endl;
    cout << "Is arr is sorted: " << (is_sorted(arr2.begin(), arr2.end()) ? "true" : "false")
         << endl;

    return 0;
}