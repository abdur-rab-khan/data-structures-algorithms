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

bool isVowel(char ch){
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for(const char& c: vowels){
        if(c == ch)
            return true;
    }

    return false;
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW EASY PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace easy_problems {
    int computeMaximumSumWithTarget(const vector<int>& numbers, int target){
        if(numbers.size() == target)
            return 0;

        size_t leftWindow = 0;
        size_t rightWindow = 0;

        int maxSum = 0;
        int totalSum = 0;

        while(rightWindow < numbers.size()){
           // Step 1. Calculating sum using rightWindow.
            totalSum += numbers[rightWindow];

            // Step 2. Size become equal to target - 1;
            if((rightWindow - leftWindow) == target - 1){
                maxSum = max(maxSum, totalSum);
                totalSum -= numbers[leftWindow];
                leftWindow++;
            }

            rightWindow++;
        }

        return maxSum;
    }
   
    vector<float> computeAverageSumWithTarget(const vector<int>& numbers, int target){
        if(numbers.size() == target)
            return {};

        vector<float> sumOfAverage = {};

        size_t leftWindow = 0;
        size_t rightWindow = 0;

        int totalSum = 0;

        while(rightWindow < numbers.size()){
            // Step 1. Calculate right value into "totalSum"
            totalSum += numbers[rightWindow];

            // Step 2. If Total size got bigger than target
            if((rightWindow - leftWindow) == target - 1){
                sumOfAverage.push_back((float)totalSum / target);
                totalSum -= numbers[leftWindow];
                leftWindow++;
            }

            rightWindow++;
        }

        return sumOfAverage;
    }
    
    int countMaximumVowelInSubstring(string str, int target) {
        if(str.size() == target)
            return 0;

        int leftWindow = 0;
        int rightWindow = 0;

        int vowelCount = 0;
        int maxVowelCount = 0;

        while(rightWindow < str.size()){
            // Step 1. If right string is vowel increase the "vowelCount" by 1. 
            if(isVowel(str[rightWindow]))
                vowelCount++;

            // Step 2. If window size become greater than target.
            if((rightWindow - leftWindow) == target - 1){
                maxVowelCount = max(maxVowelCount, vowelCount);

                // Only decrease if left str is vowel.
                if(isVowel(str[leftWindow]))
                    vowelCount--;

                leftWindow++;
            }

            rightWindow++;
        }

        return maxVowelCount;
    }

    bool checkContainsTwoDuplicates(const vector<int>& numbers, int target){
        if(numbers.size() < target)
            return false;

        size_t leftWindow = 0;
        size_t rightWindow = 0;

        unordered_map<int, bool> window;

        while(rightWindow < numbers.size()){
            if(window.count(numbers[rightWindow]))
                return true;
            
            window.insert({numbers[rightWindow], true});

            if((rightWindow - leftWindow) >= target){
                window.erase(numbers[leftWindow]);
                leftWindow++;
            }

            rightWindow++;
        }

        return false;
    }

    int findUniqueLongestSubstring(string str){
        size_t size = str.size();

        size_t leftIndex = 0;
        size_t rightIndex = 0;

        unordered_map<char, int> lastSeen;

        int longestSubstring = 0;

        for (rightIndex = 0; rightIndex < size; rightIndex++){
            if(lastSeen.count(str[rightIndex]) && lastSeen[str[rightIndex]] >= leftIndex){
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
    void main(){
        cout << "Sliding Window Easy Problems: " << endl;

        // FINDING MAXIMUM SUM WITH TARGET
        vector<int> maximumSumNumbers = {2, 1, 5, 1, 3, 2};

        cout << "Maximum sum with target " << 3
             << " is: " << computeMaximumSumWithTarget(maximumSumNumbers, 3) << endl;

        // AVERAGE OF A SUBARRAY SIZE K
        vector<int> averageSumNumbers = {1, 3, 2, 6, -1, 4, 1, 8, 2};

        printArrayElements<float>(computeAverageSumWithTarget(averageSumNumbers, 5), "Average Sums with target 5 are: ");

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
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                           🪟 SLIDING WINDOW MEDIUM PROBLEMS                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace medium_problems {
    int findLongestRepeatingSubstring(string str, int minLength){
        /*
        Problem: Given a string, find the length of the longest substring where you can replace at most 'minLength' characters to make all characters in the substring the same.

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

        while(rightIndex < str.size()){
            charFrequencyCount[str[rightIndex] - 'A']++;
            maxFrequency = max(maxFrequency, charFrequencyCount[str[rightIndex] - 'A']);

            while((rightIndex - leftIndex + 1) - maxFrequency > minLength) {
               charFrequencyCount[str[leftIndex] - 'A']--;
               leftIndex++;
           }  

            maxSubstringLength = max(maxSubstringLength, rightIndex - leftIndex + 1);
            rightIndex++;
        }

        return maxSubstringLength;
    }
   
    int findMaximumNumberOfFruits(const vector<int>& fruits, int maximumAllowedType){
        int leftIndex = 0;

        int maxFruitsCount = 0;

        unordered_map<int, int> bucketsWithLastSeen;

        for (int rightIndex = 0; rightIndex < fruits.size(); rightIndex++){
            bucketsWithLastSeen[fruits[rightIndex]]++;
            
            if(bucketsWithLastSeen.size() > maximumAllowedType){
                maxFruitsCount = max(maxFruitsCount, rightIndex - leftIndex + 1);
                
                while(bucketsWithLastSeen.size() > maximumAllowedType){
                    bucketsWithLastSeen[leftIndex]--;
                    
                    if(bucketsWithLastSeen[leftIndex] == 0)
                        bucketsWithLastSeen.clear();

                    leftIndex++;
                }
            }
        }

        return maxFruitsCount;
    }
    
    // Main function
    void main(){
        cout << "Sliding Window Medium Problems: " << endl;

        // FINDING LONGEST REPEATING SUBSTRINGS
        string str = "ABBCBKK";
        int minLength = 1;

        cout << "Maximum possible substring is: " << findLongestRepeatingSubstring(str, minLength);

        cout << endl << endl;
    }
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW HARD PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hard_problems {
    // Main function
    void main(){
        cout << "Sliding Window Hard Problems: " << endl;

        cout << endl << endl;
    }
}

int main() {
    // Calling main functions
    // easy_problems::main();
    medium_problems::main();
    // hard_problems::main();

    return 0;
}