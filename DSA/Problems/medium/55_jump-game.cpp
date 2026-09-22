#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    bool canJump(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        // 🟡 First approach: Traversing from right to left.
        // 🟡 At each step we are checking that if the finalPosition is reachable from current pos.
        // 🟡 If it's reachable mean we can now say that if any number each to current reachable position, then they can eventually to go the end
        // int finalPosition = static_cast<int>(nums.size() - 1);

        // for (int i = nums.size() - 2; i >= 0; --i) {
        //     if (nums[i] + i >= finalPosition) {
        //         finalPosition = i;
        //     }
        // }

        // return finalPosition == 0;

        int maxReach = 0;
        int size     = static_cast<int>(nums.size()) - 1;
        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            if (nums[i] + i > maxReach) {
                maxReach = nums[i] + i;
            }
            if (maxReach >= size) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    std::vector<int> num1 = {0, 2, 3};
    std::vector<int> num2 = {2, 3, 1, 1, 4};
    std::vector<int> num3 = {3, 2, 1, 0, 4};

    print(sol.canJump(num1), "Can jump to end: ");
    print(sol.canJump(num2), "Can jump to end: ");
    print(sol.canJump(num3), "Can jump to end: ");

    return 0;
}
