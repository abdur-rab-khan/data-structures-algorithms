#include <algorithm>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsetsWithDup(const vector<int>& nums) {
        vector<int> sortedNums = nums;
        std::ranges::sort(sortedNums);
        backTracking(sortedNums, 0);
        return result;
    }

   private:
    vector<vector<int>> result;
    vector<int>         current;

    void backTracking(const vector<int>& nums, int index) {
        result.push_back(current);

        for (int i = index; i < static_cast<int>(nums.size()); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backTracking(nums, i + 1);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.subsetsWithDup({1, 2, 2}), "Unique subsets are: ");
    return 0;
}
