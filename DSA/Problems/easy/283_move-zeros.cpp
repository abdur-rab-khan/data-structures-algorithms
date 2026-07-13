#include <vector>

#include "../../dsa_utils.h"

using namespace std;

void moveZeros(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < static_cast<int>(nums.size()); rightIdx++) {
        if (nums[rightIdx] != 0) {
            swap(nums[rightIdx], nums[leftIdx]);
            leftIdx++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 1, 2};
    moveZeros(nums);
    printArrayElements(nums);
}
