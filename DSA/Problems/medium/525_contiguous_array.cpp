#include <bits/stdc++.h>
using namespace std;

// We can't use sliding window here because, there is no condition for stoping the iteration.

// ==> BRUIT FORCE APPROACH
int findMaxLength(vector<int>& nums) {
    int maxSubArraySize = 0;

    for (int i = 0; i < nums.size(); i++) {
        int totalOnes = 0;
        int totalZeros = 0;

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 0) {
                totalZeros++;
            } else {
                totalOnes++;
            }

            if (totalZeros == totalOnes) {
                maxSubArraySize = max(maxSubArraySize, (j - i + 1));
            }
        }
    }

    return maxSubArraySize;
}

// ==> OPTIMIZED APPROACH USING HASHMAP
int findMaxLengthFirst(vector<int>& nums) {
    unordered_map<int, int> firstSeen;
    firstSeen[0] = -1;

    int maxLen = 0;
    int runningSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        runningSum += (nums[i] == 0) ? -1 : 1;

        if (firstSeen.count(runningSum)) {
            maxLen = max(maxLen, i - firstSeen[runningSum]);
        } else {
            firstSeen[runningSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> numbers = {0, 1, 1, 0, 1, 0, 1};
    cout << "Max Length is: " << findMaxLength(numbers) << endl;
    cout << "Max Length is: " << findMaxLengthFirst(numbers) << endl;

    return 0;
}