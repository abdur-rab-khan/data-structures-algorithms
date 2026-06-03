#include <bits/stdc++.h>
using namespace std;

/**
 * Finds a peak element index using binary search.
 *
 * A peak element is an element that is greater than its neighbors.
 * This implementation assumes the input is non-empty and uses the
 * property that if nums[mid] < nums[mid + 1], a peak exists on the right.
 *
 * Example:
 * Input: nums = [1, 2, 3, 1]
 * Output: 2 (nums[2] = 3 is a peak)
 *
 * Example:
 * Input: nums = [1, 2, 1, 3, 5, 6, 4]
 * Output: 5 (nums[5] = 6 is a peak)
 *
 * Time Complexity: O(log n) - Binary search over the array
 * Space Complexity: O(1) - Uses constant extra space
 *
 * @param nums Vector of integers with at least one element
 * @return Index of any peak element
 */
int findPeekElement(vector<int> nums) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;

    while (leftIndex < rightIndex) {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        if (nums[mid] < nums[mid + 1]) {
            leftIndex = mid + 1;
        } else {
            rightIndex = mid;
        }
    }

    return rightIndex;
}

/**
 * Runs basic sanity checks for findPeekElement.
 */
int main() {
    cout << "Peek element is: " << findPeekElement({1, 2, 3, 1}) << endl;
    cout << "Peek element is: " << findPeekElement({1, 2, 1, 3, 5, 6, 4}) << endl;

    return 0;
}