/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              🔍 TECHNIQUES USE IN SEARCH                                                                                            |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 1️⃣. "Binary Search":                                                                                                                                                                                                |
|                                                                                                                                                                                                                     |
| 2️⃣. "Two Pointers":                                                                                                                                                                                                 |
|                                                                                                                                                                                                                     |
| 3️⃣. "Sliding Window":                                                                                                                                                                                               |
|                                                                                                                                                                                                                     |
| 4️⃣. "Hash Map/Set":                                                                                                                                                                                                 |
|                                                                                                                                                                                                                     |
| 5️⃣. Linear/Prefix Sum:                                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                  🔍 SEARCHING PATTERN                                                                                               |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Pattern 1. "Classic Binary Search":                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
| 🟡 Pattern 2. "Binary Search on Answer":                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
| 🟡 Pattern 3. "Find First/Last Occurrence":                                                                                                                                                                         |
|                                                                                                                                                                                                                     |
| 🟡 Pattern 4. "Rotated Sorted Array": Normally, Sort array are arranged in an ascending order but in "Rotated Sorted Array" numbers are divided into two part and both two parts are sorted in there own way.       |
|                                       Suppose sorted array looks like this [1, 2, 3, 4, 5, 6, 7], then "rotated array" will looks like this [[4, 5, 6, 7], [1, 2, 3]], We got two parts.                            |
|                                       To solve these problems, We have to find drop point in this case that is "7 and 1" Which find using "middle > last" -> "drop is in right direction", "middle" < "last" -> left |
|                                                                                                                                                                                                                     |
| 🟡 Pattern 5. "Hash Map Search":                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
| 🟡 Pattern 6. "Prefix Sum Search":                                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    🔍 Linear Search                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace linearSearch {
    /**
     * Performs a linear search to find a target value in an array.
     *
     * Scans each element of the array sequentially from the beginning until the
     * target value is found or the end of the array is reached.
     *
     * Example:
     * Input: numbers = [3, 7, 1, 9, 4, 6, 2, 8], targetValue = 6
     * Output: 5
     *
     * Time Complexity: O(n) where n is the total number of elements.
     * Space Complexity: O(1) as no extra space is used.
     *
     * @param numbers The vector of integers to search through.
     * @param targetValue The integer value to find.
     * @return The 0-based index of the target value, or -1 if not found.
     */
    int linearSearch(const vector<int>& numbers, int targetValue) {
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == targetValue) {
                return i;
            }
        }
        return -1;
    }

    void main() {
        int targetValue = 6;
        vector<int> numbers = {3, 7, 1, 9, 4, 6, 2, 8};

        cout << "USING LINEAR SEARCH: " << endl;
        cout << targetValue << " found at: " << linearSearch(numbers, targetValue) << " index."
             << endl;
    }
}  // namespace linearSearch

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    🔍 Binary Search                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 Binary Search required array value should be in sorted manner.                                                                                                                                                   |
|                                                                                                                                                                                                                     |
| 🟡 Step by Step Process of Binary Search.                                                                                                                                                                           |
|                                                                                                                                                                                                                     |
|    1. Find "mid" value of the array.                                                                                                                                                                                |
|    2. If "mid" is equal to "targetValue", Simply we return the index of it.                                                                                                                                         |
|    3. If "mid" become greater than "targetValue", mean "targetValue" is smaller so we again Slice into "mid" again step starts from "1".                                                                            |
|    4. If "mid" become smaller than "targetValue", mean "targetValue" is greater so we should have to start step "1" again from "mid + 1" to "right".                                                                |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace binarySearch {
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
    int iterativeBinarySearch(const vector<int>& numbers, int targetValue) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        while (leftIndex <= rightIndex) {
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            int midValue = numbers[midIndex];

            if (midValue == targetValue) {
                return midIndex;
            }

            // Updating both pointers based on smaller/greater than "targetValue"
            if (midValue > targetValue) {
                rightIndex = midIndex - 1;
            } else {
                leftIndex = midIndex + 1;
            }
        }

        // If "targetValue" not found in this list.
        return -1;
    }

    /**
     * Recursively searches for a target value in a sorted array using Binary Search.
     *
     * Uses the call stack to divide the search interval in half at each step until 
     * the target value is found or the interval is empty.
     *
     * Time Complexity: O(log n) where n is the number of elements.
     * Space Complexity: O(log n) due to the recursive call stack.
     *
     * @param numbers A sorted vector of integers.
     * @param targetValue The target integer to find.
     * @param leftIndex The starting index of the current search interval.
     * @param rightIndex The ending index of the current search interval.
     * @return The index of the target value, or -1 if not found.
     */
    int recursiveBinarySearch(const vector<int>& numbers, int targetValue, int leftIndex,
                              int rightIndex) {
        if (leftIndex > rightIndex)
            return -1;

        const int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        const int midValue = numbers[midIndex];

        // If "midValue" its equal to targetValue.
        if (midValue == targetValue) {
            return midIndex;
        }

        // If "midValue" is greater than targetValue.
        if (midValue > targetValue) {
            return recursiveBinarySearch(numbers, targetValue, leftIndex, midIndex - 1);
        }

        // If "midValue" is smaller than targetValue.
        return recursiveBinarySearch(numbers, targetValue, midIndex + 1, rightIndex);
    }

    void main() {
        int targetValue = 4;
        vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 9};

        cout << "USING BINARY SEARCH (ITERATIVE): " << endl;
        cout << targetValue << " found at: " << iterativeBinarySearch(numbers, targetValue)
             << " index." << endl;

        cout << "USING BINARY SEARCH (RECURSIVE): " << endl;
        cout << targetValue
             << " found at: " << recursiveBinarySearch(numbers, targetValue, 0, numbers.size() - 1)
             << " index." << endl;
    }
}  // namespace binarySearch

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    😎 Easy Problems                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace easyProblems {
    int binarySearch(const vector<int>& numbers, int targetValue) {
        const int NOT_FOUND = -1;

        if (numbers.empty()) {
            return NOT_FOUND;
        }

        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        while (leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if (numbers[middleIndex] == targetValue) {
                return middleIndex;
            }

            if (numbers[middleIndex] > targetValue) {
                rightIndex = middleIndex - 1;
            } else {
                leftIndex = middleIndex + 1;
            }
        }

        return NOT_FOUND;
    }

    /**
     * Finds the index where a target should be inserted in a sorted array.
     *
     * Uses binary search to find the position to insert a target value such that
     * the array remains sorted if the target is not currently in the array.
     *
     * Example:
     * Input: numbers = [1, 3, 5, 7], targetValue = 7
     * Output: 3
     * Explanation: 7 is found at index 3. Wait, the logic actually finds the last max insert position.
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers A sorted vector of integers.
     * @param targetValue The target to insert or find.
     * @return The index where the target is or should be inserted.
     */
    int searchingInsertPosition(const vector<int>& numbers, int targetValue) {
        if (numbers.empty()) {
            return -1;
        }

        int insertPosition = -1;

        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        while (leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if (numbers[middleIndex] > targetValue) {
                rightIndex = middleIndex - 1;
            } else {
                insertPosition = max(insertPosition, middleIndex + 1);
                leftIndex = middleIndex + 1;
            }
        }

        return insertPosition;
    }

    /**
     * Finds a pair of adjacent elements that sum up to the target value.
     *
     * Iterates through the array and stores the sum of consecutive neighboring 
     * pairs (i-1 and i) in a hashmap to quickly identify if any adjacent combination matches.
     *
     * Example:
     * Input: numbers = [2, 7, 11, 15], targetValue = 9
     * Output: {0, 1}
     * Explanation: numbers[0] + numbers[1] = 2 + 7 = 9.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n) to store the sums in the hash map.
     *
     * @param numbers The vector of integers.
     * @param targetValue The desired sum of adjacency elements.
     * @return A pair of indices corresponding to the two elements, or {-1, -1} if not found.
     */
    pair<int, int> findTwoSumPairs(const vector<int>& numbers, int targetValue) {
        int size = numbers.size();

        unordered_map<int, int> hashMap;

        // Preparing calculation between "i" and "i - 1".
        for (int i = 1; i < size; i++) {
            hashMap[i] = numbers[i - 1] + numbers[i];
        }

        for (int j = 1; j < size; j++) {
            if (hashMap[j] == targetValue) {
                return make_pair(j - 1, j);
            }
        }

        return make_pair(-1, -1);
    }

    /**
     * Determines if the array contains any duplicate values.
     *
     * Example:
     * Input: numbers = [1, 2, 3, 1]
     * Output: true
     *
     * Time Complexity: O(n) space time, average case.
     * Space Complexity: O(n) for the hash map to store frequencies.
     *
     * @param numbers The vector of integers to check.
     * @return True if at least one value appears at least twice, false otherwise.
     */
    bool isContainingDuplicates(const vector<int>& numbers) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < numbers.size(); i++) {
            hashMap[numbers[i]]++;

            if (hashMap[numbers[i]] >= 2) {
                return true;
            }
        }

        return false;
    }

    /**
     * Finds the maximum average of a contiguous subarray of a fixed size.
     *
     * Uses the sliding window technique to efficiently calculate the sums 
     * and averages of subarrays of size 'maxSize'.
     *
     * Example:
     * Input: numbers = [1, 12, -5, -6, 50, 3], maxSize = 4
     * Output: 12.75
     * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75.
     *
     * Time Complexity: O(n) where n is the number of elements.
     * Space Complexity: O(1) since we only store sums and sliding window boundaries.
     *
     * @param numbers The vector of integers.
     * @param maxSize The fixed size of the contiguous subarray.
     * @return The maximum average calculated.
     */
    float findMaximumAvgSubarray(const vector<int>& numbers, int maxSize) {
        int leftIndex = 0;

        int totalSum = 0;
        float maximumAvg = 0;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            totalSum += numbers[rightIndex];

            if ((rightIndex - leftIndex + 1) == maxSize) {
                float avg = totalSum / maxSize;
                maximumAvg = max(maximumAvg, avg);

                totalSum -= numbers[leftIndex];
                leftIndex++;
            }
        }

        return maximumAvg;
    }

    /**
     * Finds the first bad software version using binary search.
     *
     * Example:
     * Input: versions = [...], firstBad = 4
     * Output: 4
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param versions The array representing different software versions.
     * @param firstBad A target version considered as the starting bad version point.
     * @return The index/version number of the first bad version.
     */
    int findBadVersion(const vector<int>& versions, int firstBad) {
        int leftIndex = 0;
        int rightIndex = versions.size() - 1;

        int firstBadVersion = INT_MAX;

        while (leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if (versions[middleIndex] >= firstBad) {
                firstBadVersion = min(versions[middleIndex], firstBadVersion);
            }

            if (versions[middleIndex] > firstBad) {
                rightIndex = middleIndex - 1;
            } else {
                leftIndex = middleIndex + 1;
            }
        }

        return firstBadVersion;
    }

    /**
     * Guesses a secret number within a sequence constraint via binary guessing.
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param size The upper limit of the number range (1 to size).
     * @param secretNum The actual secret number to search for.
     * @return The secret number if guessed correctly, or -1 otherwise.
     */
    int guessHightOrLowerNum(int size, int secretNum) {
        int left = 1;
        int right = size;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (middle == secretNum) {
                return middle;
            }

            if (middle > secretNum) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return -1;
    }

    void main() {
        cout << "Easy Problems: " << endl;

        // BINARY SEARCH
        vector<int> numbers = {2, 5, 8, 12};
        int targetValue = 8;
        cout << "Position of " << targetValue
             << " found at index: " << binarySearch(numbers, targetValue) << endl;

        // SEARCHING INSERT POSITION
        numbers = {1, 3, 5, 7};
        targetValue = 7;
        cout << "Insert Position for " << targetValue
             << " is at index: " << searchingInsertPosition(numbers, targetValue) << endl;

        // FIND TWO SUM (UNORDERED)
        numbers = {2, 7, 11, 15};
        targetValue = 9;
        pair<int, int> twoSumPair = findTwoSumPairs(numbers, targetValue);
        cout << "Sum of two pairs for " << targetValue << " is: " << twoSumPair.first << " - "
             << twoSumPair.second << endl;

        // IS CONTAINING DUPLICATES
        numbers = {1, 2, 3, 1};
        cout << "Is numbers has duplicates: " << isContainingDuplicates(numbers) << endl;

        // FIND MAXIMUM AVERAGE SUBARRAY
        numbers = {1, 12, -5, -6, 50, 3};
        cout << "Maximum Average of Subarray is: " << findMaximumAvgSubarray(numbers, 4) << endl;

        cout << endl << endl;
    }
}  // namespace easyProblems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                  🤔 Medium Problems                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace mediumProblems {
    /**
     * Finds the minimum element in a rotated sorted array.
     *
     * A rotated sorted array is an array sorted in ascending order that has been 
     * shifted at an unknown pivot (e.g., [3,4,5,1,2]). Uses binary search to find the drop point.
     *
     * Example:
     * Input: numbers = [3, 4, 5, 6, 7, 1, 2]
     * Output: 1
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers The rotated sorted vector of integers.
     * @return The minimum integer found in the array.
     */
    int findMinimumInRotatedSortedArr(const vector<int>& numbers) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        int miniValue = INT_MAX;

        while (leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

            // Means "second" half is at left direction.
            if (numbers[middleIndex] > numbers[rightIndex]) {
                leftIndex = middleIndex + 1;
            } else {
                rightIndex = middleIndex - 1;
                miniValue = min(miniValue, numbers[middleIndex]);
            }
        }

        return miniValue;
    }

    /**
     * Searches for a target value within a rotated sorted array.
     *
     * Uses binary search by continuously checking which half (left or right) of 
     * the array is correctly sorted, and then determining if the target falls within that sorted range.
     *
     * Example:
     * Input: numbers = [4, 5, 6, 7, 0, 1, 2], target = 0
     * Output: 4
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers The rotated sorted vector.
     * @param target The target value to search for.
     * @return The index of the target value, or -1 if not found.
     */
    int searchInRotatedArray(const vector<int>& numbers, int target) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        while (leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if (numbers[middleIndex] == target) {
                return middleIndex;
            }

            // Check which half is sorted
            if (numbers[leftIndex] <= numbers[middleIndex]) {
                // Left half is sorted
                if (target >= numbers[leftIndex] && target < numbers[middleIndex]) {
                    rightIndex = middleIndex - 1;  // target is in left half
                } else {
                    leftIndex = middleIndex + 1;  // target is in right half
                }
            } else {
                // Right half is sorted
                if (target > numbers[middleIndex] && target <= numbers[rightIndex]) {
                    leftIndex = middleIndex + 1;  // target is in right half
                } else {
                    rightIndex = middleIndex - 1;  // target is in left half
                }
            }
        }

        return -1;
    }

    /**
     * Finds the minimal length of a contiguous subarray whose sum is greater than or equal to a target.
     *
     * Uses a dynamic sliding window. It expands to the right to meet the target sum, 
     * and shrinks from the left to find the absolute minimum length that satisfies the condition.
     *
     * Example:
     * Input: numbers = [1, 4, 4], target = 4
     * Output: 1
     * Explanation: The subarray [4] has minimum length under the condition sum >= 4.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers The vector of positive integers.
     * @param target The minimum bound for the sum of the contiguous subarray.
     * @return The minimum length of the subarray, or INT_MAX if no such setup exists.
     */
    int findMinimumSizeSubarray(const vector<int>& numbers, int target) {
        int leftIndex = 0;

        int totalSum = 0;
        int minSize = INT_MAX;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            totalSum += numbers[rightIndex];

            while (totalSum >= target) {
                minSize = min((rightIndex - leftIndex + 1), minSize);
                totalSum -= numbers[leftIndex];
                leftIndex++;
            }
        }

        return minSize;
    }

    /**
     * Finds the minimum eating speed to consume all banana piles within given hours.
     *
     * Also known as "Koko Eating Bananas". Uses binary search on the "answer" (speed).
     * Checks if eating at 'middle' bananas/hour allows finishing before 'h' hours.
     * 
     * Example:
     * Input: piles = [3, 6, 7, 11], h = 8
     * Output: 4
     *
     * Time Complexity: O(n * log(max(piles))) where n is the number of piles.
     * Space Complexity: O(1)
     *
     * @param piles Array where each element represents bananas in a pile.
     * @param h Maximum hours allowed to eat all bananas.
     * @return Minimum eating speed (bananas per hour).
     */
    int minEatingSpeed(const vector<int>& piles, int h) {
        if (piles.empty())
            return -1;

        int minimumHour = INT_MAX;
        auto maxPile = max_element(piles.begin(), piles.end());

        int left = 1;
        int right = *maxPile;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            int totalHour = 0;
            for (const int& p : piles) {
                totalHour += ceil((double)p / middle);
            }

            if (totalHour > h) {
                left = middle + 1;
            } else {
                right = middle - 1;
                minimumHour = min(minimumHour, middle);
            }
        }

        return minimumHour;
    }

    /**
     * Finds the maximum length of a contiguous subarray whose total sum is at most 'k'.
     * 
     * Expands a right index boundary and contracts a left index boundary when the 
     * total sum exceeds constraints (sliding window strategy).
     *
     * Example:
     * Input: numbers = [1, 2, 1, 0, 1], k = 4
     * Output: 4
     * Explanation: Window [1, 2, 1, 0] gives sum 4 with max length 4.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers The vector of integers.
     * @param k The upper limit for the total sum of the sub array.
     * @return The maximum length valid configuration.
     */
    int longestSumOfSubarrayLength(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        int totalSum = 0;
        int longestLength = 0;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            totalSum += numbers[rightIndex];

            while (totalSum > k) {
                totalSum -= numbers[leftIndex];
                leftIndex++;
            }

            longestLength = max(longestLength, (rightIndex - leftIndex + 1));
        }

        return longestLength;
    }

    /**
     * Finds all unique triplets in an array that sum up to zero.
     *
     * Sorts the original array to deploy a "two-pointer" methodology inside an outer 
     * iteration loop. Deduplicates outcomes logically.
     *
     * Example:
     * Input: numbers = [-1, 0, 1, 2, -1, -4]
     * Output: [[-1, -1, 2], [-1, 0, 1]]
     *
     * Time Complexity: O(n^2) tracking outer and pair-pointers.
     * Space Complexity: O(1) or O(n) dependent on library sort layout (excluding output array).
     *
     * @param numbers The vector of integers.
     * @return A 2D vector where each child vector represents a valid resulting triplet array.
     */
    vector<vector<int>> threeSumEqualToZero(vector<int>& numbers) {
        vector<vector<int>> groups;

        sort(numbers.begin(), numbers.end());

        int size = numbers.size();
        for (int outerIndex = 0; outerIndex < size - 2; outerIndex++) {
            int rightIndex = size - 1;
            int leftIndex = outerIndex + 1;

            while (leftIndex < rightIndex) {
                int totalSum = numbers[outerIndex] + numbers[leftIndex] + numbers[rightIndex];

                if (totalSum == 0) {
                    groups.push_back(
                        {numbers[outerIndex], numbers[leftIndex], numbers[rightIndex]});

                    while (leftIndex < rightIndex &&
                           (numbers[leftIndex] == numbers[leftIndex - 1])) {
                        leftIndex++;
                    }

                    while (rightIndex > leftIndex &&
                           (numbers[rightIndex] == numbers[rightIndex - 1])) {
                        rightIndex--;
                    }
                }

                if (totalSum <= 0) {
                    leftIndex++;
                } else {
                    rightIndex--;
                }
            }
        }

        return groups;
    }

    void main() {
        cout << "Medium Problems: " << endl;

        // FINDING MINIMUM IN ROTATED SORTED ARRAY.
        vector<int> numbers = {3, 4, 5, 6, 7, 1, 2};
        cout << "Minimum number in rotated sorted array is: "
             << findMinimumInRotatedSortedArr(numbers) << endl;

        // SEARCHING IN AN ROTATED SORTED ARRAY
        numbers = {4, 5, 6, 7, 0, 1, 2};
        int targetValue = 0;
        cout << targetValue << " found at index: " << searchInRotatedArray(numbers, targetValue)
             << endl;

        // MIN SIZE SUBARRAY
        numbers = {1, 4, 4};
        cout << "Min size of sum of subarray is: " << findMinimumSizeSubarray(numbers, 4) << endl;

        // MINIMUM BANANA SPEED
        numbers = {3, 6, 7, 11};  // piles of bananas
        targetValue = 8;          // minimHours
        cout << "Minimum speed taken to eat banana is: " << minEatingSpeed(numbers, targetValue)
             << endl;

        // FIND LONGEST LENGTH OF SUM OF SUBARRAY EQUAL TO K
        numbers = {1, 2, 1, 0, 1};
        targetValue = 4;
        cout << "Longest length is: " << longestSumOfSubarrayLength(numbers, targetValue) << endl;

        // THREE SUM EQUAL TO ZERO
        numbers = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> groups = threeSumEqualToZero(numbers);
        cout << "Groups are: " << endl;
        for (const vector<int>& vec : groups) {
            cout << "[ ";
            for (const int& n : vec) {
                cout << n << " ";
            }
            cout << " ]" << endl;
        }

        cout << endl << endl;
    }
}  // namespace mediumProblems

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                   😶 Hard Problems                                                                                                  |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hardProblems {
    void main() {
        cout << "Hard Problems: " << endl;
        // PROBLEMS
        cout << endl << endl;
    }
}  // namespace hardProblems

int main() {
    // linearSearch::main();
    // binarySearch::main();

    // Problems
    // easyProblems::main();
    mediumProblems::main();
    // hardProblems::main();

    return 0;
}