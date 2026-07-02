//
// Created by abdur on 02-07-2026.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

vector<vector<int>> threeSum(vector<int>& nums) {
    const int size = nums.size();

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left  = i + 1;
        int right = size - 1;

        while (left < right) {
            const int totalSum = nums[i] + nums[left] + nums[right];

            if (totalSum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
            } else {
                if (totalSum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}