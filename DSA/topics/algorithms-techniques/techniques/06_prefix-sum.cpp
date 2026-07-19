/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                         ➕ PREFIX SUM                                                                                    | 
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                          |
| 🟡 Prefix Sum of an Array is a sum of element from **start** till **end** it is also called as **Cumulative Sum**.                                                                       |
|                                                                                                                                                                                          |
| 🟡 Prefix Sum of **ith** element will be the sum of element of **0th** element to **(i-1)th** element.                                                                                   |
|                                                                                                                                                                                          |
| 🟡 It's often used to **pre-calculate** array element so that in future we don't need to calculate again and again.                                                                      |
|                                                                                                                                                                                          |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                        ➕ EXAMPLE                                                                                        | 
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                          |
| originalArray = [3, 7, 2, 5, 8];                                                                                                                                                         |
|                                                                                                                                                                                          |
| 🟡 Prefix Sum                                                                                                                                                                            |
|                                                                                                                                                                                          |
|    0 = 3                                                                                                                                                                                 |
|                                                                                                                                                                                          |
|    1 = 7 + previous(3) = 10                                                                                                                                                              |
|                                                                                                                                                                                          |
|    2 = 2 + previous(10) = 12                                                                                                                                                             |
|                                                                                                                                                                                          |
|    3 = 5 + previous(12) = 17                                                                                                                                                             |
|                                                                                                                                                                                          |
|    4 = 8 + previous(17) = 25                                                                                                                                                             |
|                                                                                                                                                                                          |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>

#include "../../dsa_utils.hpp"

using namespace std;

// Easy Prefix Sum Problems
namespace easy {
    auto sumQueryRange(vector<int> nums) {
        // Let's make prefix sum
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return [&nums](int left, int right) {
            if (left == 0)
                return nums[right];

            return nums[right] - nums[left - 1];
        };
    }

    vector<int> leftRightDifference(vector<int>& numbers) {
        vector<int> diffArray(numbers.size());

        int totalSum = accumulate(numbers.begin(), numbers.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < numbers.size(); i++) {
            int rightSum = totalSum - (leftSum + numbers[i]);
            int diff = abs(rightSum - leftSum);

            diffArray[i] = diff;
            leftSum += numbers[i];
        }

        return diffArray;
    }

    void main() {
        // Question 1: Sum Query Range.
        vector<int> nums = {3, 7, 2, 5, 8};
        auto sumQuery = sumQueryRange(nums);

        cout << "Sum of nums from 0 to 2 is: " << sumQuery(0, 2) << endl;
        cout << "Sum of nums from 2 to 4 is: " << sumQuery(2, 4) << endl;

        // Question 2: Left Right Difference.
        std::vector<int> numbers = {10, 4, 8, 3};
        printArrayElements(leftRightDifference(numbers), "Array Difference are: ");
    }
}  // namespace easy

// Medium Prefix Sum Problems
namespace medium {
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int prefixCount = 0;

        unordered_map<int, int> prefixFreq;

        prefixFreq.insert({0, 1});

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int diff = sum - k;

            if (prefixFreq.count(diff))
                prefixCount += prefixFreq[diff];

            prefixFreq[sum]++;
        }

        return prefixCount;
    }

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

    void main() {
        // Question 1. Sub Array Sum
        vector<int> numbers = {1, 1, 1};
        cout << "Total subArrays are: " << subarraySum(numbers, 2) << endl;

        // Question 2. Product Except Self
        std::vector<int> nums = {1, 2, 3, 4};
        std::vector<int> result = productExceptSelf(nums);

        printArrayElements(result, "Expected product self is: ");
    }

}  // namespace medium

// Hard Prefix Sum Problems
namespace hard {}

int main() {
    // easy::main();
    medium::main();

    return 0;
}