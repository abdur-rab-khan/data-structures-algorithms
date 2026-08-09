/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                      TWO POINTERS                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 In "two pointers" technique we use two indices (pointer) to scan the array, based on condition we smartly increase/decrease pointer indices.                                                                     |
|                                                                                                                                                                                                                     |
| 🟡 Without using "two pointers" we could use "nested loop o(n²)", "two pointers" makes scaning efficient "o(n)".                                                                                                    |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    TYPES TWO POINTERS                                                                                               |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔶 Opposite direction (start & end):                                                                                                                                                                                |
|                                                                                                                                                                                                                     |
|    1. One Pointer at the begining, One Pointer at the end.                                                                                                                                                          |
|    2. Moving based on conditions.                                                                                                                                                                                   |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Sorted array problems                                                                                                                                                                                  |
|           2. Pair sum problems                                                                                                                                                                                      |
|           3. Palindrome checking                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
| 🔶 Same direction (slow & fast pointer):                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|    1. Both pointers starts from the same position.                                                                                                                                                                  |
|    2. Fast pointer (move quickly), slow pointer (move based on conditions).                                                                                                                                         |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Removing Duplicates                                                                                                                                                                                    |
|           2. Removing elements                                                                                                                                                                                      |
|           3. Cycle Detection                                                                                                                                                                                        |
|           4. Rearranging array in place                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
| 🔶 Sliding window (Variable size):                                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|    1. Window grows and shrinks maintaining condition inside the window.                                                                                                                                             |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Longest Substring                                                                                                                                                                                      |
|           2. Subarray sum problems                                                                                                                                                                                  |
|           3. At most K distinct element                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
| 🔶 Sliding window (Fixed size):                                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|    1. Window size fixed maintaining fixed distance, both moves together.                                                                                                                                            |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Maximum size of K                                                                                                                                                                                      |
|           2. First negative in window.                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>

#include "../../../dsa_utils.h"

