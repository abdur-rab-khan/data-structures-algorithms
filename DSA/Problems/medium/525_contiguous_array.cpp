#include <bits/stdc++.h>
using namespace std;

// We can't use sliding window here because, there is no condition for stoping the iteration.

// ==> BRUIT FORCE APPROACH
int findLongestContiguousArrayBruteForce(vector<int>& nums) {
    int maxSubArraySize = 0;

    for (int i = 0; i < nums.size(); i++) {
        int totalOnes  = 0;
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

/*
 * Optimized approach using Hashmap
 * You were too worry about how to find the whole length once we got the sum what I've already see before. 
 * 
 * Finding size at the center on end of the array is very simple:
 *   1. Suppose I saw 0 at index 4 and index 8, mean we can find the size but using this formula (8 - 4 = 4). Mean there were 4 elements there.
 *   2. But problem will happen if found 0 at index 1, means at the start, then we have to set 0: -1 in advance because (1 - (-1) = (1 + 1 = 2)) 
*/
int findLongestContiguousArray(const vector<int>& binaryNums) {
    if (binaryNums.empty()) {
        return 0;
    }

    int runningPrefixSum        = 0;
    int longestContinuousSubStr = 0;

    unordered_map<int, int> firstSeen;
    firstSeen[0] = -1;

    for (int i = 0; i < static_cast<int>(binaryNums.size()); i++) {
        runningPrefixSum += binaryNums[i] == 0 ? -1 : 1;

        auto it = firstSeen.find(runningPrefixSum);
        if (it != firstSeen.end()) {
            longestContinuousSubStr = max(longestContinuousSubStr, (i - (*it).second));
        }

        firstSeen[runningPrefixSum] = i;
    }

    return longestContinuousSubStr;
}

int main() {
    vector<int> numbers = {0, 1, 1, 0, 1, 0, 1};
    cout << "Max Length is: " << findLongestContiguousArray(numbers) << endl;
    cout << "Max Length is: " << findLongestContiguousArray(numbers) << endl;

    return 0;
}