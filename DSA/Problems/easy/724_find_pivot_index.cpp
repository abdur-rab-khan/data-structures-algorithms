#include <bits/stdc++.h>
using namespace std;

/*
    * "Pivot Index:" Every numbers to "left" from "pivot index" is strictly equal to every number to "right".
    * For Example in this: [1, 7, 3, 6, 5, 6]
    * 
    * Pivot index is 6 so: 1 + 7 + 3 = 11 and 5 + 6 = 11;
*/
int findPivotIndex(vector<int>& nums) {
    int leftSum = 0;
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 5, 1, 2, 1, 1, 5, 11};
    cout << "Pivot index is: " << findPivotIndex(nums) << endl;

    return 0;
}