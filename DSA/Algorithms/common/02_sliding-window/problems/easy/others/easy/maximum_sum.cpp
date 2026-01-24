#include <bits/stdc++.h>
using namespace std;

/*
    <=====================> Maximum sum subarray having sum less than or equal to given sum
   <=====================>

    ◎ Given an array "arr" and integer "sum", So our task is to find contiguous subarray who's sum
        is "maximum possible".
    ◎ And ensure sum does not exceed the given target sum.

    -> EXAMPLE:

    Input: arr[] = [1, 2, 3, 4, 5], sum = 11
    Output: 10
    Explanation: Subarray having maximum sum is [1, 2, 3, 4]

    Input: arr[] = [2, 4, 6, 8, 10], sum = 7
    Output: 6
    Explanation: Subarray having maximum sum is [2, 4] or [6]
*/

// Brute force approach TIME_COMPLEXITY o(n²) and SPACE_COMPLEXITY o(1)
int maxSumBR(vector<int> arr, int sum) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int ctn = 0;

        for (int j = i; j < n; j++) {
            ctn += arr[j];

            if (ctn < sum) {
                maxSum = max(maxSum, ctn);
            }
        }
    }

    return maxSum;
}

// Expected Approach TIME_COMPLEXITY o(n) and SPACE_COMPLEXITY o(1)
int maxSum(vector<int> arr, int sum) {
    int n = arr.size();
    int maxSum = INT_MIN, ctn = arr[0];
    int start = 0;

    for (int i = 1; i < n; i++) {
        if (ctn <= sum) {
            maxSum = max(maxSum, ctn);
        }

        // What if ctn greater than sum
        while (start < i && ctn + arr[i] > sum) {
            ctn -= arr[start];
            start++;
        }

        if (ctn < 0) {
            ctn = 0;
        }

        ctn += arr[i];
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {2, 4, 6, 8, 10};

    cout << "Using brute force approach: " << endl;
    cout << "Max sum of subarray: " << maxSumBR(arr, 11) << endl;
    cout << "Max sum of subarray: " << maxSumBR(arr1, 7) << endl;

    cout << "Using expected approach: " << endl;
    cout << "Max sum of subarray: " << maxSum(arr, 11) << endl;
    cout << "Max sum of subarray: " << maxSum(arr1, 7) << endl;

    return 0;
}