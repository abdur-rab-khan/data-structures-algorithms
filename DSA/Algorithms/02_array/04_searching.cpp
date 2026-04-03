#include <bits/stdc++.h>
using namespace std;

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
        int leftIndex = 0, rightIndex = numbers.size() - 1;

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

int main() {
    linearSearch::main();
    binarySearch::main();
    return 0;
}