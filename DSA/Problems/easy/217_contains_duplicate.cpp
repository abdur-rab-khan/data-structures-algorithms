#include <bits/stdc++.h>
using namespace std;

/**
 * Checks whether the array contains any duplicate value.
 *
 * Uses a hash table to track which values have been seen before. If a value
 * is encountered twice, the function returns true.
 *
 * Example:
 * Input: nums = [1, 2, 3, 1]
 * Output: true
 *
 * Example:
 * Input: nums = [1, 2, 3, 4]
 * Output: false
 *
 * Time Complexity: O(n) - One pass with average O(1) insert/lookup
 * Space Complexity: O(n) - Stores seen values
 *
 * @param nums Vector of integers to check
 * @return True if any duplicate exists, otherwise false
 */
bool containsDuplicate(vector<int> nums) {
    unordered_map<int, int> numFreqTracer;

    for (int i = 0; i < nums.size(); i++) {
        if (numFreqTracer.count(nums[i]))
            return true;

        numFreqTracer[nums[i]]++;
    }

    return false;
}

int testCount = 0;
void submitForTesting(vector<int> nums, bool expected) {
    testCount++;

    bool res = containsDuplicate(nums);

    assert(res == expected);
    cout << "Test no. " << testCount << " is done." << endl;
}

int main() {
    submitForTesting({1, 2, 3, 1}, true);
    submitForTesting({1, 2, 3, 4, 5}, false);

    return 0;
}