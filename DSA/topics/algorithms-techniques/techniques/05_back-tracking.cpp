/*
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                         BACK TRACKING                                                                          |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <iostream>
#include <vector>

using namespace std;

namespace Problems {
    class Subset {
       public:
        vector<vector<int>> findSubsets(const vector<int>& nums) {
            backTracking(0, nums);
            return result;
        }

       private:
        vector<int>         subsets;
        vector<vector<int>> result;

        void backTracking(int index, const vector<int>& nums) {
            if (index >= static_cast<int>(nums.size())) {
                result.push_back(subsets);
                return;
            }

            subsets.push_back(nums[index]);  // CHOOSE: add nums[index] into the path
            backTracking(index + 1, nums);   // EXPLORE: go deeper look element only after i
            subsets.pop_back();  // UNCHOOSE: remove nums[i] before trying to next option

            backTracking(index + 1, nums);
        }
    };

    class Permutation {
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

       public:
        vector<vector<int>> findPermutations(const vector<int>& nums) {
            backTracking(nums);
            return result;
        }
    };

    void main() {
        // Solve subset problem using backtracking
        vector<int> nums = {1, 2, 3};
        Subset      sub;

        cout << "Total Subsets are: ";
        for (const vector<int>& subsets : sub.findSubsets(nums)) {
            cout << "[ ";
            for (const int& num : subsets) {
                cout << num << " ";
            }
            cout << " ] ";
        }
        cout << endl;

        // Solve Permutation problem using backtracking
        Permutation per;

        cout << "Total Permutations are: ";
        for (const vector<int>& permutation : per.findPermutations(nums)) {
            cout << "[ ";
            for (const int& num : permutation) {
                cout << num << " ";
            }
            cout << " ] ";
        }
        cout << endl;
    }
};  // namespace Problems

int main() {
    Problems::main();
    return 0;
}
