//
// Created by abdur on 25-06-2026.
//
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::min;
using std::vector;

int findMinOnRotatedSortedArray(const vector<int>& nums) {
    if (nums.empty())
        return -1;

    int leftIdx  = 0;
    int rightIdx = static_cast<int>(nums.size()) - 1;

    while (leftIdx < rightIdx) {
        const int midIdx = leftIdx + (rightIdx - leftIdx) / 2;

        /*
                If nums[midIdx] > nums[rightIdx]
                * Mean I can say min can never be smaller, So that I can directly increase by """"midIdx + 1""""
            */
        if (nums[midIdx] > nums[rightIdx]) {
            leftIdx = midIdx + 1;
        } else {
            // Here we aren't decreasing by """midIdx - 1""", because may there is a chance that nums[midIdx] can be a smaller one.
            rightIdx = midIdx;
        }
    }

    return nums[leftIdx];
}

int main() {
    const vector<int> nums = {3, 4, 5, 6, 7, 0};
    cout << "Minimum value on the array is: " << findMinOnRotatedSortedArray(nums) << endl;

    return 0;
}