#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + nums[i - 1];
    }

    return nums;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    runningSum(numbers);

    return 0;
}