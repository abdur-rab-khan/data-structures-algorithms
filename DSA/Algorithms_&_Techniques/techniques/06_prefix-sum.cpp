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

    void main() {
        vector<int> nums = {3, 7, 2, 5, 8};
        auto sumQuery = sumQueryRange(nums);

        cout << "Sum of nums from 0 to 2 is: " << sumQuery(0, 2) << endl;
        cout << "Sum of nums from 2 to 4 is: " << sumQuery(2, 4) << endl;
    }
}  // namespace easy

// Medium Prefix Sum Problems
namespace medium {}

// Hard Prefix Sum Problems
namespace hard {}

int main() {
    easy::main();

    return 0;
}