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
using namespace std;

void traverse(const vector<int>& vec, string msg = "") {
    if (vec.size() == 0)
        return;

    if (msg.empty())
        cout << "Elements of a vector are: ";
    else
        cout << msg;

    for (const int& el : vec) {
        cout << el << " ";
    }
    cout << endl;
}

namespace intro {
    // Using Opposite direction to reverse the array
    void reverse(vector<int>& vec) {
        int i = 0;
        int j = vec.size() - 1;

        while (i < j) {
            vec[i] ^= vec[j], vec[j] ^= vec[i], vec[i] ^= vec[j];  // Swapping numbers

            i++;
            j--;
        }
    }

    // Using same direction to check duplicates
    void removeDuplicates(vector<int> vec) {
        int i = 0, j = 1;
        vector<int> uniqueValues = {};

        while (j < vec.size()) {
            if (vec[i] == vec[j])
                j++;
            else {
                uniqueValues.push_back(vec[i]);
                i = j;
                j++;
            }
        }

        // The last unique group is never pushed inside the loop, add it here
        if (!vec.empty())
            uniqueValues.push_back(vec[i]);

        traverse(uniqueValues);  // Printing all unique elements
    }

    void main() {
        // Reversing and printing arr
        vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        reverse(arr), traverse(arr);

        // Removing duplicates
        vector<int> arr2 = {1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 5};
        removeDuplicates(arr2);
    }
}  // namespace intro

// Basic Level
namespace basic {
    // Two sum problem (SHORTED VERSION)
    void computeTwoSum(vector<int> numbers, int k) {
        vector<vector<int>> pairs = {};

        size_t leftIndex = 0;
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

    // Checking whether it's palindrome or not.
    void isPalindrome(string str) {
        int leftIndex = 0;
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
            bool isLeftCharValid = isValidChar(str[leftIndex]);

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

    // Remove duplicates
    vector<int> removeDuplicates(vector<int> numbers) {
        if (numbers.empty())
            return {};

        size_t leftIndex = 0;
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

    // Moving zeros
    vector<int> moveZeros(vector<int>& numbers) {
        if (numbers.empty())
            return {};

        // Technique 1;
        if (0) {
            size_t leftIndex = 0;
            size_t rightIndex = 0;

            while (rightIndex < numbers.size()) {
                if (numbers[rightIndex] != 0) {
                    numbers[leftIndex] = numbers[rightIndex];
                    leftIndex++;
                }

                rightIndex++;
            }

            return vector<int>(numbers.begin(), numbers.begin() + leftIndex);
        }

        // Technique 2;
        size_t size = numbers.size();

        size_t leftIndex = 0;
        size_t rightIndex = 1;

        while (rightIndex < size) {
            while (leftIndex < size && numbers[leftIndex] != 0)
                leftIndex++, rightIndex++;

            while (rightIndex < size && numbers[rightIndex] == 0)
                rightIndex++;

            if (rightIndex < size) {
                numbers[leftIndex] = numbers[rightIndex];
                leftIndex++;
                rightIndex++;
            }
        }

        return vector<int>(numbers.begin(), numbers.begin() + leftIndex);
    }

    // Merge sorted array
    vector<int> mergeSort(vector<int>& numsOne, vector<int>& numsTwo) {
        if (numsOne.empty() || numsTwo.empty())
            return numsOne.empty() ? numsTwo : numsOne;

        // We can use two pointer and new vector for acheiving this but, space complexity will be
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

    // Container with most water problem
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
        int maxContainerArea = 0;

        int leftIndex = 0;
        int rightIndex = heights.size() - 1;

        while (leftIndex < rightIndex) {
            int leftHeight = heights[leftIndex];
            int rightHeight = heights[rightIndex];

            int minHeight = min(leftHeight, rightHeight);
            int width = rightIndex - leftIndex;
            int capcity = minHeight * width;

            if (leftIndex < rightHeight)
                leftIndex++;
            else
                rightIndex--;

            maxContainerArea = max(maxContainerArea, capcity);
        }

        return maxContainerArea;
    }

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
            int leftValue = numbers[negativeIndex];
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

        traverse(squaredValues, "Printing all sorted array: ");
    }

    // Main function
    void main() {
        cout << endl << "Basic Problems: " << endl;

        // Two Sum Problem
        vector<int> arr = {2, 7, 11, 15};
        computeTwoSum(arr, 9);

        // IsPalindrome problem
        isPalindrome("madam");
        isPalindrome("car racing");

        // Removing duplicates in place
        vector<int> duplicateNumbers = {1, 1, 1, 2, 3, 4, 5, 5, 5};
        traverse(removeDuplicates(duplicateNumbers), "Unique numbers are: ");

        // Moving zero elements towards right
        vector<int> numbers = {0, 1, 0, 3, 12};
        traverse(moveZeros(numbers), "Zero free numbers are: ");

        // Merge sorted array
        vector<int> sortedNumberF = {1, 3, 5, 7};
        vector<int> sortedNumberS = {2, 4, 6};
        traverse(mergeSort(sortedNumberF, sortedNumberS), "After merging: ");

        // Container with most water
        vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        calculateMaxContainerArea(heights);

        // Square of sorted array
        vector<int> sortedNumbers = {-4, -1, 0, 3, 10};
        computeSortedSquares(sortedNumbers);

        cout << endl << endl;
    }
}  // namespace basic

// Medium Level
namespace medium {
    vector<vector<int>> evaluateThreeSum(vector<int> nums, int target) {
        vector<vector<int>> possiblePairs = {};

        size_t size = nums.size();

        // Sorting the nums array.
        sort(nums.begin(), nums.end());

        for (int fixedIndex = 0; fixedIndex < size - 2; fixedIndex++) {
            int leftIndex = fixedIndex + 1;
            int rightIndex = size - 1;

            while (leftIndex < rightIndex) {
                int totalSum = nums[fixedIndex] + nums[leftIndex] + nums[rightIndex];

                if (totalSum == target) {
                    possiblePairs.push_back({nums[fixedIndex], nums[leftIndex], nums[rightIndex]});

                    leftIndex++;
                    rightIndex--;

                    // Skiping duplicates from left
                    while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1])
                        leftIndex++;

                    // Skiping duplicates from right
                    while (rightIndex > leftIndex && nums[rightIndex] == nums[rightIndex - 1])
                        rightIndex--;
                }

                if (totalSum > target)
                    rightIndex--;
                else
                    leftIndex++;
            }
        }

        return possiblePairs;
    }

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

