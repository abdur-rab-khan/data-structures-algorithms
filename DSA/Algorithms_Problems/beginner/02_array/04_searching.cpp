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
|                                      Suppose sorted array looks like this [1, 2, 3, 4, 5, 6, 7], then "rotated array" will looks like this [[4, 5, 6, 7], [1, 2, 3]], We got two parts.                             |
|                                      To solve these problems, We have to find drop point in this case which is "7 and 1" We find using "middle > last" -> "drop is in right direction", "middle" < "last" -> left   |
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
    * Finds the index of a target value in an unsorted array.
    *
    * Given an array and a target value, return the first index where the
    * target appears. If the value is not present, return -1.
     *
     * Example:
     * Input: numbers = [3, 7, 1, 9, 4, 6, 2, 8], targetValue = 6
     * Output: 5
     *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
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
    * Searches for a target value in a sorted array using binary search.
    *
    * Given a sorted array of integers and a target value, return the index of
    * the target if it exists; otherwise return -1.
     *
     * Example:
    * Input: numbers = [1, 2, 3, 4, 6, 7, 8, 9], targetValue = 4
    * Output: 3
     *
    * Time Complexity: O(log n)
    * Space Complexity: O(1)
     *
    * @param numbers Sorted array of integers
    * @param targetValue Value to search for
    * @return Index of the target value, or -1 if not found
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
     * Searches for a target value in a sorted array using recursion.
     *
     * Given a sorted array of integers and a target value, return the index of
     * the target if it exists; otherwise return -1.
     *
     * Example:
     * Input: numbers = [1, 2, 3, 4, 6, 7, 8, 9], targetValue = 4
     * Output: 3
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(log n)
     *
     * @param numbers Sorted array of integers
     * @param targetValue Value to search for
     * @param leftIndex Left boundary of the current search interval
     * @param rightIndex Right boundary of the current search interval
     * @return Index of the target value, or -1 if not found
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

    /**
     * Runs the binary search examples.
     *
     * Example:
     * Input: numbers = [1, 2, 3, 4, 6, 7, 8, 9], targetValue = 4
     * Output: 3
     */
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
    /**
     * Searches for a target value in a sorted array.
     *
     * Given a sorted array, return the index of the target value if it exists,
     * otherwise return -1.
     *
     * Example:
     * Input: numbers = [2, 5, 8, 12], targetValue = 8
     * Output: 2
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers Sorted array of integers
     * @param targetValue Value to search for
     * @return Index of the target value, or -1 if not found
     */
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
     * Finds the insert position for a target in a sorted array.
     *
     * Given a sorted array and a target value, return the index where the target
     * should be inserted to keep the array sorted.
     *
     * Example:
     * Input: numbers = [1, 3, 5, 7], targetValue = 7
     * Output: 3
     * Explanation: The target already exists at index 3.
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers Sorted array of integers
     * @param targetValue Target to search for
     * @return Insert position for the target value
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
     * Finds adjacent indices whose values sum to a target.
     *
     * Given an array and a target value, return the pair of neighboring indices
     * whose values add up to the target.
     *
     * Example:
     * Input: numbers = [2, 7, 11, 15], targetValue = 9
     * Output: {0, 1}
     * Explanation: numbers[0] + numbers[1] = 2 + 7 = 9.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param numbers Input array of integers
     * @param targetValue Target sum of two adjacent values
     * @return Pair of indices, or {-1, -1} if no match exists
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
     * Determines whether an array contains duplicate values.
     *
     * Example:
     * Input: numbers = [1, 2, 3, 1]
     * Output: true
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param numbers Input array of integers
     * @return True if at least one value appears more than once, otherwise false
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
     * Finds the maximum average of a contiguous subarray of fixed size.
     *
     * Given an array and a window size, return the maximum average over all
     * contiguous subarrays of that size.
     *
     * Example:
     * Input: numbers = [1, 12, -5, -6, 50, 3], maxSize = 4
     * Output: 12.75
     * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 12.75.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers Input array of integers
     * @param maxSize Fixed window size
     * @return Maximum average across all windows of size maxSize
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
     * Finds the first bad version in an ordered list of versions.
     *
     * Example:
     * Input: versions = [1, 2, 3, 4, 5], firstBad = 4
     * Output: 4
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param versions Array of version numbers
     * @param firstBad First bad version number
     * @return The first bad version number
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
     * Guesses a secret number in a known range.
     *
     * Given a range from 1 to size, return the secret number if it exists in the
     * range.
     *
     * Example:
     * Input: size = 10, secretNum = 7
     * Output: 7
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param size Upper bound of the search range
     * @param secretNum Secret number to find
     * @return The secret number if found, otherwise -1
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
     * Finds the minimum value in a rotated sorted array.
     *
     * Given a sorted array that has been rotated, return the smallest value in
     * the array.
     *
     * Example:
     * Input: numbers = [3, 4, 5, 6, 7, 1, 2]
     * Output: 1
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers Rotated sorted array
     * @return Minimum value in the array
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
     * Searches for a target value in a rotated sorted array.
     *
     * Given a rotated sorted array and a target value, return the index of the
     * target if it exists; otherwise return -1.
     *
     * Example:
     * Input: numbers = [4, 5, 6, 7, 0, 1, 2], target = 0
     * Output: 4
     *
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     *
     * @param numbers Rotated sorted array
     * @param target Target value
     * @return Index of the target value, or -1 if not found
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
     * Finds the minimum length of a contiguous subarray whose sum reaches a target.
     *
     * Given a positive integer array and a target, return the smallest length
     * of a contiguous subarray whose sum is greater than or equal to the target.
     *
     * Example:
     * Input: numbers = [1, 4, 4], target = 4
     * Output: 1
     * Explanation: The subarray [4] has the shortest valid length.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers Input array of positive integers
     * @param target Target sum
     * @return Minimum valid subarray length, or INT_MAX if none exists
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
     * Finds the minimum eating speed needed to finish all banana piles within h hours.
     *
     * Given banana piles and a number of hours, return the minimum integer speed
     * required to finish all bananas.
     *
     * Example:
     * Input: piles = [3, 6, 7, 11], h = 8
     * Output: 4
     *
     * Time Complexity: O(n * log(max(piles)))
     * Space Complexity: O(1)
     *
     * @param piles Array of banana piles
     * @param h Maximum hours allowed
     * @return Minimum eating speed
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
     * Finds the maximum length of a contiguous subarray whose sum is at most k.
     *
     * Given an integer array and an upper bound k, return the longest contiguous
     * subarray whose total sum does not exceed k.
     *
     * Example:
     * Input: numbers = [1, 2, 1, 0, 1], k = 4
     * Output: 4
     * Explanation: Window [1, 2, 1, 0] gives sum 4 with max length 4.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param numbers Input array of integers
     * @param k Maximum allowed sum
     * @return Maximum valid window length
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
     * Finds all unique triplets in an array that sum to zero.
     *
     * Given an integer array, return all unique triplets [a, b, c] such that
     * a + b + c = 0.
     *
     * Example:
     * Input: numbers = [-1, 0, 1, 2, -1, -4]
     * Output: [[-1, -1, 2], [-1, 0, 1]]
     *
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) excluding output
     *
     * @param numbers Input array of integers
     * @return All unique triplets that sum to zero
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
    linearSearch::main();
    binarySearch::main();

    // Problems
    easyProblems::main();
    mediumProblems::main();
    hardProblems::main();

    return 0;
}