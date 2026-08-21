//
// Created by abdur on 02-07-2026.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> nums) {
        if (nums.size() < 3) {
            return {};
        }

        std::ranges::sort(nums);
        vector<vector<int>> result;

        for (auto first = nums.begin(); first < nums.end() - 2; ++first) {
            // Skip duplicate first elements to avoid duplicate triplets
            if (first != nums.begin() && *first == *(first - 1)) {
                continue;
            }

            auto left  = first + 1;
            auto right = nums.end() - 1;

            while (left < right) {
                int sum = *first + *left + *right;

                if (sum == 0) {
                    result.push_back({*first, *left, *right});
                    ++left;
                    --right;

                    // If you think, critically you'll see that we can simply skip number of previous and current numbers are the same.
                    // Why?? Suppose we have this number [-2, -1, -1, 2]
                    // At left = 1 is -1, and left = 2 is -1 which means we'll going to get
                    // On left = 1 [-1, -1, 2] and on left = 2 [-1, -1, 2]
                    // If this is a case we can skip them easily, but after putting the result atleast one time.
                    // One more we are only doing if we got the answer because there we don't care if we got any duplicate and they are similar
                    while (left < right && *left == *(left - 1)) {
                        ++left;
                    }

                    while (right > left && *right == *(right + 1)) {
                        --right;
                    }

                    continue;
                }

                if (sum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> num1 = {-1, 0, 1, 2, -1, -4};
    vector<int> num2 = {0, 1, 1};
    vector<int> num3 = {0, 0, 0};

    Solution sol;

    cout << "Distinct three sum equal to 0 is: ";
    for (const vector<int>& vec : sol.threeSum(num1)) {
        cout << "[ ";
        for (const int& num : vec) {
            cout << num << ", ";
        }
        cout << " ]";
    }
    cout << endl;

    return 0;
}