                int leftIndex = j + 1;
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

    int computeMinimumSubarraySum(vector<int> nums, int target) {
        int size = nums.size();

        int totalSum = 0;
        int leftIdx = 0;
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

    int evaluateMaximumTrappedWater(vector<int> heights) {
        /*
            Example 1:
                    arr = [3, 0, 2, 0, 4]

                    * Array elements represents the height of the vertical line.
                    * Water will trap between vertical lines so we have to evaluate the thing.
        */

        if (heights.size() < 2)
            return 0;

        size_t size = heights.size();

        size_t leftIndex = 1;
        size_t rightIndex = size - 2;

        int maxLeftHeight = heights[0];
        int maxRightHeight = heights[size - 1];

        int totalTrappedWater = 0;

        while (leftIndex <= rightIndex) {
            int currentLeftHeight = heights[leftIndex];
            int currentRightHeight = heights[rightIndex];

            int minHeight = min(maxLeftHeight, maxRightHeight);

            if (maxLeftHeight > maxRightHeight) {
                if (maxRightHeight >= currentRightHeight) {
                    totalTrappedWater += (minHeight - currentRightHeight);
                } else {
                    maxRightHeight = currentRightHeight;
                }

                rightIndex--;
            } else {
                if (maxLeftHeight >= currentLeftHeight) {
                    totalTrappedWater += (minHeight - currentLeftHeight);
                } else {
                    maxLeftHeight = currentLeftHeight;
                }

                leftIndex++;
            }
        }

        return totalTrappedWater;
    }

    void solveDutchFlag(vector<int>& nums) {
        size_t size = nums.size();

        int leftIdx = 0;
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

    void solveDutchFlagThreePT(vector<int>& colors) {
        if (colors.empty())
            return;
    }

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

    int countSubarrayProducts(const vector<int>& nums, int k) {
        if (nums.empty())
            return 0;

        size_t size = nums.size();

        int slow = 0;
        int fast = 0;

        int totalProducts = 1;
        int totalCounts = 0;

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

    // Main function
    void main() {
        // find three sum
        vector<int> threeSumNums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> possiblePairs = evaluateThreeSum(threeSumNums, 0);

        cout << "Possible pairs for three sum are: " << endl;
        for (const vector<int>& pairs : possiblePairs) {
            for (const int& p : pairs) {
                cout << p << " ";
            }
            cout << endl;
        }

        // find four sum
        vector<int> fourSumNums = {-1, 0, 1, 2, -1, -4};
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
        cout << "Total trapped water is: " << evaluateMaximumTrappedWater(heightForRain) << endl;

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
    }
}  // namespace medium

// Advance Level
namespace hard {
    // Main function
    void main() {
        // CALLING ALL THE METHOD
    }
}  // namespace hard

int main() {
    cout << "Intro: " << endl;
    intro::main();

    cout << "Basic Problems: " << endl;
    basic::main();
    cout << endl << endl;

    cout << "Medium Problems: " << endl;
    medium::main();
    cout << endl << endl;

    cout << "Hard Problems: " << endl;
    hard::main();
    cout << endl << endl;

    return 0;
}