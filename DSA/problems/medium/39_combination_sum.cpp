#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> findCombinationSum(const vector<int>& nums, int target) {
        backTracking(nums, target, 0, 0);
        return result;
    }

   private:
    vector<vector<int>> result;
    vector<int>         currentCombination;

    void backTracking(const vector<int>& nums, int target, int index, int currentSum) {
        if (currentSum >= target) {
            if (currentSum == target) {
                result.push_back(currentCombination);
            }
            return;
        }

        // So intead of going from "0" again we just start again and again until "currentSum > target" or "currentSum == target"
        for (int i = index; i < static_cast<int>(nums.size()); i++) {
            currentCombination.push_back(nums[i]);
            backTracking(nums, target, i, currentSum + nums[i]);
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.findCombinationSum({2, 3, 6, 7}, 7));
    return 0;
}
