#include <bits/stdc++.h>
using namespace std;

/**
 * Supports range sum queries using a prefix sum array.
 */
class NumArray {
   public:
    vector<int> prefixSum;
    /**
     * Builds a prefix sum array from the input numbers.
     *
     * Example:
     * Input: nums = [-2, 0, 3, -5, 2, -1]
     * prefixSum = [-2, -2, 1, -4, -2, -3]
     *
     * Time Complexity: O(n) - One pass to build prefix sums
     * Space Complexity: O(n) - Stores prefix sums
     *
     * @param nums Vector of integers to preprocess
     */
    NumArray(vector<int>& nums) {
        if (nums.empty())
            return;

        prefixSum.resize(nums.size());

        this->prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            this->prefixSum[i] = this->prefixSum[i - 1] + nums[i];
        }
    }

    /**
     * Returns the sum of elements between left and right (inclusive).
     *
     * Example:
     * Input: left = 0, right = 2
     * Output: 1
     *
     * Time Complexity: O(1) - Prefix sum lookup
     * Space Complexity: O(1) - No extra space per query
     *
     * @param left Left index of the range
     * @param right Right index of the range
     * @return Sum of nums[left..right]
     */
    int sumRange(int left, int right) {
        if (left == 0)
            return this->prefixSum[right];

        return (this->prefixSum[right] - this->prefixSum[left - 1]);
    }
};

int testingCount = 0;
void submitForTesting(vector<int> nums, int left, int right, int expected) {
    NumArray n(nums);

    int sum = n.sumRange(left, right);

    assert(sum == expected);
    cout << "Test no. " << testingCount << " successfully solved" << endl;
    testingCount++;
}

int main() {
    submitForTesting({-2, 0, 3, -5, 2, -1}, 0, 2, 1);

    return 0;
}