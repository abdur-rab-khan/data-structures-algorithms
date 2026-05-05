#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

/**
 * Finds the length of the longest substring that can be made uniform with k replacements.
 *
 * Uses a sliding window and tracks the maximum frequency character within
 * the window. The window is valid if (windowSize - maxFrequency) <= k.
 *
 * Example:
 * Input: str = "ABAB", k = 2
 * Output: 4
 *
 * Example:
 * Input: str = "AABABBA", k = 1
 * Output: 4
 *
 * Time Complexity: O(n) - Each character is processed at most twice
 * Space Complexity: O(1) - Fixed-size frequency array
 *
 * @param str Uppercase string
 * @param k Maximum number of character replacements allowed
 * @return Length of the longest valid substring
 */
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
/**
 * Runs an assertion-based test for findLongestSubstring.
 *
 * @param str Input string to test
 * @param k Maximum number of replacements
 * @param expected Expected longest length
 */
void submitForTesting(string str, int k, int expected) {
    testCount++;
    int longestSize = findLongestSubstring(str, k);

    assert(longestSize == expected);
    cout << "Test no. " << testCount << " is done." << endl;
}

/**
 * Executes sample test cases.
 */
int main() {
    submitForTesting("ABAB", 2, 4);
    submitForTesting("AABABBA", 1, 4);

    return 0;
}