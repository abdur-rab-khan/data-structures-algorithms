#include <bits/stdc++.h>

#include <cassert>
using namespace std;

// TODO: THIS ONE BREAK WHEN ARRAY HAS NEGATIVE NUMBERS, SO WE CAN'T SOLVE WITH SLIDING WINDOW WE NEED TO USE PREFIX SUM.
int subarraySum(vector<int>& nums, int k) {
    int totalSum = 0;
    int leftIdx = 0;

    for (int rightIdx = 0; rightIdx < nums.size(); rightIdx++) {
        totalSum += nums[rightIdx];

        if (totalSum == k)
            return ((rightIdx - leftIdx) + 1);

        while (totalSum >= k) {
            totalSum -= nums[leftIdx];
            leftIdx++;
        }
    }

    return -1;
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
    submitForTesting({1, 2, 8, 6, 7}, 13, 2);
    return 0;
}
