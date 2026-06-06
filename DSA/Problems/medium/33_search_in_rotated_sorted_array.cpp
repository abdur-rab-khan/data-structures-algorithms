#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int findKOnRotatedSortedArray(const vector<int>& nums, int k) {
    if (nums.empty()) {
        return -1;
    }

    int size = static_cast<int>(nums.size());

    int leftIdx = 0, rightIdx = size - 1;
    for (int i = 0; i < size / 2; i++) {
        int midIdx   = leftIdx + (rightIdx - leftIdx) / 2;
        int midValue = nums[midIdx];

        if (midValue == k) {
            return midIdx;
        }

        // .....
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Search 0: " << findKOnRotatedSortedArray(nums, 0) << endl;
    cout << "Search 3: " << findKOnRotatedSortedArray(nums, 3) << endl;

    return 0;
}