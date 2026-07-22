#include <iostream>
#include <numeric>
#include <vector>

#include "../../dsa_utils.hpp"

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();

    std::vector<int> answer(n);
    std::vector<int> prefix(n);
    std::vector<int> suffix(n);

    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    return answer;
}

// More Efficient
std::vector<int> calculateProductExceptSelf(std::vector<int>& nums) {
    const int        numCount = static_cast<int>(nums.size());
    std::vector<int> products(nums.size(), 1);

    int runningProduct = 1;
    for (int i = 0; i < numCount; i++) {
        products[i] *= runningProduct;
        runningProduct *= nums[i];
    }

    runningProduct = 1;
    for (int i = numCount - 1; i >= 0; i--) {
        products[i] *= runningProduct;
        runningProduct *= nums[i];
    }

    return products;
}

int main() {
    std::vector<int> nums    = {1, 2, 3, 4};
    std::vector<int> result  = productExceptSelf(nums);
    std::vector<int> result2 = calculateProductExceptSelf(nums);

    print(result, "Expected product self is: ");
    print(result2, "Expected product self is: ");

    return 0;
}
