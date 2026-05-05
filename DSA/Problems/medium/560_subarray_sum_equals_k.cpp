#include <bits/stdc++.h>

#include <cassert>
using namespace std;

/**
 * Counts the number of subarrays whose sum equals k.
 *
 * Uses prefix sums and a frequency map. For each position, the number of
 * prior prefixes with sum (currentSum - k) indicates how many subarrays
 * ending here add up to k.
 *
 * Example:
 * Input: nums = [1, 1, 1], k = 2
 * Output: 2
 *
 * Example:
 * Input: nums = [1, 2, 3], k = 3
 * Output: 2
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(n) - Stores prefix sum frequencies
 *
 * @param nums Vector of integers
 * @param k Target sum for subarrays
 * @return Count of subarrays whose sum equals k
 */
int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int prefixCount = 0;

    unordered_map<int, int> prefixFreq;

    prefixFreq.insert({0, 1});

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int diff = sum - k;

        if (prefixFreq.count(diff))
            prefixCount += prefixFreq[diff];

        prefixFreq[sum]++;
    }

    return prefixCount;
}

int testCount = 1;
/**
 * Runs an assertion-based test for subarraySum.
 *
 * @param numbers Input array to test
 * @param target Target sum to search for
 * @param expected Expected count of matching subarrays
 */
void submitForTesting(vector<int> numbers, int target, int expected) {
    int output = subarraySum(numbers, target);

    assert(output == expected);
    cout << "Test case no. " << testCount << " is done" << endl;
    testCount++;
}

/**
 * Executes sample test cases.
 */
int main() {
    submitForTesting({1, 1, 1}, 2, 2);
    submitForTesting({1, 2, 3}, 3, 2);
    submitForTesting({1, 2, 8, 6, 7}, 13, 1);
    return 0;
}
