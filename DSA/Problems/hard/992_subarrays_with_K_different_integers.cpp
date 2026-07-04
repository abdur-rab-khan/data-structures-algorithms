#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 🟡 Brute for approach
// 👉 [ Remember ] Same issue you did again, You put the "insert" operator at below which is wrong because You'll miss the first match if found.
int countSubarrayWithKDistinctBruteForce(const vector<int>& nums, const int k) {
    int totalSubarray = 0;

    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> distinctIntegers;

        for (int j = i; j < nums.size(); j++) {
            distinctIntegers.insert(nums[j]);

            if (distinctIntegers.size() > k) {
                break;
            } else if (distinctIntegers.size() == k) {
                ++totalSubarray;
            }
        }
    }

    return totalSubarray;
}

// 🟡 Optimized Approach
// 👉 [ Pattern ]: It is a problem where are using a trick called "exactly K = (at most K) - (at most K - 1)" with "Sliding Window"
// 👉 [ Remember ]: Count "at Most K elements" is easier than "counting exact K different numbers" directly If the question is these type than It's most likely it will be solved using "exactly K" trick.
int countSubarrayWithKDistinct(const vector<int>& nums, const int k) {
    const int size = static_cast<int>(nums.size());

    auto countSubarrays = [=](const int k) -> int {
        if (k <= 0) {
            return 0;

            int totalSubarrays = 0;

            unordered_map<int, int> distinctNumsMap;

            int leftIdx = 0;
            for (int rightIdx = 0; rightIdx < size; rightIdx++) {
                distinctNumsMap[nums[rightIdx]]++;

                while (leftIdx < rightIdx && distinctNumsMap.size() > k) {
                    distinctNumsMap[nums[leftIdx]]--;

                    if (distinctNumsMap[nums[leftIdx]] == 0) {
                        distinctNumsMap.erase(nums[leftIdx]);
                    }

                    leftIdx++;
                }

                totalSubarrays += (rightIdx - leftIdx) + 1;
            }

            return totalSubarrays;
        };

        return countSubarrays(k) - countSubarrays(k - 1);
    }

    int
    main() {
        const vector<int> nums = {1, 2};
        cout << "Total subarrays are: " << countSubarrayWithKDistinct(nums, 1) << endl;

        return 0;
    }