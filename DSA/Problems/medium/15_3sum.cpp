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
        // Same goes for this as well
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left  = i + 1;
        int right = size - 1;

        while (left < right) {
            if (const int totalSum = nums[i] + nums[left] + nums[right]; totalSum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // If you think, critically you'll see that we can simply skip number of previous and current numbers are the same.
                // Why?? Suppose we have this number [-2, -1, -1, 2]
                // At left = 1 is -1, and left = 2 is -1 which means we'll going to get
                // On left = 1 [-1, -1, 2] and on left = 2 [-1, -1, 2]
                // If this is a case we can skip them easily, but after putting the result atleast one time.
                // One more we are only doing if we got the answer because there we don't care if we got any duplicate and they are similar
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (right > right && nums[right] == nums[right - 1])
                    left++;
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
    vector<int> num1 = {-1, 0, 1, 2, -1, -4};
    vector<int> num2 = {0, 1, 1};
    vector<int> num3 = {0, 0, 0};

    cout << "Distinct three sum equal to 0 is: ";
    for (const vector<int>& vec : threeSum(num1)) {
        cout << "[ ";
        for (const int& num : vec) {
            cout << num << ", ";
        }
        cout << " ]";
    }
    cout << endl;

    return 0;
}
