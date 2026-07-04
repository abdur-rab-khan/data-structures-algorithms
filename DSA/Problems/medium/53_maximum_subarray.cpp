#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

/*
 * 🟡 Optimized approach to solve this problem, we are using an algorithm called "kadane's" algorithm.
 *
 * 🔶 [ Intuition ]: So the intuition is if "currentSum" become less than "0 (negative)", there's no reason to continue the currentSum with "negative number", that's why we'll go to reset the currentSum
 *
 * 🟡 [ Kadane's Algorithm ]: In this algorithm, we store the "currentSum"
 */
int maximumSubarraySum(const vector<int>& nums) {
    const int size = static_cast<int>(nums.size());

    int currentSum  = 0;
    int maxSubarray = INT_MIN;

    for (int i = 0; i < size; i++) {
        currentSum += nums[i];

        maxSubarray = max(maxSubarray, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSubarray;
}

int main() {
    const vector<int> nums1 = {1};
    const vector<int> nums2 = {5, 4, -1, 7, 8};
    const vector<int> nums3 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Max sum array of num1 is: " << maximumSubarraySum(nums1) << endl;
    cout << "Max sum array of num2 is: " << maximumSubarraySum(nums2) << endl;
    cout << "Max sum array of num3 is: " << maximumSubarraySum(nums3) << endl;

    return 0;
}