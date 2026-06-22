#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 🟡 Most Optimized approach --> Time Complexity o(n log n + k), Space Complexity o(1)
vector<int> findKClosestElements(const vector<int>& nums, const int k, const int x) {
    int leftIdx = 0;

    /*
     * Suppose the array looks like this [1, 2, 3, 4, 5]
     * Because the subarrays size will have size "K" suppose K = 3
     * 1. [1, 2, 3],
     * 2. [2, 3, 4]
     * 3. [3, 4, 5]
     * 👉 If we don't subtract the "K" from the size, It will lead an off bound error.
    */
    int rightIdx = static_cast<int>(nums.size()) - k;

    while (leftIdx < rightIdx) {
        const int midIdx = (leftIdx + rightIdx) / 2;

        // There should be two conditions either "rightIdx" will update or "leftIdx", To check whether this window is good, We have to compare "midIdx" with "midIdx + k"
        // If midIdx is correct means, we have to shrink towards right by "midIdx", Otherwise shrink will happen towards left by "midIdx + 1"
        if (x - nums[midIdx] > nums[midIdx + k] - x) {
            leftIdx = midIdx + 1;
        } else {
            rightIdx = midIdx;
        }
    }

    return vector<int>(nums.begin() + leftIdx, nums.begin() + leftIdx + k);
}

vector<int> findKClosestElementTwoPointers(const vector<int>& nums, const int k, const int x) {
    int leftIdx  = 0;
    int rightIdx = static_cast<int>(nums.size()) - 1;

    while (rightIdx - leftIdx >= k) {
        if (x - nums[leftIdx] > nums[rightIdx] - x) {
            leftIdx++;
        } else {
            rightIdx--;
        }
    }

    vector<int> result;
    for (int i = leftIdx; i <= rightIdx; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

int main() {
    const vector<int> nums = {1, 1, 2, 3, 4, 5};

    cout << "Closest elements are: ";
    for (const int& num : findKClosestElements(nums, 4, -1)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
