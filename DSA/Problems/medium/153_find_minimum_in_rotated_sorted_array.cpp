//
// Created by abdur on 25-06-2026.
//
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int findMinOnRotatedSortedArray(const vector<int>& nums) {
    if (nums.empty())
        return -1;

    int leftIdx  = 0;
    int rightIdx = static_cast<int>(nums.size()) - 1;

    while (leftIdx < rightIdx) {
        const int midIdx = leftIdx + (rightIdx - leftIdx) / 2;

        if (nums[midIdx] > nums[rightIdx]) {
            leftIdx = midIdx + 1;
        } else {
            // We aren't doing "mid - 1", because maybe mid will be smaller among all of them.
            // Look at this case: [3, 1, 2], mid is smaller than 2 right but if do "right = mid - 1", than will going to miss 1 right?? think about that
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
