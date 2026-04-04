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
| 🟡 Pattern 4. "Rotated Sorted Array":                                                                                                                                                                               |
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
    // CLASSIC BINARY SEARCH PROBLEMS
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

    // HASHMAP PATTERN
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

    // FIXED WINDOW
    float findMaximumAvgSubarray(const vector<int>& numbers, int maxSize) {
        int leftIndex = 0;

        int maximumAvg = 0;
        int totalSum = 0;

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
        }

        return maximumAvg;
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
    void main() {
        cout << "Easy Problems: " << endl;
        // PROBLEMS
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
    easyProblems::main();
    mediumProblems::main();
    hardProblems::main();

    return 0;
}