#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

int findLongestSubstring(string str, int k) {
    int leftIndex = 0;

    int maxFrequency = 0;
    int maxSubstringLength = 0;

    vector<int> charFrequencyCount(26, 0);

    for (int rightIndex = 0; rightIndex < str.size(); rightIndex++) {
        charFrequencyCount[str[rightIndex] - 'A']++;

        maxFrequency = max(maxFrequency, charFrequencyCount[str[rightIndex] - 'A']);

        while ((rightIndex - leftIndex + 1) - maxFrequency > k) {
            charFrequencyCount[str[leftIndex] - 'A']--;
            leftIndex++;
        }

        maxSubstringLength = max(maxSubstringLength, (rightIndex - leftIndex + 1));
    }

    return maxSubstringLength;
}

int testCount = 0;
void submitForTesting(string str, int k, int expected) {
    testCount++;
    int longestSize = findLongestSubstring(str, k);

    assert(longestSize == expected);
    cout << "Test no. " << testCount << " is done." << endl;
}

int main() {
    submitForTesting("ABAB", 2, 4);
    submitForTesting("AABABBA", 1, 4);

    return 0;
}