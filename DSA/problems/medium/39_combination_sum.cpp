#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> findCombinationSum(const vector<int>& nums, int target) {
        backTracking(nums, 0, target);
        return result;
    }

   private:
    vector<vector<int>> result;

    vector<int> currentCombination;
    int         totalSum = 0;

    void backTracking(const vector<int>& nums, int index, int target) {
        if (totalSum >= target) {
            if (totalSum == target) {
                result.push_back(currentCombination);
            }
            return;
        }

        for (int i = index; i < static_cast<int>(nums.size()); i++) {
            totalSum += nums[i];
            currentCombination.push_back(nums[i]);

            backTracking(nums, i, target);

            totalSum -= nums[i];
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.findCombinationSum({2}, 3));
    return 0;
}
