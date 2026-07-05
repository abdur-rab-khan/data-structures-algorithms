#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 🟡 Brute force approach, ⌛ Complexity --> time complexity = o(n^2), space complexity = o(1)
int countSubarrayProductsBrute(const vector<int>& nums, const int k) {
    int subArrayCount = 0;

    for (int i = 0; i < nums.size(); i++) {
        int products = 1;
        for (int j = i; j < nums.size(); j++) {
            products *= nums[j];
            if (products < k) {
                subArrayCount++;
            } else {
                break;
            }
        }
    }

    return subArrayCount;
}

/* 🟡 Optimized Approach
 * 💡 The key idea behind this approach is by counting the total elements inside a window ""instead of count subarray"", by doing this we can count the number of window's exists on it.
 *
 * 🔶 { 10, 5, 2, 6 }
 *      🔸 { 10 }         ||    1
 *      🔸 { 10, 5 }      ||    2
 *      🔸 { 5, 2 }       ||    2
 *      🔸 { 5, 2, 6 }    ||    3
 *
 *  👉 1 + 2 + 2 + 3 = 8
 */
int countSubarrayProducts(const vector<int>& nums, const int k) {
    int product        = 1;
    int totalSubarrays = 0;

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < static_cast<int>(nums.size()); rightIdx++) {
        product *= nums[rightIdx];

        while (leftIdx <= rightIdx && product >= k) {
            product /= nums[leftIdx];
            leftIdx++;
        }

        totalSubarrays += (rightIdx - leftIdx) + 1;
    }

    return totalSubarrays;
}

int main() {
    const vector<int> nums = {10, 5, 2, 6};
    cout << "Total subarray count is: " << countSubarrayProducts(nums, 100) << endl;

    return 0;
}