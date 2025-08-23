#include <bits/stdc++.h>
using namespace std;

/*
    <=================> Minimum in a Sorted and Rotated Array <=================>

    ● Given a sorted array of distinct elements "arr[]" of size n, which is rotated at some unknown
    point, the task is to find the minimum element in it.

   <=================> Examples <=================>
    Input: arr[] = [5, 6, 1, 2, 3, 4]
    Output: 1
    Explanation: 1 is the minimum element present in the array.

    Input: arr[] = [3, 1, 2]
    Output: 1
    Explanation: 1 is the minimum element present in the array.

    Input: arr[] = [4, 2, 3]
    Output: 2
    Explanation: 2 is the only minimum element in the array.
*/

int minElement(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        // The current subarray is already sorted,
        // the minimum is at the low index
        if (arr[low] < arr[high])
            return arr[low];

        int mid = (low + high) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            low = mid;
    }

    return arr[low];
}

int main() {
    // Example 1
    vector<int> arr1 = {5, 6, 1, 2, 3, 4};
    int minElem1 = minElement(arr1);

    cout << "Min element in arr is: " << minElem1 << endl;

    // Example 2
    vector<int> arr2 = {3, 1, 2};
    int minElem2 = minElement(arr2);

    cout << "Min element in arr is: " << minElem2 << endl;

    // Example 3
    vector<int> arr3 = {4, 2, 3};
    int minElem3 = minElement(arr3);

    cout << "Min element in arr is: " << minElem3 << endl;

    return 0;
}