#include <algorithm>
#include <vector>

using namespace std;

#include "../../dsa_utils.h"

/*
 * Permutation is rearrangment of all the elements of an array, in such a way to that all the array are distinct and unique.
 * To solve this problem the easiest way is using "backTracking" technique where where we solve quickly as much as possible.
*/
class Solution {
   public:
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<int>         currentPermute;
        vector<vector<int>> finalPermutations;
        vector<bool>        visited(nums.size(), false);

        backTracking(nums, currentPermute, visited, finalPermutations);
        return finalPermutations;
    }

   private:
    void backTracking(const vector<int>& nums, vector<int>& currentPermute, vector<bool>& visited,
                      vector<vector<int>>& finalPermutations) {
        if (currentPermute.size() == nums.size()) {
            finalPermutations.push_back(currentPermute);
            return;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            currentPermute.push_back(nums[i]);
            backTracking(nums, currentPermute, visited, finalPermutations);

            visited[i] = false;
            currentPermute.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.permute({1, 2, 3}), "Permutations of 123 are: ");

    return 0;
}
