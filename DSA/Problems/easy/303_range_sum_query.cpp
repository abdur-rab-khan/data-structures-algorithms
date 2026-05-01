#include <bits/stdc++.h>
using namespace std;

class NumArray {
   public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        if (nums.empty())
            return;

        prefixSum.resize(nums.size());

        this->prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            this->prefixSum[i] = this->prefixSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return this->prefixSum[right];

        return (this->prefixSum[right] - this->prefixSum[left - 1]);
    }
};

int testingCount = 0;
void submitForTesting(vector<int> nums, int left, int right, int expected) {
    NumArray n(nums);

    int sum = n.sumRange(left, right);

    assert(sum == expected);
    cout << "Test no. " << testingCount << " successfully solved" << endl;
    testingCount++;
}

int main() {
    submitForTesting({-2, 0, 3, -5, 2, -1}, 0, 2, 1);

    return 0;
}