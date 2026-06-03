#include <bits/stdc++.h>

#include <cassert>
using namespace std;

/**
     * Let's  explain how the following approach is working, So to solve the following problem we use "prefix sum" approach.
     * How it's working:
     *      Suppose I have a road and their are some point after before kilo-meters, and we want to find how many point are there in "n" kilo-meters
     *     
     *      1     2     3      4 
     *      *-----*-----*------*    k = 2 (Find number of point in 2 kilo-meters)
     *      1     1     1      1
     * 
     *      At index -> 0 -> prefix sum = 1 and find k - prefix (1 - 2) = -1 is -1 is there previously No. -> {0: 1}
     *      At index -> 1 -> prefix sum = 2 and find k - prefix (2 - 2) = 0 is 0 is there previously, Yes mean there are map[0] numbers of points. -> {0: 1, 2: 1}
     *      At index -> 2 -> prefix sum = 3 and find k - prefix (3 - 2) = 2 is 2 is there previously Yes. So prefixCount become prefixCount += map[2] = 2
 */
int subarraySumCount(vector<int>& nums, int k) {
    int subarrayCount = 0;
    int currentPrefixSum = 0;

    unordered_map<int, int> prefixFreq;

    prefixFreq.insert({0, 1});

    for (int i = 0; i < nums.size(); i++) {
        currentPrefixSum += nums[i];
        int diff = currentPrefixSum - k;

        if (prefixFreq.count(diff))
            subarrayCount += prefixFreq[diff];

        prefixFreq[currentPrefixSum]++;
    }

    return subarrayCount;
}

int testCount = 1;
/**
 * Runs an assertion-based test for subarraySum.
 *
 * @param numbers Input array to test
 * @param target Target sum to search for
 * @param expected Expected count of matching subarrays
 */
void submitForTesting(vector<int> numbers, int target, int expected) {
    int output = subarraySumCountnumbers, target);

    assert(output == expected);
    cout << "Test case no. " << testCount << " is done" << endl;
    testCount++;
}

/**
 * Executes sample test cases.
 */
int main() {
    submitForTesting({1, 1, 1}, 2, 2);
    submitForTesting({1, 2, 3}, 3, 2);
    submitForTesting({1, 2, 8, 6, 7}, 13, 1);
    return 0;
}
