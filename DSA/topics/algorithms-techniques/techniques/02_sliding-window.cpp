/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                   🪟 SLIDING WINDOW                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 The sliding window technique is a very useful that helps us to find and process on "continuous part" of data efficiently. Instead of checking every possible values we maintain a window by "kth" elements and   |
|     perform operation on it.                                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
| 🟡 Instead of recalculating everything, If it breaks conditions than we remove elements from "left" and shift the window by adding from "right" after performing calculation.                                       |
|                                                                                                                                                                                                                     |
| 🔷 Example:                                                                                                                                                                                                         |
|                                                                                                                                                                                                                     |
|            🟡 arr = [2, 1, 5, 1, 3, 2]                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
|            🟡 k = 3                                                                                                                                                                                                 |
|                                                                                                                                                                                                                     |
|            🟡 Windows are:                                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                        [2, 1, 5]                                                                                                                                                                                    |
|                        [1, 5, 1]                                                                                                                                                                                    |
|                        [5, 1, 3]                                                                                                                                                                                    |
|                        [1, 3, 2]                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              HOW SLIDING WINDOW WORKS 🪟                                                                                            |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 Step 1: Creating a window                                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
|          🟡 left = 0     // Start of the window                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|          🟡 right = 0   //  End of the window                                                                                                                                                                       |
|                                                                                                                                                                                                                     |
| 🔷 Step 2: Expand Window                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 Move towards "right" to include more elements                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 [2, 1, 5]                                                                                                                                                                                                |
|                                                                                                                                                                                                                     |
| 🔷 Step 3: Process Window                                                                                                                                                                                           |
|                                                                                                                                                                                                                     |
|         🟡 Performing compute on value like "sum", "maximum", "minimum", "number of characters", "count unique values".                                                                                             |
|                                                                                                                                                                                                                     |
| 🔷 Step 4: Shrink Window                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 If it breaks the condition ("size become bigger"), We'll shrink ("move left") pointer.                                                                                                                   |
|                                                                                                                                                                                                                     |
| 🔷 Step 5: Slide Window                                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
|         🟡 Move forward window, "Remove left element", "Add new right element".                                                                                                                                     |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              TYPE OF SLIDING WINDOW 🪟                                                                                              |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 1. Fixed Size Window:                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|       🟡 Find the maximum sum of subarray size "k", Here the window size will be constant, So that we only have to consider the sum if size of the window is "smaller or equal" to "k".                             |
|                                                                                                                                                                                                                     |
| 🔷 2. Variable Size Window:                                                                                                                                                                                         |
|                                                                                                                                                                                                                     |
|       🟡 Here window size are't fixed, It will update based on the condition, Suppose "Find longest substring without repeating characters."                                                                        |
|                                                                                                                                                                                                                     |
|       🟡 Input = "abcabcbb", Output = 3, "Longest Substring is 3". Here the window size if dynamic means it will update based on whether it's longest substring or not.                                             |
|                                                                                                                                                                                                                     |
| 🔷 3. Sliding Window with Frequency Map:                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|       🟡 Here we use "sliding window" + "a frequency map" (For Tracking the elements), Example finding "Find the fruits from the bucket that can hold upto 3 fruits".                                               |
|                                                                                                                                                                                                                     |
|       🟡 fruits = ["apple", "banana", "apple", "orange", "banana"]                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|                   first_window = ["apple" ,"banana", "apple"], Frequency Map = {"apple" -> 2, "banana" -> 1} // Similar with other windows                                                                          |
|                                                                                                                                                                                                                     |
| 🔷 4. Sliding Window with dequeue:                                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|       🟡 Here we use "sliding window" + "deque (doubly ended queue)", It's useful when we want to store elements in a correct order, Like for storing "maximum" or "minimum" value.                                 |
|                                                                                                                                                                                                                     |
|       🟡 In "doubly ended" queue it's possible to store, remove elements on both "front" and "start" position, Which helps to maintain order of elements like large value will be at "front" and small at "back".   |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              ALL SLIDING WINDOW PATTERNS 🪟                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 Pattern 1: Fixed Size Window:                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
|                                 🟡 Window size if fixed one step at a time, Suppose problem statement contains "subarray size of k", "substring length k". So find thing we have is "sliding window".               |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 2: Longest/Shortest Valid Window:                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
|                                 🟡 Expand Window Until condition breaks, Like "Find longest Subarray", "Find longest Substring", "Minimum Window", "Smallest Subarray".                                             |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 3: At Most K Distinct Elements:                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                                 🟡 Window allows maximum k unique elements.                                                                                                                                         |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 4: Exactly K Distinct Elements:                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                                 🟡 Find extract "k" distinct elements.                                                                                                                                              |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 5: Anagram Matching:                                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|                                 🟡 Compare Characters Frequency, "find anagram", "permutation of string".                                                                                                           |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>

