#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int>         tempList;
    vector<vector<int>> result;

    void backTracking(const vector<int>& nums) {
        if (tempList.size() == nums.size()) {
            result.push_back(tempList);
            return;
        }

        for (const int& num : nums) {
            if (find(tempList.begin(), tempList.end(), num) != tempList.end()) {
                continue;
            }

            // CHOOSE: Push into the tempList
            tempList.push_back(num);

            // BACKTRACK: "backTracking" to call the function
            backTracking(nums);

            // UNCHOOSE: Pop from tempList mainly to skip and create permutation
            tempList.pop_back();
        }
    }

    vector<vector<int>> findPermutations(const vector<int>& nums) {
        backTracking(nums);
        return result;
    }
};

int main() {
    return 0;
}
