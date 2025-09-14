#include <bits/stdc++.h>

#include <climits>

using namespace std;

// Using naive approach to solve
int maxSum(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int current_sum = 0;

        for (int j = 0; j < k; j++)
            current_sum += arr[i + j];

        maxSum = max(maxSum, current_sum);
    }

    return maxSum;
}

// Using sliding window technique approach (first)
int maxSumSWin(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = k - 1;
    int maxSum = INT_MIN, currentSum = 0;

    // Let's find the sum from 0 till k;
    for (int i = 0; i < k; i++)
        currentSum += arr[i];

    while (r < n) {
        l++;
        r++;

        int prevL = arr[l - 1], prevR = arr[r - 1];
        currentSum = (currentSum - prevL) + prevR;

        // Update if currentSum is greater than maxSum
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

// Using sliding window technique approach (second)
// Reduce the number of extra variables
int maxSumSWin2(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN, window_size = 0;

    // Compute the sum from 0 till k - 1
    for (int i = 0; i < k; i++)
        window_size += arr[i];

    for (int i = k; i < n; i++) {
        // Let's remove i - kth element and add k element;
        window_size += arr[i] - arr[i - k];

        // Update if window_size is greater than maxSum
        maxSum = max(maxSum, window_size);
    }

    return maxSum;
}

int main() {
    int k = 3;
    vector<int> arr = {0, 1, 2, 3, 4};

    cout << "The max sum of " << k << " of subarray is: " << maxSum(arr, k) << endl;
    cout << "The max sum of " << k << " of subarray is: " << maxSumSWin(arr, k) << endl;
    cout << "The max sum of " << k << " of subarray is: " << maxSumSWin2(arr, k) << endl;

    return 0;
}