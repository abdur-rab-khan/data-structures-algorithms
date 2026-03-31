/*
╔════════════════════════════════════════════════════════════════════════════════════════╗
║                    🎯 SLIDING WINDOW - QUICK CHEAT SHEET 🎯                           ║
╚════════════════════════════════════════════════════════════════════════════════════════╝

┌────────────────────────────────────────────────────────────────────────────────────────┐
│ ⚡ KEY PATTERNS                                                                        │
├────────────────────────────────────────────────────────────────────────────────────────┤
│                                                                                        │
│  1. FIXED SIZE:    while(right - left == k-1) { process(); left++; }                   │
│  2. AT MOST K:     while(freq.size() > k) { shrink(); }                                │
│  3. SUM >= TARGET: while(sum >= target) { update(); shrink(); }                        │
│  4. NO DUPLICATES: if(freq[char] > 0) left = last_seen[char] + 1;                      │
│  5. MAX FREQ:      while(winsize - maxfreq > k) { shrink(); }                          │
│  6. Types of Sliding window:                                                           │
│                                                                                        │
└────────────────────────────────────────────────────────────────────────────────────────┘

 ⏱️  Always O(n) | 💡 Left pointer never goes backwards
*/








































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
#include "../dsa_utils.hpp"

using namespace std;

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
    int computeMaximumSumWithTarget(const vector<int>& numbers, int target) {
        if (numbers.size() == target)
            return 0;

        size_t leftWindow = 0;
        size_t rightWindow = 0;

        int maxSum = 0;
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

    vector<float> computeAverageSumWithTarget(const vector<int>& numbers, int target) {
        if (numbers.size() == target)
            return {};

        vector<float> sumOfAverage = {};

        size_t leftWindow = 0;
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

    int countMaximumVowelInSubstring(string str, int target) {
        if (str.size() == target)
            return 0;

        int leftWindow = 0;
        int rightWindow = 0;

        int vowelCount = 0;
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

    bool checkContainsTwoDuplicates(const vector<int>& numbers, int target) {
        if (numbers.size() < target)
            return false;

        size_t leftWindow = 0;
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

    int findUniqueLongestSubstring(string str) {
        size_t size = str.size();

        size_t leftIndex = 0;
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
        longestSubstring = max(longestSubstring, remainingWindowLength);

        return longestSubstring;
    }

    // Main function
    void main() {
        cout << "Sliding Window Easy Problems: " << endl;

        // FINDING MAXIMUM SUM WITH TARGET
        vector<int> maximumSumNumbers = {2, 1, 5, 1, 3, 2};

        cout << "Maximum sum with target " << 3
             << " is: " << computeMaximumSumWithTarget(maximumSumNumbers, 3) << endl;

        // AVERAGE OF A SUBARRAY SIZE K
        vector<int> averageSumNumbers = {1, 3, 2, 6, -1, 4, 1, 8, 2};

        printArrayElements<float>(computeAverageSumWithTarget(averageSumNumbers, 5),
                                  "Average Sums with target 5 are: ");

        // MAX VOWEL COUNT OF A SUBSTRING
        string str = "abciiidef";

        cout << "Maximum vowel count of a substring size 3 is: "
             << countMaximumVowelInSubstring(str, 3) << endl;

        cout << endl << endl;

        // CHECKING DUPLICATE WITH TARGET K
        vector<int> duplicateNumbers = {1, 2, 1, 3, 6, 8};

        cout << "Is numbers has duplicate number: "
             << checkContainsTwoDuplicates(duplicateNumbers, 3) << endl;

        // LONGEST UNIQUE SUBSTRING
        string duplicateStr = "abcabcbbieouvx";

        cout << "Longest Unique Substring is: " << findUniqueLongestSubstring(duplicateStr) << endl;
    }
}  // namespace easy_problems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                           🪟 SLIDING WINDOW MEDIUM PROBLEMS                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace medium_problems {
    /**
     * Finds the length of the longest repeating character replacement substring.
     *
     * Given a string, finds the maximum length of a contiguous substring where you
     * can replace at most 'minLength' characters to make all characters in the substring identical.
     *
     * Example:
     * Input: str = "ABBCBKK", minLength = 1
     * Output: 4
     * Explanation: Replace one 'C' with 'B' to get "BBBB" (length 4), or replace 'B' with 'K' to
     * get "KKKK" (length 4).
     *
     * Time Complexity: O(n) where n is the length of the string
     * Space Complexity: O(1) space for the frequency array of 26 uppercase letters
     *
     * @param str The original string of characters
     * @param minLength Maximum number of characters that can be replaced
     * @return Length of the longest substring with identical characters after replacements
     */
    int findLongestRepeatingSubstring(string str, int minLength) {
        /*
        Problem: Given a string, find the length of the longest substring where you can replace at
        most 'minLength' characters to make all characters in the substring the same.

        Example:
        Input: str = "ABBCBKK", minLength = 1
        Output: 4
        Explanation: Replace one 'C' with 'B' to get "BBBB" or one 'B' with 'K' to get "KKKK".
        */

        int leftIndex = 0;
        int rightIndex = 0;

        int maxSubstringLength = 0;
        int maxFrequency = 0;

        vector<int> charFrequencyCount(26, 0);

        while (rightIndex < str.size()) {
            charFrequencyCount[str[rightIndex] - 'A']++;
            maxFrequency = max(maxFrequency, charFrequencyCount[str[rightIndex] - 'A']);

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
     * Finds the maximum number of fruits that can be collected.
     *
     * Finds the length of the longest contiguous subarray that contains at most
     * 'maximumAllowedType' distinct elements (representing different types of fruit).
     *
     * Example:
     * Input: fruits = [1, 2, 1, 2, 3], maximumAllowedType = 2
     * Output: 4
     * Explanation: The longest subarray with at most 2 distinct types is [1, 2, 1, 2] with
     * length 4.
     *
     * Time Complexity: O(n) where n is the number of fruits
     * Space Complexity: O(k) where k is the maximumAllowedType (size of the hash map)
     *
     * @param fruits Array representing the types of fruit available
     * @param maximumAllowedType Maximum number of different fruit types allowed
     * @return Maximum number of fruits you can collect
     */
    int findMaximumNumberOfFruits(const vector<int>& fruits, int maximumAllowedType) {
        int leftIndex = 0;
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
     * Finds the minimal length of a contiguous subarray with sum >= target.
     *
     * Given an array of positive integers and a target integer, finds the
     * minimum length of a contiguous subarray whose sum is greater than or equal to the target.
     * If there is no such subarray, returns 0.
     *
     * Example:
     * Input: numbers = [2, 3, 1, 2, 4, 3], target = 7
     * Output: 2
     * Explanation: The subarray [4, 3] has the minimal length (2) under the problem constraint.
     *
     * Time Complexity: O(n) where n is the number of elements
     * Space Complexity: O(1)
     *
     * @param numbers Array of integers
     * @param target The target sum to reach or exceed
     * @return Minimum length of a valid subarray, or 0 if none exists
     */
    int findMinimumSizeSubarraySum(const vector<int>& numbers, int target) {
        int leftIndex = 0;

        int totalSum = 0;
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
     * Finds the maximum sum of a distinct subarray of size k.
     *
     * Finds the maximum sum of a contiguous subarray of size exactly 'k'
     * where all elements in the subarray are distinct.
     *
     * Example:
     * Input: numbers = [1, 5, 4, 2, 9, 9, 9], k = 3
     * Output: 15
     * Explanation: The subarrays of length 3 are:
     *              [1, 5, 4] -> sum: 10 (distinct)
     *              [5, 4, 2] -> sum: 11 (distinct)
     *              [4, 2, 9] -> sum: 15 (distinct)
     *              [2, 9, 9] -> invalid (contains duplicate 9s)
     *              Max valid sum is 15.
     *
     * Time Complexity: O(n) where n is the number of elements
     * Space Complexity: O(k) for the hash map to store frequencies of the current window
     *
     * @param numbers Array of integers
     * @param k The exact size of the distinct subarray
     * @return Maximum sum of a valid subarray, or 0 if no such subarray exists
     */
    int findMaximumSumOfDistinctArray(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        int maxSum = 0;
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
     * Given an array containing only 0s and 1s, find the maximum length of a subarray
     * that can be obtained by flipping at most k zeros to ones.
     *
     * Example:
     * Input: numbers = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
     * Output: 6
     * Explanation: Flip the two zeros at indices 3 and 4 to get [1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0]
     *              The longest subarray of 1s is [1, 1, 1, 1, 1] with length 6.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers Array of 0s and 1s
     * @param k Maximum number of zeros that can be flipped
     * @return Length of longest subarray of 1s after flipping at most k zeros
     */
    int findLongestOnesAfterKFlips(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        int maximumSize = 0;
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

    // Main function
    void main() {
        cout << "Sliding Window Medium Problems: " << endl;

        // FINDING LONGEST REPEATING SUBSTRINGS
        string str = "ABBCBKK";
        int minLength = 1;

        cout << "Maximum possible substring is: " << findLongestRepeatingSubstring(str, minLength);
        cout << endl << endl;

        // FINDING MAXIMUM NUMBER OF FRUIT A BUCKET HAS
        vector<int> fruits = {1, 2, 1, 2, 3};
        cout << "Maximum fruit count is: " << findMaximumNumberOfFruits(fruits, 2) << endl;
        ;

        // FINDING SUM OF SUBARRAY BUT WITH MINIMUM SIZE
        vector<int> numbers = {2, 3, 1, 2, 4, 3};
        cout << "Minimum size of a subarray is: " << findMinimumSizeSubarraySum(numbers, 7) << endl;

        // FINDING MAXIMUM SUM OF K DISTINCT ARRAY
        vector<int> numbers2 = {1, 5, 4, 2, 9, 9, 9};
        cout << "Maximum sum of k distinct array is: " << findMaximumSumOfDistinctArray(numbers2, 3)
             << endl;

        // Find longest subarray containing 1 by flipping 0 K times.
        vector<int> oneZero = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        cout << "Longest Subarray containing 1's is: " << findLongestOnesAfterKFlips(oneZero, 2)
             << endl;
    }
}  // namespace medium_problems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW HARD PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hard_problems {
    string findMinimumWindowSubstring(string str, string pattern) {
        int leftIndex = 0;

        int formedCount = 0;
        int requiredCount = pattern.size();

        int startIndex = -1;
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
                    startIndex = leftIndex;
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

    vector<int> findMaximumWindow(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        deque<int> deq;
        vector<int> maximumValues = {};

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++){
            // Step 1: Remove smaller from back 
            while(!deq.empty() && numbers[deq.back()] < numbers[rightIndex]){
                deq.pop_back();
            }
            
            // Add current index
            deq.push_back(rightIndex);

            // Step 2: Remove elements out of window 
            if(!deq.empty() && deq.front() <= rightIndex - k){
                deq.pop_front();
            }

            // Step 3: Store result when window is valid
            if(rightIndex >= k - 1){
                maximumValues.push_back(numbers[deq.front()]);
            }
        }

        return maximumValues;
    }

    string findMinimumWindowSequence(string str, string target) {
        // LOGIC TO HANDLE IT.
        return "";
    }

    int findMaximumNumberOfRobots(const vector<int>& robot) {
        // LOGIC TO HANDLE IT.
        return 0;
    }

    int findSubarraysWithFixedBounds(const vector<int>& number) {
        // LOGIC TO HANDLE IT.
        return 0;
    }

    // Main function
    void main() {
        cout << "Sliding Window Hard Problems: " << endl;

        // Finding minimum substring containing all elements.
        string str = "aaabc", pattern = "abc";
        cout << "Minimum substring containing all elements from pattern is: " << findMinimumWindowSubstring(str, pattern) << endl;
        
        // Finding Maximum Value in a "k" window size.
        vector<int> numbers = {1, 3, -1, -3, 5, 3, 6, 7};
        cout << "Maximum numbers are: ";
        for(int n : findMaximumWindow(numbers, 3)){
            cout << n << " ";
        }
        cout << endl;

        cout << endl << endl;
    }
}  // namespace hard_problems

int main() {
    // Calling main functions
    // easy_problems::main();
    // medium_problems::main();
    hard_problems::main();

    return 0;
}