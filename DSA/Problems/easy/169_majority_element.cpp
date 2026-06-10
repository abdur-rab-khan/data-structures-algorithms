#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
    * To solve this problem, We actually have three approach, let's see one by one.
    *   1. Using Hashmap
    *       * In this approach, We actually use hashmap to track the candidate majority, and update if majority is increased by any candidate.
    *   2. Using sorting
    *       * It's only take two lines to solve this problem, First is I'll sort the array and as the problem say array will always have majority mean then I can directly get using n[size / 2].
    *   3. Using Boyer-Moore Voting Algorithm
    *       * Let's explain this algorithm step by step:
    *           1. Initially, We choose first element as a candidate and made count as 0
    *           2. As we go either candidate increases/decreases:
    *                   1. "Increases" --> Than we increase the count by 1
    *                   2. "Decreases" --> Than we increase the count by 1
    *           3. If candidate become "0" means, Now it's not in majority than we update with current one.
*/
int findMajorityElements(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int count     = 0;
    int candidate = nums[0];

    for (const int& n : nums) {
        candidate = count == 0 ? n : candidate;

        if (candidate == n) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    // vector<int> nums = {3, 2, 4, 3}; ❌ Yes, it will going to give wrong answer which is ""4"", but problem say It will always have majority element so that It won't occur.

    vector<int> nums = {3, 2, 3};
    cout << "Majority elements are: " << findMajorityElements(nums) << endl;

    return 0;
}