using namespace std;

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                             🔺 TWO POINTERS EASY PROBLEMS                                                                                           |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace easy {
    /**
    * Reverses an array.
    *
    * Given an array of integers, return the same array in reverse order.
 *
 * Example:
 * Input: vec = {1, 2, 3, 4}
* Output: {4, 3, 2, 1}
 *
 * Time Complexity: O(n) where n is the size of the vector
 * Space Complexity: O(1) in-place
 *
* @param vec Input array to be reversed
 */
    void reverse(vector<int>& vec) {
        int i = 0;
        int j = vec.size() - 1;

        while (i < j) {
            vec[i] ^= vec[j], vec[j] ^= vec[i], vec[i] ^= vec[j];  // Swapping numbers

            i++;
            j--;
        }
    }

    /**
    * Removes duplicate values from a sorted array and prints unique values.
    *
    * Given a sorted array, keep one occurrence of each value and print the
    * resulting unique list.
 *
 * Example:
 * Input: vec = {1, 1, 2, 3, 3}
 * Output: 1 2 3
 *
* Time Complexity: O(n) where n is the array size
 * Space Complexity: O(n) due to constructing a new unique vector for output
 *
* @param vec Sorted input array that may contain duplicates
 */
    void removeDuplicates(vector<int> vec) {
        int i = 0, j = 1;

        while (j < vec.size()) {
            if (vec[i] != vec[j]) {
                i++;
                vec[i] = vec[j];
                j++;
            } else
                j++;
        }

        vector<int> duplicateFreeVec(vec.begin(), vec.begin() + i + 1);

        print(duplicateFreeVec);  // Printing all unique elements
    }

    /**
        * Finds all pairs in a sorted array whose sum equals a target.
        *
        * Given a sorted array and an integer k, print every pair [a, b] such that
        * a + b = k.
     *
     * Example:
     * Input: numbers = {2, 7, 11, 15}, k = 9
     * Output: [ 2 7 ]
     *
     * Time Complexity: O(n) where n is the vector size
     * Space Complexity: O(p) where p is number of matching pairs stored
     *
     * @param numbers Sorted input vector
     * @param k Target sum value
     */
    void computeTwoSum(vector<int> numbers, int k) {
        vector<vector<int>> pairs = {};

        size_t leftIndex  = 0;
        size_t rightIndex = numbers.size() - 1;

        while (leftIndex < rightIndex) {
            int sum = numbers[leftIndex] + numbers[rightIndex];

            if (sum == k) {
                pairs.push_back({numbers[leftIndex], numbers[rightIndex]});
                leftIndex++;
                rightIndex--;
                continue;
            }

            if (sum > k) {
                rightIndex--;
            } else {
                leftIndex++;
            }
        }

        for (const vector<int>& vec : pairs) {
            cout << "[ ";
            for (const int& n : vec) {
                cout << n << " ";
            }
            cout << "]" << endl;
        }
    }

    /**
        * Checks whether a string is a palindrome.
        *
        * Given a string, determine if it reads the same from left to right and
        * right to left when ignoring non-alphanumeric characters and case.
     *
     * Example:
     * Input: str = "A man, a plan, a canal: Panama"
    * Output: true
     *
     * Time Complexity: O(n) where n is the string length
     * Space Complexity: O(1) auxiliary space
     *
     * @param str Input string to validate as palindrome
     */
    void isPalindrome(string str) {
        int leftIndex  = 0;
        int rightIndex = str.length() - 1;

        // Lambda function: use "auto" or given type or directly use "isalnum"  ==> Learned LAMBDA
        // FUNCTION
        function<bool(char)> isValidChar = [](char ch) -> bool {
            char lowerCh = tolower(ch);
            return (lowerCh >= 'a' && lowerCh <= 'z') || (lowerCh >= '0' && lowerCh <= '9');
        };

        // Find whether "str" is palindrome or not by look both side.
        while (leftIndex < rightIndex) {
            bool isRightCharValid = isValidChar(str[rightIndex]);
            bool isLeftCharValid  = isValidChar(str[leftIndex]);

            if (!isRightCharValid) {
                leftIndex++;
                continue;
            }

            if (!isLeftCharValid) {
                rightIndex--;
                continue;
            }

            if (tolower(str[leftIndex]) != tolower(str[rightIndex])) {
                cout << str << " is not a palindrome";
                return;
            }

            leftIndex++;
            rightIndex--;
        }

        cout << str << " is a palindrome";
    }

    /**
        * Removes duplicates from a sorted array.
        *
        * Given a sorted array, return a new array containing only unique values
        * in sorted order.
     *
     * Example:
     * Input: numbers = {1, 1, 2, 3, 3}
     * Output: {1, 2, 3}
     *
     * Time Complexity: O(n) where n is the vector size
    * Space Complexity: O(u) for returned array of u unique elements
     *
     * @param numbers Sorted vector that may contain duplicates
     * @return A vector containing unique elements in sorted order
     */
    vector<int> removeDuplicates(vector<int> numbers) {
        if (numbers.empty())
            return {};

        size_t leftIndex  = 0;
        size_t rightIndex = 1;

        while (rightIndex < numbers.size()) {
            if (numbers[leftIndex] != numbers[rightIndex]) {
                leftIndex++;
                numbers[leftIndex] = numbers[rightIndex];
            }

            rightIndex++;
        }

        return vector<int>(numbers.begin(), numbers.begin() + leftIndex + 1);
    }

    /**
        * Moves all zeros to the right while keeping non-zero order.
        *
        * Given an array, place all zero values at the end and keep the relative
        * order of non-zero values unchanged.
     *
     * Example:
     * Input: numbers = {0, 1, 0, 3, 12}
    * Output: rearranged array starts with {1, 3, 12} and zeros move to the end
     *
     * Time Complexity: O(n) where n is the vector size
     * Space Complexity: O(k) for returned prefix vector of k non-zero elements
     *
     * @param numbers Vector to rearrange in place
     * @return Vector containing non-zero values after compaction
     */
    std::vector<int> moveZeros(std::vector<int>& numbers) {
        if (numbers.empty())
            return {};

        // Technique 1;
        if (0) {
            int leftIndex = 0;

            for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
                if (numbers[rightIndex] != 0) {
                    std::swap(numbers[leftIndex], numbers[rightIndex]);
                    leftIndex++;
                }
            }

            return std::vector<int>(numbers.begin(), numbers.begin() + leftIndex);
        }

        // Technique 2;
        size_t size = numbers.size();

        size_t leftIndex  = 0;
        size_t rightIndex = 1;

        while (rightIndex < size) {
            while (leftIndex < size && numbers[leftIndex] != 0)
                leftIndex++;

            while (rightIndex < size && numbers[rightIndex] == 0)
                rightIndex++;

            if (rightIndex < size) {
                std::swap(numbers[leftIndex], numbers[rightIndex]);
                leftIndex++;
                rightIndex++;
            }
        }

        return std::vector<int>(numbers.begin(), numbers.begin() + leftIndex);
    }

    /**
        * Merges two sorted arrays into one sorted array.
        *
        * Given two sorted arrays, return a single sorted array containing all
        * elements from both inputs.
     *
     * Example:
     * Input: numsOne = {1, 3, 5}, numsTwo = {2, 4}
     * Output: {1, 2, 3, 4, 5}
     *
     * Time Complexity: O(n + m) where n and m are input sizes
     * Space Complexity: O(1) auxiliary (excluding resized output storage)
     *
     * @param numsOne First sorted vector; receives merged values
     * @param numsTwo Second sorted vector
     * @return Merged sorted vector
     */
    vector<int> mergeSort(vector<int>& numsOne, vector<int>& numsTwo) {
        if (numsOne.empty() || numsTwo.empty())
            return numsOne.empty() ? numsTwo : numsOne;

        // We can use two pointer and new vector for achieving this but, space complexity will be
        // "O(n)".
        size_t numsOneSize = numsOne.size();
        size_t numsTwoSize = numsTwo.size();

        size_t numsOneLastIndex = numsOneSize - 1;
        size_t numsTwoLastIndex = numsTwoSize - 1;

        size_t lastIndex = (numsOneSize + numsTwoSize) - 1;

        // Resizing the vector for merging both vector.
        numsOne.resize(numsOneSize + numsTwoSize);

        while (numsOneLastIndex != 0 && numsTwoLastIndex != 0) {
            if (numsOne[numsOneLastIndex] > numsTwo[numsTwoLastIndex]) {
                numsOne[lastIndex] = numsOne[numsOneLastIndex];
                numsOneLastIndex--;
            } else {
                numsOne[lastIndex] = numsTwo[numsTwoLastIndex];
                numsTwoLastIndex--;
            }

            lastIndex--;
        }

        // If numsOne is smaller, then adding all remaining numsTwo elements.
        while (numsTwoLastIndex != 0) {
            numsOne[lastIndex] = numsTwo[numsTwoLastIndex];

            lastIndex--;
            numsTwoLastIndex--;
        }

        return numsOne;
    }

    /**
        * Finds the maximum water container area.
        *
        * Given heights of vertical lines, find two lines that with the x-axis form
        * a container holding the maximum amount of water.
     *
     * Example:
     * Input: heights = {1, 8, 6, 2, 5, 4, 8, 3, 7}
     * Output: 49
     *
     * Time Complexity: O(n) where n is the number of heights
     * Space Complexity: O(1)
     *
     * @param heights Heights of vertical lines
     * @return Maximum area of water that can be contained
     */
    int calculateMaxContainerArea(const vector<int>& heights) {
        /*
            Suppose we have an array that represents heights -> [2, 3, 4, 1, 6];

                           |
                           |
                           |
                           |
            |              |
            |              |
            ----------------

            So the capcity will be min(2, 6) * (width), width = j - i = 4 - 0 = 4;
        */
        int leftIndex  = 0;
        int rightIndex = heights.size() - 1;

        int maxArea = 0;

        while (leftIndex < rightIndex) {
            int actualHeight = std::min(heights[leftIndex], heights[rightIndex]);
            int area         = actualHeight * (rightIndex - leftIndex);

            maxArea = std::max(maxArea, area);

            if (heights[leftIndex] > heights[rightIndex]) {
                rightIndex--;
            } else {
                leftIndex++;
            }
        }

        return maxArea;
    }

    /**
        * Returns the sorted squares of a sorted array.
        *
        * Given a non-decreasing array (possibly with negatives), square each value
        * and return the squared values in non-decreasing order.
     *
     * Example:
     * Input: numbers = {-4, -1, 0, 3, 10}
     * Output: 0 1 9 16 100
     *
     * Time Complexity: O(n) where n is the vector size
     * Space Complexity: O(n) for the squared result vector
     *
     * @param numbers Sorted vector that may include negative values
     */
    void computeSortedSquares(vector<int> numbers) {
        // Edge case: empty array
        if (numbers.empty())
            return;

        int size = numbers.size();

        int negativeIndex = 0;
        int positiveIndex = 1;

        vector<int> squaredValues;

        // Step 1: Find first non-negative index
        while (positiveIndex < size && numbers[positiveIndex] < 0) {
            negativeIndex++;
            positiveIndex++;
        }

        // Step 2: Merge negative and positive parts
        while (negativeIndex >= 0 && positiveIndex < size) {
            int leftValue  = numbers[negativeIndex];
            int rightValue = numbers[positiveIndex];

            if (abs(leftValue) < rightValue) {
                squaredValues.push_back(leftValue * leftValue);
                negativeIndex--;
            } else {
                squaredValues.push_back(rightValue * rightValue);
                positiveIndex++;
            }
        }

        // Step 3: Add remaining negative elements
        while (negativeIndex >= 0) {
            int value = numbers[negativeIndex];
            squaredValues.push_back(value * value);
            negativeIndex--;
        }

        while (positiveIndex < size) {
            int value = numbers[positiveIndex];
            squaredValues.push_back(value * value);
            positiveIndex++;
        }

        print(squaredValues, "Printing all sorted array: ");
    }

    /**
        * Runs easy-level two-pointer questions.
        *
        * Executes sample inputs for pair sum, palindrome check, duplicate removal,
        * move zeros, merge sorted arrays, max water area, and sorted squares.
        *
        * Example:
        * Input: predefined sample arrays and strings
        * Output: printed answers for easy-level questions
     *
     * Time Complexity: Depends on each demonstrated function
     * Space Complexity: Depends on each demonstrated function
     */
    void main() {
        cout << "Easy Problems: " << endl;

        // Two Sum Problem
        vector<int> arr = {2, 7, 11, 15};
        computeTwoSum(arr, 9);

        // IsPalindrome problem
        isPalindrome("madam");
        isPalindrome("car racing");

        // Removing duplicates in place
        vector<int> duplicateNumbers = {1, 1, 1, 2, 3, 4, 5, 5, 5};
        print(removeDuplicates(duplicateNumbers), "Unique numbers are: ");

        // Moving zero elements towards right
        vector<int> numbers = {0, 1, 0, 3, 12};
        print(moveZeros(numbers), "Zero free numbers are: ");

        // Merge sorted array
        vector<int> sortedNumberF = {1, 3, 5, 7};
        vector<int> sortedNumberS = {2, 4, 6};
        print(mergeSort(sortedNumberF, sortedNumberS), "After merging: ");

        // Container with most water
        vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        calculateMaxContainerArea(heights);

        // Square of sorted array
        vector<int> sortedNumbers = {-4, -1, 0, 3, 10};
        computeSortedSquares(sortedNumbers);

        cout << endl << endl;
    }
}  // namespace easy

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🔺 TWO POINTERS MEDIUM PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace medium {
    /**
     * Finds all unique triplets whose sum equals the target.
     *
        * Given an integer array and a target value, return all distinct triplets
        * [a, b, c] such that a + b + c = target.
     *
     * Example:
     * Input: nums = {-1, 0, 1, 2, -1, -4}, target = 0
     * Output: {{-1, -1, 2}, {-1, 0, 1}}
     *
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) auxiliary (excluding output)
     *
     * @param nums Input vector of integers
     * @param target Target sum for each triplet
     * @return All unique triplets that sum to target
     */
    vector<vector<int>> computeThreeSumProblem(vector<int> numbers, int target) {
        int size = numbers.size();

        vector<vector<int>> possiblePairs;

        sort(numbers.begin(), numbers.end());

        for (int outerIndex = 0; outerIndex < size - 2; outerIndex++) {
            int leftIndex  = outerIndex + 1;
            int rightIndex = size - 1;

            while (leftIndex < rightIndex) {
                int sum = numbers[outerIndex] + numbers[leftIndex] + numbers[rightIndex];

                if (sum == target) {
                    possiblePairs.push_back(
                        {numbers[outerIndex], numbers[leftIndex], numbers[rightIndex]});

                    leftIndex++;
                    rightIndex--;

                    // Skipping duplicates from left
                    while (leftIndex < rightIndex && numbers[leftIndex] == numbers[leftIndex - 1])
                        leftIndex++;

                    // Skipping duplicates from right
                    while (rightIndex > leftIndex && numbers[rightIndex] == numbers[rightIndex - 1])
                        rightIndex--;

                    continue;
                }

                if (sum > target) {
                    rightIndex--;
                } else {
                    leftIndex++;
                }
            }
        }

        return possiblePairs;
    }

    /**
     * Finds all unique quadruplets whose sum equals k.
     *
        * Given an integer array and k, return all distinct quadruplets
        * [a, b, c, d] such that a + b + c + d = k.
     *
     * Example:
     * Input: nums = {1, 0, -1, 0, -2, 2}, k = 0
     * Output: {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}
     *
     * Time Complexity: O(n^3)
     * Space Complexity: O(1) auxiliary (excluding output)
     *
     * @param nums Input vector of integers
     * @param k Target sum for each quadruplet
     * @return All unique quadruplets that sum to k
     */
    vector<vector<int>> findFourSum(vector<int>& nums, int k) {
        const int size = nums.size();

        vector<vector<int>> possiblePairs = {};

        if (size < 4)
            return possiblePairs;

        sort(nums.begin(), nums.end());

        // 1.
        for (int i = 0; i < size - 3; i++) {
            // Skip duplicate for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 2.
            for (int j = i + 1; j < size - 2; j++) {
                // Skip duplicate for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int leftIndex  = j + 1;
                int rightIndex = size - 1;

                // 3.
                while (leftIndex < rightIndex) {
                    int sum = nums[i] + nums[j] + nums[leftIndex] + nums[rightIndex];

                    if (sum == k) {
                        possiblePairs.push_back(
                            {nums[i], nums[j], nums[leftIndex], nums[rightIndex]});

                        leftIndex++;
                        rightIndex--;

                        while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1])
                            leftIndex++;

                        while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1])
                            rightIndex--;

                    } else if (sum > k) {
                        rightIndex--;
                    } else {
                        leftIndex++;
                    }
                }
            }
        }

        return possiblePairs;
    }

    /**
        * Finds the minimum length subarray with sum at least target.
        *
        * Given a positive integer array and a target, return the smallest length
        * of a contiguous subarray whose sum is greater than or equal to target.
     *
     * Example:
     * Input: nums = {2, 3, 1, 2, 4, 3}, target = 7
     * Output: 2
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param nums Input vector of positive integers
     * @param target Required subarray sum threshold
     * @return Minimum valid subarray length, or 0 if not found
     */
    int computeMinimumSubarraySum(vector<int> nums, int target) {
        int size = nums.size();

        int totalSum    = 0;
        int leftIdx     = 0;
        int minSubarray = INT_MAX;

        for (int rightIdx = 0; rightIdx < size; rightIdx++) {
            totalSum += nums[rightIdx];

            while (leftIdx < rightIdx && totalSum >= target) {
                if (totalSum == target)
                    minSubarray = min(minSubarray, (rightIdx - leftIdx) + 1);

                totalSum -= nums[leftIdx];
                leftIdx++;
            }
        }

        return (minSubarray == INT_MAX) ? 0 : minSubarray;
    }

    /**
        * Calculates total trapped rain water.
        *
        * Given an elevation map where each value is bar height, compute total
        * water units trapped after rainfall.
     *
     * Example:
     * Input: heights = {3, 0, 2, 0, 4}
     * Output: 7
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param heights Elevation map heights
     * @return Total units of trapped water
     */
    int calculateTotalTrappedWater(vector<int> heights) {
        /*
            Example 1:
                    arr = [3, 0, 2, 0, 4]

                    * Array elements represents the height of the vertical line.
                    * Water will trap between vertical lines so we have to evaluate the thing.
        */

        int leftIndex  = 1;
        int rightIndex = heights.size() - 2;

        int maxLeftHeight  = heights[0];
        int maxRightHeight = heights[heights.size() - 1];

        int totalTrappedWater = 0;

        // You alway do wrong here please consider this "leftIndex <= rightIndex"
        while (leftIndex <= rightIndex) {
            int leftHeight  = heights[leftIndex];
            int rightHeight = heights[rightIndex];

            int minHeight = std::min(maxLeftHeight, maxRightHeight);

            if (maxLeftHeight > maxRightHeight) {
                if (rightHeight >= maxRightHeight) {
                    maxRightHeight = rightHeight;
                } else {
                    totalTrappedWater += (minHeight - rightHeight);
                }
                rightIndex--;
            } else {
                if (leftHeight >= maxLeftHeight) {
                    maxLeftHeight = leftHeight;
                } else {
                    totalTrappedWater += (minHeight - leftHeight);
                }
                leftIndex++;
            }
        }

        return totalTrappedWater;
    }

    /**
        * Sorts an array containing only 0, 1, and 2.
        *
        * Given an array of only three values (0, 1, 2), reorder it so that all
        * 0s come first, then 1s, then 2s.
     *
     * Example:
     * Input: nums = {2, 0, 2, 1, 1, 0}
     * Output: {0, 0, 1, 1, 2, 2}
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param nums Vector containing only 0, 1, and 2
     */
    void solveDutchFlag(vector<int>& nums) {
        size_t size = nums.size();

        int leftIdx  = 0;
        int rightIdx = size - 1;

        // Moving 0 towards front
        while (leftIdx < rightIdx) {
            while (nums[leftIdx] == 0)
                leftIdx++;

            if (rightIdx == 0) {
                swap(nums[leftIdx], nums[rightIdx]);
                leftIdx++;
            }

            rightIdx--;
        }

        // Reseting rightIdx
        rightIdx = size - 1;

        // Moving 1 towards front
        while (leftIdx < rightIdx) {
            while (nums[leftIdx] == 1)
                leftIdx++;

            if (rightIdx == 1) {
                swap(nums[leftIdx], nums[rightIdx]);
                leftIdx++;
            }

            rightIdx--;
        }
    }

    /**
        * Placeholder for three-pointer Dutch National Flag question.
        *
        * Given an array of values 0, 1, and 2, the goal is to sort it in one pass
        * with constant extra space.
        *
        * Example:
        * Input: colors = {2, 0, 2, 1, 1, 0}
        * Output: {0, 0, 1, 1, 2, 2}
     *
    * Time Complexity: O(1) currently (placeholder implementation)
     * Space Complexity: O(1)
     *
     * @param colors Vector to be sorted in Dutch Flag order
     */
    void solveDutchFlagThreePT(vector<int>& colors) {
        if (colors.empty())
            return;
    }

    /**
        * Finds a duplicate number in an array.
        *
        * Given an array containing numbers in a limited index range with one
        * repeated value, return the duplicate number.
     *
     * Example:
     * Input: nums = {1, 3, 4, 2, 2}
     * Output: 2
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param nums Vector with at least one duplicate in valid index range
     * @return Duplicate number detected by cycle entry
     */
    int evaluatingFloydCycle(const vector<int>& nums) {
        int slow = nums[0];  // It's move 1 steps per iteration.
        int fast = nums[0];  // It's move 2 steps per iteration.

        // If any cycle exists eventually it will meet after some iteration.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    /**
        * Counts contiguous subarrays with product less than k.
        *
        * Given a positive integer array and k, count how many contiguous
        * subarrays have product strictly less than k.
     *
     * Example:
     * Input: nums = {10, 5, 2, 6}, k = 100
     * Output: 8
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param nums Input vector of positive integers
     * @param k Product upper bound (exclusive)
     * @return Number of valid contiguous subarrays
     */
    int countSubarrayProducts(const vector<int>& nums, int k) {
        if (nums.empty())
            return 0;

        size_t size = nums.size();

        int slow = 0;
        int fast = 0;

        int totalProducts = 1;
        int totalCounts   = 0;

        while (fast < size) {
            totalProducts *= nums[fast++];

            while (totalProducts >= k) {
                totalProducts /= nums[slow];
                slow++;
            }

            if (totalProducts < k)
                totalCounts += fast - slow;
        }

        return totalCounts;
    }

    /**
        * Runs medium-level two-pointer questions.
        *
        * Executes sample inputs for three-sum, four-sum, minimum subarray length,
        * trapped rain water, Dutch flag ordering, duplicate finding, and
        * subarray product counting.
        *
        * Example:
        * Input: predefined sample arrays and targets
        * Output: printed answers for medium-level questions
     *
     * Time Complexity: Depends on each demonstrated function
     * Space Complexity: Depends on each demonstrated function
     */
    void main() {
        cout << "Medium Problems: " << endl;

        // find three sum
        vector<int>         threeSumNums  = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> possiblePairs = computeThreeSumProblem(threeSumNums, 0);

        cout << "Possible pairs for three sum are: " << endl;
        for (const vector<int>& pairs : possiblePairs) {
            for (const int& p : pairs) {
                cout << p << " ";
            }
            cout << endl;
        }

        // find four sum
        vector<int>         fourSumNums          = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> possiblePairsFourSum = findFourSum(fourSumNums, 0);

        cout << "Possible pairs for four sum are: " << endl;
        for (const vector<int>& pairs : possiblePairsFourSum) {
            for (const int& p : pairs) {
                cout << p << " ";
            }
            cout << endl;
        }

        // Sum of minimum subarray
        vector<int> minSubArrayNums = {2, 3, 1, 2, 4, 3};
        cout << "Minimum subarray length is: " << computeMinimumSubarraySum(minSubArrayNums, 7)
             << endl;

        // Sum of minimum subarray
        vector<int> minSubArrayNums2 = {1, 2, 3, 4, 5};
        cout << "Minimum subarray length is: " << computeMinimumSubarraySum(minSubArrayNums2, 15)
             << endl;

        // Evaluating total trapped water
        vector<int> heightForRain = {3, 0, 2, 0, 4};
        cout << "Total trapped water is: " << calculateTotalTrappedWater(heightForRain) << endl;

        // Solving Dutch Flag
        vector<int> arr = {2, 0, 2, 1, 1, 0};
        solveDutchFlag(arr);

        cout << "Re-Arranging in Dutch Flag Order: ";
        for (const int& n : arr) {
            cout << n << " ";
        }
        cout << endl;

        // Finding Duplicates (Floyd's cycle)
        vector<int> floydArr = {1, 2, 3, 2, 4};
        cout << "Duplicate num is: " << evaluatingFloydCycle(floydArr) << endl;

        // Count Total Subarray products
        vector<int> productArr = {10, 5, 2, 6};
        cout << "Total counts is: " << countSubarrayProducts(productArr, 100) << endl;

        vector<int> productArr2 = {1, 2, 3};
        cout << "Total counts is: " << countSubarrayProducts(productArr2, 4) << endl;

        cout << endl << endl;
    }
}  // namespace medium

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              🔺 TWO POINTERS HARD PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hard {
    /**
        * Entry point for hard-level two-pointer questions.
     *
        * This is a placeholder section for future hard problems.
        *
        * Example:
        * Input: none
        * Output: currently no hard problem output
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void main() {
        // CALLING ALL THE METHOD
    }
}  // namespace hard

int main() {
    easy::main();
    medium::main();
    hard::main();

    return 0;
}
