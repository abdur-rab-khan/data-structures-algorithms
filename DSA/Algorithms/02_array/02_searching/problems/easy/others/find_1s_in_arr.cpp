#include <bits/stdc++.h>
using namespace std;

/*
    <=================> Find 1's in Sorted array <=============>

    ● Given a "non-increasing" ordered sorted binary array (arr[]) of size n, Task is to count
   number of 1's.

   <=================> Examples <=================>
    Input: arr[] = [1, 1, 0, 0, 0, 0, 0]
    Output: 2

    Input : arr[] = [1, 1, 1, 1, 1, 1]
    Output : 6

    Input: arr[] = [0, 0, 0, 0, 0, 0]
    Output: 0
*/

int countOne(vector<int>& arr) {
    int n = arr.size() - 1;
    int low = 0, high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 0)
            high = mid - 1;

        // If we are at last or mid + 1 is not 1 then simply return mid + 1;
        else if (mid == n - 1 || arr[mid + 1] != 1)
            return mid + 1;

        else
            low = mid + 1;
    }
}

int main() {
    vector<int> arr = {1, 1, 1, 0, 0, 0, 0};

    int count1 = countOne(arr);
    cout << "Count of 1's in arr is: " << count1 << endl;

    // Example 2
    vector<int> arr2 = {1, 1, 0, 0, 0, 0};

    int count2 = countOne(arr2);
    cout << "Count of 1's in arr is: " << count2 << endl;

    // Example 3
    vector<int> arr3 = {1, 1, 1, 1, 1, 1};

    int count3 = countOne(arr3);
    cout << "Count of 1's in arr is: " << count3 << endl;

    // Example 4
    vector<int> arr4 = {0, 0, 0, 0, 0, 0};

    int count4 = countOne(arr4);
    cout << "Count of 1's in arr is: " << count4 << endl;

    return 0;
}