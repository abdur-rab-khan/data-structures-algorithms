//
// Created by abdur on 02-07-2026.
//
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void moveZerosToEnd(vector<int>& nums) {
    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < static_cast<int>(nums.size()); rightIdx++) {
        if (nums[rightIdx] != 0) {
            if (leftIdx != rightIdx)
                swap(nums[leftIdx], nums[rightIdx]);
            ++leftIdx;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZerosToEnd(nums);

    cout << "Elements after moving zero to end: ";
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}