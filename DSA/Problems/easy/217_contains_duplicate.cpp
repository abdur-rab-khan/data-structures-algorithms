#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums) {
    unordered_map<int, int> numFreqTracer;

    for (int i = 0; i < nums.size(); i++) {
        if (numFreqTracer.count(nums[i]))
            return true;

        numFreqTracer[nums[i]]++;
    }

    return false;
}

int testCount = 0;
void submitForTesting(vector<int> nums, bool expected) {
    testCount++;

    bool res = containsDuplicate(nums);

    assert(res == expected);
    cout << "Test no. " << testCount << " is done." << endl;
}

int main() {
    submitForTesting({1, 2, 3, 1}, true);
    submitForTesting({1, 2, 3, 4, 5}, false);

    return 0;
}