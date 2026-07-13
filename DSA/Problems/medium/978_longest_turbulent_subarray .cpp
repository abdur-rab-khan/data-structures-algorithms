#include <iostream>
#include <vector>

using namespace std;

int findLongestTurbulentSubarray(vector<int> nums) {
    int    maxSubarray  = 1;
    string previousSign = "";

    int leftIdx = 0, rightIdx = 1;
    while (rightIdx < static_cast<int>(nums.size())) {
        if (!(nums[rightIdx] == nums[rightIdx - 1])) {
            const auto invalidSign = (nums[rightIdx - 1] > nums[rightIdx] && previousSign == ">") ||
                                     (nums[rightIdx - 1] < nums[rightIdx] && previousSign == "<");

            if (invalidSign) {
                // Why we are doing like this??
                // Once it become invalid, means the sign is invalid, but we know that "right - 1" will be valid.
                // It's because there will be only two elements, we there's no way to be a wrong substring
                leftIdx = rightIdx - 1;
            }

            previousSign = nums[rightIdx - 1] > nums[rightIdx] ? ">" : "<";
        } else {
            previousSign = "";

            // Why we aren't just doing "right - 1", because both are same, we can't say it will be turbulent subarray.
            // It's because of turbulent subarray are a subarray where either ">" or "<" not "==", that's why "right - 1" will never be a valid subarray.
            leftIdx = rightIdx;
        }

        maxSubarray = max(maxSubarray, (rightIdx - leftIdx) + 1);
        rightIdx++;
    }

    return maxSubarray;
}

int main() {
    cout << "Longest subarray is: " << findLongestTurbulentSubarray({9, 4, 2, 10, 7, 8, 8, 1, 9})
         << endl;
    cout << "Longest subarray is: " << findLongestTurbulentSubarray({4, 8, 12, 16}) << endl;
    cout << "Longest subarray is: " << findLongestTurbulentSubarray({100}) << endl;
    return 0;
}
