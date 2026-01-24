#include <bits/stdc++.h>
using namespace std;

/*
    <===================> Count Strictly Increasing Subarrays <===================>

    ◎ Given an integer array called "arr[]", that is task to count number of subarray and they
        should be in increasing order and have a size of aleast 2.
    ◎ A "subarrays" is the contiguous sequence of elements from arr[], and subarray should be each
        element is greater than previous one.

    -> Example:

    Input: arr[] = {1, 4, 5, 3, 7, 9}
    Output: 6
    Explanation: The strictly increasing subarrays are: [1, 4], [1, 4, 5], [4, 5], [3, 7],
                    [3, 7, 9], [7, 9]

    Input: arr[] = {1, 4, 5, 3, 7, 9}
    Output: 6
    Explanation: The strictly increasing subarrays are: [1, 3], [2, 3], [2, 3, 5], [3, 5]

    Input: arr[] = {1, 4, 5, 3, 7, 9}
    Output: 6
    Explanation: No strictly increasing subarray exists.
*/

int strictlySubArrayBR(vector<int>& arr) {
    int n = arr.size();  // Size of the array
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int j = i;
        while (arr[j] < arr[++j] && j != n) {
            cnt++;
        }
    }

    return cnt;
}

int strictlySubArray(vector<int>& arr) {
    int n = arr.size();

    if (n < 2) {
        return 0;
    }

    int cnt = 0, len = 1;

    for (int i = 1; i < n; i++) {
        // If current element is greater than previous one.
        if (arr[i] > arr[i - 1]) {
            len++;
        } else {
            // Add subarrays count and reset len
            cnt += (len * (len - 1)) / 2;
            len = 1;
        }
    }

    cnt += (len * (len - 1)) / 2;
    // If len is 4 means we found element in increasing order. we use
    // this formula to check how many possible subarrays are possible.

    return cnt;
}

int main() {
    vector<int> arr = {1, 4, 5, 3, 7, 9};
    vector<int> arr2 = {2, 2, 2, 2, 2};
    vector<int> arr3 = {1, 3, 3, 2, 3, 5};
    vector<int> arr4 = {1, 2, 2, 4};

    cout << "Using Brute Force Method: " << "\n";
    cout << "The count is: " << strictlySubArrayBR(arr) << "\n";
    cout << "The count is: " << strictlySubArrayBR(arr2) << "\n";
    cout << "The count is: " << strictlySubArrayBR(arr3) << "\n";
    cout << "The count is: " << strictlySubArrayBR(arr4) << "\n";

    cout << "Using Sliding Window Technique: " << "\n";
    cout << "The count is: " << strictlySubArray(arr) << "\n";
    cout << "The count is: " << strictlySubArray(arr2) << "\n";
    cout << "The count is: " << strictlySubArray(arr3) << "\n";
    cout << "The count is: " << strictlySubArray(arr4) << "\n";

    return 0;
}