#include <functional>
#include <iostream>
#include <vector>

int firstMissing(std::vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = n + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        int num = abs(nums[i]);
        if (num <= n) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    std::vector<int> nums = {-1, -2};
    std::cout << "Missing number is: " << firstMissing(nums) << std::endl;

    return 0;
}