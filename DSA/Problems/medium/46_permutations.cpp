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
    vector<vector<int>> findPermutations(const vector<int>& nums) {
        backTracking(nums);
        return result;
    }

   private:
    vector<int>         tempList;
    vector<vector<int>> result;

    void backTracking(const vector<int>& nums) {
        if (tempList.size() == nums.size()) {
            result.push_back(tempList);
            return;
        }

        for (const int& num : nums) {
            if (ranges::find(tempList, num) != tempList.end()) {
                continue;
            }

            tempList.push_back(num);  // CHOOSE: Push into the tempList
            backTracking(nums);       // BACKTRACK: "backTracking" to call the function
            tempList
                .pop_back();  // UNCHOOSE: Pop from tempList mainly to skip and create permutation
        }
    }
};

int main() {
    Solution sol;
    print(sol.findPermutations({1, 2, 3}), "Permutations of 123 are: ");

    return 0;
}
