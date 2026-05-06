#include <bits/stdc++.h>
using namespace std;

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
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << "Pivot index is: " << findPivotIndex(nums) << endl;

    return 0;
}