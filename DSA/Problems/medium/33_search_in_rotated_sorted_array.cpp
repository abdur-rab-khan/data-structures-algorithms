#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
    * Search in rotated sorted array, We are given an rotated sorted array, mean there will be a pointer where we'll have two sorted array.
    * [4, 5, 6, 7, 0, 1, 2] --> Like this, and problem will say try to find "target" elements
    * We can think like that, after/before the mid pointer "there will be atleast one sorted array".
    * Like if mid point is "7" then the there will be two parts
    *   [7, 5, 6]
    *   [0, 1, 2] 
    * So the idea is try to find thing on sorted side and the make condition for either going towards left or right side.
*/
int searchInRotatedSortedArray(const vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int size = static_cast<int>(nums.size());

    int leftIdx = 0, rightIdx = size - 1;
    while (leftIdx <= rightIdx) {
        int midIdx = leftIdx + (rightIdx - leftIdx) / 2;

        if (nums[midIdx] == target) {
            return midIdx;
        }

        if (nums[leftIdx] <= nums[midIdx]) {
            // Left half [leftIdx, midIdx] is sorted.
            // We have to take two decisions either say towards left, or go towards right.
            if (nums[leftIdx] <= target && nums[midIdx] > target) {
                rightIdx = midIdx - 1;
            } else {
                leftIdx = midIdx + 1;
            }
        } else {
            // Right half [midIdx, rightIdx] is sorted
            // We have to take two decision either say towards left, or go towards right.
            if (nums[rightIdx] >= target && nums[midIdx] < target) {
                leftIdx = midIdx + 1;
            } else {
                rightIdx = midIdx - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Search 0: " << searchInRotatedSortedArray(nums, 0) << endl;
    cout << "Search 3: " << searchInRotatedSortedArray(nums, 3) << endl;

    return 0;
}