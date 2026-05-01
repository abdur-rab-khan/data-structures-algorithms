#include <bits/stdc++.h>

#include <cassert>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int prefixCount = 0;

    unordered_map<int, int> prefixFreq;

    prefixFreq.insert({0, 1});

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int diff = sum - k;

        if (prefixFreq.count(diff))
            prefixCount += prefixFreq[diff];

        prefixFreq[sum]++;
    }

    return prefixCount;
}

int testCount = 1;
void submitForTesting(vector<int> numbers, int target, int expected) {
    int output = subarraySum(numbers, target);

    assert(output == expected);
    cout << "Test case no. " << testCount << " is done" << endl;
    testCount++;
}

int main() {
    submitForTesting({1, 1, 1}, 2, 2);
    submitForTesting({1, 2, 3}, 3, 2);
    submitForTesting({1, 2, 8, 6, 7}, 13, 1);
    return 0;
}