#include <format>

#include "../../../dsa_utils.h"

using namespace std;

/**
 * Checks whether a character is a vowel.
 *
 * Given a single character, determine whether it is one of the lowercase
 * vowels: a, e, i, o, or u.
 *
 * Example:
 * Input: ch = 'a'
 * Output: true
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * @param ch Character to check
 * @return True if the character is a vowel, otherwise false
 */
bool isVowel(char ch) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for (const char& c : vowels) {
        if (c == ch)
            return true;
    }

    return false;
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟SLIDING WINDOW EASY PROBLEMS                                                                                           |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace easy_problems {
    /**
     * Finds the maximum sum of any contiguous subarray of size k.
     *
     * Given an integer array and a window size k, return the largest sum among
     * all contiguous subarrays of length k.
     *
     * Example:
     * Input: numbers = [2, 1, 5, 1, 3, 2], k = 3
     * Output: 9
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers Input array of integers
     * @param target Window size
     * @return Maximum sum of any subarray of size k
     */
    int computeMaximumSumWithTarget(const vector<int>& numbers, int target) {
        if (target == static_cast<int>(numbers.size()))
            return 0;

        size_t leftWindow  = 0;
        size_t rightWindow = 0;

        int maxSum   = 0;
        int totalSum = 0;

        while (rightWindow < numbers.size()) {
            // Step 1. Calculating sum using rightWindow.
            totalSum += numbers[rightWindow];

            // Step 2. Size become equal to target - 1;
            if ((rightWindow - leftWindow) == target - 1) {
                maxSum = max(maxSum, totalSum);
                totalSum -= numbers[leftWindow];
                leftWindow++;
            }

            rightWindow++;
        }

        return maxSum;
    }

    /**
     * Computes the average of every contiguous subarray of size k.
     *
     * Given an integer array and a window size k, return the average of each
     * contiguous subarray of length k.
     *
     * Example:
     * Input: numbers = [1, 3, 2, 6, -1, 4, 1, 8, 2], k = 5
     * Output: [2.2, 2.8, 2.4, 3.6, 2.8]
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n) for the output list
     *
     * @param numbers Input array of integers
     * @param target Window size
     * @return A vector of averages for each size-k window
     */
    vector<float> computeAverageSumWithTarget(const vector<int>& numbers, int target) {
        if (numbers.size() == target)
            return {};

        vector<float> sumOfAverage = {};

        size_t leftWindow  = 0;
        size_t rightWindow = 0;

        int totalSum = 0;

        while (rightWindow < numbers.size()) {
            // Step 1. Calculate right value into "totalSum"
            totalSum += numbers[rightWindow];

            // Step 2. If Total size got bigger than target
            if ((rightWindow - leftWindow) == target - 1) {
                sumOfAverage.push_back((float)totalSum / target);
                totalSum -= numbers[leftWindow];
                leftWindow++;
            }

            rightWindow++;
        }

        return sumOfAverage;
    }

    /**
     * Finds the maximum number of vowels in any substring of size k.
     *
     * Given a string and a fixed window size k, return the maximum number of
     * vowels found in any contiguous substring of length k.
     *
     * Example:
     * Input: str = "abciiidef", k = 3
     * Output: 3
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param str Input string
     * @param target Window size
     * @return Maximum vowel count across all size-k substrings
     */
    int countMaximumVowelInSubstring(string str, int target) {
        if (str.size() == target)
            return 0;

        int leftWindow  = 0;
        int rightWindow = 0;

        int vowelCount    = 0;
        int maxVowelCount = 0;

        while (rightWindow < str.size()) {
            // Step 1. If right string is vowel increase the "vowelCount" by 1.
            if (isVowel(str[rightWindow]))
                vowelCount++;

            // Step 2. If window size become greater than target.
            if ((rightWindow - leftWindow) == target - 1) {
                maxVowelCount = max(maxVowelCount, vowelCount);

                // Only decrease if left str is vowel.
                if (isVowel(str[leftWindow]))
                    vowelCount--;

                leftWindow++;
            }

            rightWindow++;
        }

        return maxVowelCount;
    }

    /**
     * Checks whether any duplicate exists inside a window of size k.
     *
     * Given an array and a window size k, return true if any contiguous window
     * of length k contains a repeated value.
     *
     * Example:
     * Input: numbers = [1, 2, 1, 3, 6, 8], k = 3
     * Output: true
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k)
     *
     * @param numbers Input array
     * @param target Window size to inspect
     * @return True if a duplicate exists within any size-k window
     */
    bool checkContainsTwoDuplicates(const vector<int>& numbers, int target) {
        if (numbers.size() < target)
            return false;

        size_t leftWindow  = 0;
        size_t rightWindow = 0;

        unordered_map<int, bool> window;

        while (rightWindow < numbers.size()) {
            if (window.count(numbers[rightWindow]))
                return true;

            window.insert({numbers[rightWindow], true});

            if ((rightWindow - leftWindow) >= target) {
                window.erase(numbers[leftWindow]);
                leftWindow++;
            }

            rightWindow++;
        }

        return false;
    }

    /**
     * Finds the length of the longest substring without repeating characters.
     *
     * Given a string, return the length of the longest contiguous substring
     * that contains no repeated characters.
     *
     * Example:
     * Input: str = "abcabcbb"
     * Output: 3
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param str Input string
     * @return Length of the longest substring with all unique characters
     */
    int findUniqueLongestSubstring(string str) {
        size_t size = str.size();

        size_t leftIndex  = 0;
        size_t rightIndex = 0;

        unordered_map<char, int> lastSeen;

        int longestSubstring = 0;

        for (rightIndex = 0; rightIndex < size; rightIndex++) {
            if (lastSeen.count(str[rightIndex]) && lastSeen[str[rightIndex]] >= leftIndex) {
                int windowLength = rightIndex - leftIndex;
                longestSubstring = max(longestSubstring, windowLength);

                leftIndex = lastSeen[str[rightIndex]] + 1;
            }

            lastSeen[str[rightIndex]] = rightIndex;
        }

        int remainingWindowLength = rightIndex - leftIndex;
        longestSubstring          = max(longestSubstring, remainingWindowLength);

        return longestSubstring;
    }

    void main() {
        cout << "Sliding Window Easy Problems: " << endl;

        // FINDING MAXIMUM SUM WITH TARGET
        vector<int> maximumSumNumbers = {2, 1, 5, 1, 3, 2};
        print(computeMaximumSumWithTarget(maximumSumNumbers, 3),
              std::format("Maximum sum with target {} is: ", 3));

        // AVERAGE OF A SUBARRAY SIZE K
        vector<int> averageSumNumbers = {1, 3, 2, 6, -1, 4, 1, 8, 2};
        print(computeAverageSumWithTarget(averageSumNumbers, 5),
              "Average Sums with target 5 are: ");

        // MAX VOWEL COUNT OF A SUBSTRING
        print(countMaximumVowelInSubstring("abciiidef", 3),
              "Maximum vowel count of a substring size 3 is: ");

        // CHECKING DUPLICATE WITH TARGET K
        vector<int> duplicateNumbers = {1, 2, 1, 3, 6, 8};
        print(checkContainsTwoDuplicates(duplicateNumbers, 3), "Is numbers has duplicate number: ");

        // LONGEST UNIQUE SUBSTRING
        string duplicateStr = "abcabcbbieouvx";
        print(findUniqueLongestSubstring(duplicateStr), "Longest Unique Substring is: ");
    }
}  // namespace easy_problems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                           🪟 SLIDING WINDOW MEDIUM PROBLEMS                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace medium_problems {
    /**
    * Finds the length of the longest substring that can be made of one repeated character.
    *
    * Given a string of uppercase letters and an integer minLength, return the
    * maximum length of a contiguous substring that can be turned into all the
    * same character by replacing at most minLength characters.
     *
     * Example:
    * Input: str = "ABBCBKK", minLength = 1
     * Output: 4
    * Explanation: Replace one character in a length-4 window to make all
    * characters identical.
     *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
     *
    * @param str Input string of uppercase letters
    * @param minLength Maximum number of replacements allowed
    * @return Length of the longest valid substring
     */
    int findLongestRepeatingSubstring(string str, int minLength) {
        int leftIndex  = 0;
        int rightIndex = 0;

        int maxFrequency       = 0;
        int maxSubstringLength = 0;

        vector<int> charFrequencyCount(26, 0);

        while (rightIndex < str.size()) {
            charFrequencyCount[str[rightIndex] - 'A']++;
            // Tracking the number which is most dominant.
            maxFrequency = max(maxFrequency, charFrequencyCount[str[rightIndex] - 'A']);

            // If most dominant number - current window size, become greater than "minLength".
            // Means there is an element Who is not same and we already replace it, Now we need to reduce the size.
            while ((rightIndex - leftIndex + 1) - maxFrequency > minLength) {
                charFrequencyCount[str[leftIndex] - 'A']--;
                leftIndex++;
            }

            maxSubstringLength = max(maxSubstringLength, rightIndex - leftIndex + 1);
            rightIndex++;
        }

        return maxSubstringLength;
    }

    /**
        * Finds the length of the longest subarray with at most k distinct values.
        *
        * Given an array of fruit types and a limit on the number of distinct types,
        * return the maximum number of fruits that can be collected from one window.
     *
     * Example:
    * Input: fruits = [1, 2, 1, 2, 3], maximumAllowedType = 2
     * Output: 4
    * Explanation: The best window is [1, 2, 1, 2].
     *
    * Time Complexity: O(n)
    * Space Complexity: O(k)
     *
    * @param fruits Input array representing fruit types
    * @param maximumAllowedType Maximum number of distinct fruit types allowed
    * @return Maximum window length that satisfies the constraint
     */
    int findMaximumNumberOfFruits(const vector<int>& fruits, int maximumAllowedType) {
        int leftIndex      = 0;
        int maxFruitsCount = 0;

        unordered_map<int, int> bucketsWithLastSeen;

        for (int rightIndex = 0; rightIndex < fruits.size(); rightIndex++) {
            bucketsWithLastSeen[fruits[rightIndex]]++;

            while (bucketsWithLastSeen.size() > maximumAllowedType) {
                bucketsWithLastSeen[fruits[leftIndex]]--;

                if (bucketsWithLastSeen[fruits[leftIndex]] == 0)
                    bucketsWithLastSeen.erase(fruits[leftIndex]);

                leftIndex++;
            }

            maxFruitsCount = max(maxFruitsCount, rightIndex - leftIndex + 1);
        }

        return maxFruitsCount;
    }

    /**
        * Finds the minimum length of a contiguous subarray whose sum reaches a target.
        *
        * Given a positive integer array and a target sum, return the shortest
        * contiguous subarray whose sum is greater than or equal to the target.
     *
     * Example:
    * Input: numbers = [2, 3, 1, 2, 4, 3], target = 7
     * Output: 2
    * Explanation: The subarray [4, 3] has the smallest valid length.
     *
    * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
    * @param numbers Input array of positive integers
    * @param target Target sum to reach or exceed
    * @return Minimum length of a valid subarray, or 0 if none exists
     */
    int findMinimumSizeSubarraySum(const vector<int>& numbers, int target) {
        int leftIndex = 0;

        int totalSum      = 0;
        int minTargetSize = INT_MAX;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            totalSum += numbers[rightIndex];

            while (totalSum >= target) {
                minTargetSize = min(minTargetSize, rightIndex - leftIndex + 1);

                totalSum -= numbers[leftIndex];
                leftIndex++;
            }
        }

        return minTargetSize == INT_MAX ? 0 : minTargetSize;
    }

    // TODO: 👉 Ask yourself:
    //                        Can we detect duplicates earlier instead of waiting for full window?

    // 💡 Tiny direction:
    //                    Think about what to do immediately when a duplicate enters the window

    /**
        * Finds the maximum sum of any subarray of size k with all distinct values.
        *
        * Given an integer array and a window size k, return the maximum sum among
        * all contiguous subarrays of length k that contain no duplicate values.
     *
     * Example:
    * Input: numbers = [1, 5, 4, 2, 9, 9, 9], k = 3
     * Output: 15
    * Explanation: The best valid window is [4, 2, 9] with sum 15.
     *
    * Time Complexity: O(n)
    * Space Complexity: O(k)
     *
    * @param numbers Input array of integers
    * @param k Required window size
    * @return Maximum sum of a valid distinct-size-k subarray, or 0 if none exists
     */
    int findMaximumSumOfDistinctArray(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        int maxSum   = 0;
        int totalSum = 0;

        unordered_map<int, int> freq;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            totalSum += numbers[rightIndex];
            freq[numbers[rightIndex]]++;

            while ((rightIndex - leftIndex + 1) > k) {
                totalSum -= numbers[leftIndex];
                freq[numbers[leftIndex]]--;

                if (freq[numbers[leftIndex]] == 0)
                    freq.erase(numbers[leftIndex]);

                leftIndex++;
            }

            if ((rightIndex - leftIndex + 1) == k && freq.size() == k) {
                maxSum = max(maxSum, totalSum);
            }
        }

        return maxSum;
    }

    /**
        * Finds the length of the longest subarray of 1s after flipping at most k zeros.
        *
        * Given a binary array and an integer k, return the maximum length of a
        * contiguous subarray containing only 1s after flipping at most k zeros.
     *
     * Example:
    * Input: numbers = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
     * Output: 6
    * Explanation: Flip two zeros to make a window of length 6 containing only 1s.
     *
    * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
    * @param numbers Binary input array of 0s and 1s
    * @param k Maximum number of zeros that can be flipped
    * @return Length of the longest valid subarray
     */
    int findLongestOnesAfterKFlips(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        int maximumSize     = 0;
        int windowZeroCount = 0;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            if (numbers[rightIndex] == 0)
                windowZeroCount++;

            while (windowZeroCount > k) {
                if (numbers[leftIndex] == 0)
                    windowZeroCount--;

                leftIndex++;
            }

            maximumSize = max(maximumSize, (rightIndex - leftIndex + 1));
        }

        return maximumSize;
    }

    void main() {
        cout << "Sliding Window Medium Problems: " << endl;

        // FINDING LONGEST REPEATING SUBSTRINGS
        string str       = "ABBCBKK";
        int    minLength = 1;

        print(findLongestRepeatingSubstring(str, minLength), "Maximum possible substring is: ");

        // FINDING MAXIMUM NUMBER OF FRUIT A BUCKET HAS
        vector<int> fruits = {1, 2, 1, 2, 3};
        print(findMaximumNumberOfFruits(fruits, 2), "Maximum fruit count is: ");

        // FINDING SUM OF SUBARRAY BUT WITH MINIMUM SIZE
        vector<int> numbers = {2, 3, 1, 2, 4, 3};
        print(findMinimumSizeSubarraySum(numbers, 7), "Minimum size of a subarray is: ");

        // FINDING MAXIMUM SUM OF K DISTINCT ARRAY
        vector<int> numbers2 = {1, 5, 4, 2, 9, 9, 9};
        print(findMaximumSumOfDistinctArray(numbers2, 3), "Maximum sum of k distinct array is: ");

        // Find longest subarray containing 1 by flipping 0 K times.
        vector<int> oneZero = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        print(findLongestOnesAfterKFlips(oneZero, 2), "Longest Subarray containing 1's is: ");
    }
}  // namespace medium_problems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW HARD PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hard_problems {
    /**
     * Finds the smallest substring that contains every character from a pattern.
     *
     * Given a source string and a pattern string, return the shortest contiguous
     * substring of the source that contains all characters of the pattern.
     *
     * Example:
     * Input: str = "aaabc", pattern = "abc"
     * Output: "abc"
     *
     * Time Complexity: O(n)
     * Space Complexity: O(m)
     *
     * @param str Source string
     * @param pattern Pattern string whose characters must be covered
     * @return The smallest valid substring, or an empty string if none exists
     */
    string findMinimumWindowSubstring(string str, string pattern) {
        int leftIndex = 0;

        int formedCount   = 0;
        int requiredCount = pattern.size();

        int startIndex       = -1;
        int minSubstringSize = INT_MAX;

        unordered_map<char, int> freq;

        // Step 1: Pre-computing frequency map
        for (char ch : pattern) {
            freq[ch]++;
        }

        for (int rightIndex = 0; rightIndex < str.size(); rightIndex++) {
            // Step 2: Expand window
            if (freq.count(str[rightIndex])) {
                if (freq[str[rightIndex]] > 0) {
                    formedCount++;
                }
                freq[str[rightIndex]]--;
            }

            // Step 3: Shrink window
            while (formedCount == requiredCount) {
                int windowSize = rightIndex - leftIndex + 1;
                if (windowSize < minSubstringSize) {
                    minSubstringSize = windowSize;
                    startIndex       = leftIndex;
                }

                if (freq.count(str[rightIndex])) {
                    if (freq[str[leftIndex]] == 0) {
                        formedCount--;
                    }
                    freq[str[leftIndex]]++;
                }

                leftIndex++;
            }
        }

        return startIndex == -1 ? "" : str.substr(startIndex, minSubstringSize);
    }

    /**
     * Finds the maximum value in every contiguous subarray of size k.
     *
     * Given an array and a window size k, return a list containing the maximum
     * value from each window.
     *
     * Example:
     * Input: numbers = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
     * Output: [3, 3, 5, 5, 6, 7]
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k)
     *
     * @param numbers Input array
     * @param k Window size
     * @return Maximum values for each window
     */
    vector<int> findMaximumWindow(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        deque<int>  deq;
        vector<int> maximumValues = {};

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            // Step 1: Remove smaller from back
            while (!deq.empty() && numbers[deq.back()] < numbers[rightIndex]) {
                deq.pop_back();
            }

            // Add current index
            deq.push_back(rightIndex);

            // Step 2: Remove elements out of window
            if (!deq.empty() && deq.front() <= rightIndex - k) {
                deq.pop_front();
            }

            // Step 3: Store result when window is valid
            if (rightIndex >= k - 1) {
                maximumValues.push_back(numbers[deq.front()]);
            }
        }

        return maximumValues;
    }

    /**
     * Placeholder for the minimum window subsequence problem.
     *
     * Given a source string and a target string, the goal is to find the
     * shortest subsequence window that matches the target in order.
     *
     * Example:
     * Input: str = "abcdebdde", target = "bde"
     * Output: "bcde"
     *
     * Time Complexity: Not implemented
     * Space Complexity: Not implemented
     *
     * @param str Source string
     * @param target Target string
     * @return Currently returns an empty string
     */
    string findMinimumWindowSequence(string str, string target) {
        return "";
    }

    /**
     * Placeholder for the maximum number of robots within a budget problem.
     *
     * Given robot costs or efficiencies, determine the maximum number of robots
     * that can be selected under a cost constraint.
     *
     * Example:
     * Input: robot = [3, 6, 1, 3, 4], budget = 15
     * Output: depends on the final problem definition
     *
     * Time Complexity: Not implemented
     * Space Complexity: Not implemented
     *
     * @param robot Input robot values
     * @return Currently returns 0
     */
    int findMaximumNumberOfRobots(const vector<int>& robot) {
        return 0;
    }

    /**
     * Placeholder for counting subarrays with fixed bounds.
     *
     * Given an array and boundary values, count the subarrays whose minimum and
     * maximum values stay within the required bounds.
     *
     * Example:
     * Input: number = [1, 3, 5, 2, 7, 5], bounds = [1, 5]
     * Output: depends on the final problem definition
     *
     * Time Complexity: Not implemented
     * Space Complexity: Not implemented
     *
     * @param number Input array
     * @return Currently returns 0
     */
    int findSubarraysWithFixedBounds(const vector<int>& number) {
        return 0;
    }

    void main() {
        cout << "Sliding Window Hard Problems: " << endl;

        // Finding minimum substring containing all elements.
        string str = "aaabc", pattern = "abc";
        cout << "Minimum substring containing all elements from pattern is: "
             << findMinimumWindowSubstring(str, pattern) << endl;

        // Finding Maximum Value in a "k" window size.
        vector<int> numbers = {1, 3, -1, -3, 5, 3, 6, 7};
        cout << "Maximum numbers are: ";
        for (int n : findMaximumWindow(numbers, 3)) {
            cout << n << " ";
        }
        cout << endl;

        cout << endl << endl;
    }
}  // namespace hard_problems

int main() {
    // Calling main functions
    easy_problems::main();
    medium_problems::main();
    hard_problems::main();

    return 0;
}
