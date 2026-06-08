#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the unique number in an array where every other number appears twice.
 *
 * Given an array of integers where all elements appear exactly twice except for
 * one element which appears only once, find and return that unique element.
 * This solution uses the XOR (bitwise exclusive OR) operation, which has the
 * property that a ^ a = 0 and a ^ 0 = a. Therefore, XORing all elements will
 * cancel out all pairs and leave only the unique element.
 *
 * Example:
 * Input: numbers = [2, 2, 1]
 * Output: 1 (1 appears once, 2 appears twice)
 *
 * Example:
 * Input: numbers = [4, 1, 2, 1, 2]
 * Output: 4 (4 appears once, 1 and 2 appear twice)
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - Only uses constant extra space
 *
 * @param numbers Vector of integers where all appear twice except one
 * @return The unique number that appears only once
 */
int uniqueNumber(const vector<int>& numbers) {
    int unique = 0;

    for (int i = 0; i < numbers.size(); i++) {
        unique ^= numbers[i];
    }

    return unique;
}

int main() {
    vector<int> numbers1 = {2, 2, 1};
    cout << "Unique number from numbers1 is: " << uniqueNumber(numbers1) << endl;

    vector<int> numbers2 = {4, 1, 2, 1, 2};
    cout << "Unique number from numbers1 is: " << uniqueNumber(numbers2) << endl;

    vector<int> numbers3 = {1};
    cout << "Unique number from numbers1 is: " << uniqueNumber(numbers3) << endl;

    return 0;
}