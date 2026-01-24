# Sliding Window Technique

> Sliding window is a technique used to solve problems that involve arrays or lists by creating a "window" that can slide over the data structure to examine subsets of elements.

- [Sliding Window Technique](#sliding-window-technique)
  - [Introduction](#introduction)
    - [Example Problems](#example-problems)
  - [Example](#example)
    - [Using Naive Approach](#using-naive-approach)
    - [Using Sliding Window Technique](#using-sliding-window-technique)
      - [Let's break down and see how the sliding window technique works in this example:](#lets-break-down-and-see-how-the-sliding-window-technique-works-in-this-example)
  - [How to use the sliding window technique?](#how-to-use-the-sliding-window-technique)
    - [1. `Fixed Size Sliding Window`](#1-fixed-size-sliding-window)
    - [2. `Dynamic Size Sliding Window`](#2-dynamic-size-sliding-window)
  - [How to identify sliding window problems?](#how-to-identify-sliding-window-problems)

## Introduction

- The sliding window technique is particularly useful for problems that require finding a contiguous (subarray) or a subset of elements that meet certain criteria, such as finding the maximum sum of a subarray of fixed size, or finding the longest substring without repeating characters.
- The main idea is to use **previous** results to do computations for the **next** window, thus avoiding the need to recompute values from scratch.
- It is commonly used in problems involving arrays, strings, or lists where you need to analyze a subset of elements that are contiguous.

### Example Problems

1. **Maximum Sum of Subarray of Size K**: Given an array and an integer K, find the maximum sum of a subarray of size K.
    - Example: For the array `[1, 2, 3, 4, 5]` and `K = 3`, the maximum sum of a subarray of size 3 is `12` (subarray `[3, 4, 5]`).
        1. First window: `[1, 2, 3]` → sum = 6
        2. Slide the window: `[2, 3, 4]` → sum = 9
        3. Slide the window: `[3, 4, 5]` → sum = 12 (maximum)
        4. Result: `12`
2. **Longest Substring Without Repeating Characters**: Given a string, find the length of the longest substring without repeating characters.
    - Example: For the string `"abcabcbb"`, the longest substring without repeating characters is `"abc"` with length `3`.
        1. Start with an empty window and expand it by adding characters until a repeat is found.
        2. When a repeat is found, slide the window from the left until the repeat is removed.
        3. Keep track of the maximum length of the window during this process.
        4. Result: `3`  

## Example

- **Problem**: Given an array of integers and an integer K, find the maximum sum of a subarray of size K.

### Using Naive Approach

```c++
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

int main() {
    int k = 3;
    vector<int> arr = {5, 2, -1, 0, 3};
cout << "The max sum of " << k << " of subarray is: " << maxSum(arr, k);

    return 0;
}
```

- **Time Complexity**: O(N * K), where N is the number of elements in the array and K is the size of the subarray.
- **Space Complexity**: O(1), as we are using a constant amount of extra space.
- We can reduce the time complexity to O(N) using the sliding window technique, which will be covered in the next section.

### Using Sliding Window Technique

```c++
#include <bits/stdc++.h>
#include <climits>
using namespace std;

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

    cout << "The max sum of " << k << " of subarray is: " << maxSumSWin(arr, k) << endl;
    cout << "The max sum of " << k << " of subarray is: " << maxSumSWin2(arr, k) << endl;

    return 0;
}
```

- **Time Complexity**: O(N), where N is the number of elements in the array.
- **Space Complexity**: O(1), as we are using a constant amount of extra space.

#### Let's break down and see how the sliding window technique works in this example:

1. **Sliding Window:** In this approach, we maintain a window of size K that slides over the array.
2. **Initial Sum Calculation:** We first calculate the sum of the first K elements to initialize our current sum.
3. **Sliding the Window:** As we slide the window from left to right, we subtract the element that is leaving the window (the leftmost element) and add the element that is entering the window (the rightmost element).
4. **Updating Maximum Sum:** After updating the current sum for each new window position, we check if it is greater than the maximum sum recorded so far and update accordingly.

## How to use the sliding window technique?

- There are basically two types of sliding window techniques:

### 1. `Fixed Size Sliding Window`

- The general technique to solve these problems are as follows:
  1. At the start, we calculate the sum of the first window (first K elements).
  2. Then, we iterate through the array, sliding the window one element at a time.
  3. For each new position of the window, we update by using previous results (subtract the element that is leaving the window and add the element that is entering the window).

### 2. `Dynamic Size Sliding Window`

- The general technique to solve these problems are as follows:
  1. In these type of sliding window problems, we expand of shrink the pointer based on the condition.
  2. At any step, if the condition is not match, we shrink the window from the left side.
  3. At any step, if the condition is match, we expand the window from the right side.
  4. We keep track of the maximum or minimum length of the window during this process.

## How to identify sliding window problems?

- These problems typically involve finding a contiguous subarray or substring that meets certain criteria, such as maximum sum, minimum length, or longest substring without repeating characters.
- These problems often require **o(n²)** if using brute force approach, but can be optimized to **o(n)** using the sliding window technique.