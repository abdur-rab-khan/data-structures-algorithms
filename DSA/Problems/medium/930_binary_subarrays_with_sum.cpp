#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 🟡 Brute force appraoch:
// 👉 [ Remember ]: You were put the "sum" at the end, which was wrong because what happend if we got 2 -> goal at start, absolutely we were miss that.
int countSubarraySumEqualGoalBruteForce(const vector<int>& nums, const int goal) {
    const int size = static_cast<int>(nums.size());

    int subarrayCount = 0;

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += nums[j];

            if (sum > goal) {
                break;
            }

            if (sum == goal) {
                subarrayCount++;
            }
        }
    }

    return subarrayCount;
}

/* 🟡 Optimized approach:
 👉 [ Remember ]:
                🔸 First thing It won't going to solve using simple sliding window, the problem with this approach is we'll going to miss lots of subarray who's sum is equal to goal.
                🔸 So instead of finding subarray who's sum is exactly equal to goal, find two things:
                    1. Find Subarrays who sum is less than equal to goal, I know it will going to consider everything. Suppose goal is 2 then it will consider 0, 1, 2.
                    2. Find Subarrays who sum is less than equal to "goal - 1", then it will give everything from 0 and 1, if Goal is 2.
                    3. Now the final part, substract all goal from 0 to 2 with goal from 0 to 1, means Now we'll got the subarrays who's goal is 2.
*/
int countSubarraySumEqualGoal(const vector<int>& nums, const int goal) {
    const int size = static_cast<int>(nums.size());

    auto countSubarray = [=](const int g) -> int {
        if (g < 0) {
            return 0;
        }

        int prefixSum     = 0;
        int totalSubarray = 0;

        int leftIdx = 0;
        for (int rightIdx = 0; rightIdx < size; rightIdx++) {
            prefixSum += nums[rightIdx];

            while (prefixSum > g) {
                prefixSum -= nums[leftIdx];
                leftIdx++;
            }

            totalSubarray += (rightIdx - leftIdx) + 1;
        }

        return totalSubarray;
    };

    return countSubarray(goal) - countSubarray(goal - 1);
}

int main() {
    const vector<int> nums = {0, 0, 0, 0, 0};
    cout << "Total subarrays are: " << countSubarraySumEqualGoal(nums, 0) << endl;

    return 0;
}