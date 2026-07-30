#include <iostream>
#include <vector>

using namespace std;

/*
 * Actually, Subsets are collection of elements taken from an original array set where order does not matter. The fundamental thing about subsets are for each elements we have two choices either "TAKE IT" or "LEAVE IT".
 *
 * For Example: [1, 2, 3]
 *      For each element we have two choices:
 *          1 = 2 Choice
 *          2 = 2 Choice
 *          3 = 2 Choice
 *
 *      If we calculate them we'll we 2 * 2 * 2 = 8, means we have 8 possible subsets for this example
 */
class Solution {
   public:
    vector<vector<int>> findSubsets(const vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }

   private:
    vector<int>         subsets;
    vector<vector<int>> result;

    void backTracking(const vector<int>& nums, int start) {
        result.push_back(subsets);

        for (int i = start; i < static_cast<int>(nums.size()); i++) {
            subsets.push_back(nums[i]);
            backTracking(nums, i + 1);
            subsets.pop_back();
        }
    }
};

int main() {
    Solution sol;

    for (auto& subset : sol.findSubsets({1, 2, 3})) {
        cout << "[ ";
        for (int n : subset)
            cout << n << " ";
        cout << "]\n";
    }

    return 0;
}
