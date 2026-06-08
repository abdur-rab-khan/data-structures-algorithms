#include <bits/stdc++.h>

#include <cassert>
using namespace std;

/**
 * Removes duplicates from a sorted array in place and returns the new length.
 *
 * Uses a two-pointer sweep: the left pointer tracks the last unique element
 * while the right pointer scans forward. When a new value is found, it is
 * placed at the next left position.
 *
 * Example:
 * Input: nums = [1, 1, 2]
 * Output: 2, nums = [1, 2]
 *
 * Example:
 * Input: nums = [0, 0, 1, 1, 2, 2, 3]
 * Output: 4, nums = [0, 1, 2, 3]
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - In-place updates only
 *
 * @param nums Sorted vector of integers to deduplicate
 * @return The count of unique elements after in-place modification
 */
int removeDuplicates(vector<int>& nums) {
    int leftIndex = 0;

    for (int rightIndex = 0; rightIndex < nums.size(); rightIndex++) {
        if (nums[leftIndex] != nums[rightIndex]) {
            nums[++leftIndex] = nums[rightIndex];
        }
    }

    nums.resize(leftIndex + 1);
    nums.shrink_to_fit();

    return leftIndex + 1;
}

int testCount = 0;
void submitForTesting(vector<int> nums, vector<int> expected) {
    testCount++;

    int k = removeDuplicates(nums);

    assert(nums.size() == k);
    for (int i = 0; i < nums.size(); i++) {
        assert(nums[i] == expected[i]);
    }

    cout << "Test no. " << testCount << " is done" << endl;
}

int main() {
    submitForTesting({1, 1, 2}, {1, 2});
    submitForTesting({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4});

    return 0;
}