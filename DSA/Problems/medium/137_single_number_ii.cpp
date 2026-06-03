#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the unique number in an array where every other number appears three times.
 *
 * This function checks each bit position across all numbers, counts how many
 * times that bit is set, and then keeps only the remainder after dividing by 3.
 * Since all repeated numbers appear exactly three times, their bits cancel out
 * and only the bits of the unique number remain.
 *
 * Example:
 * Input: nums = [2, 2, 3, 2]
 * Output: 3 (3 appears once, 2 appears three times)
 *
 * Example:
 * Input: nums = [0, 1, 0, 1, 0, 1, 99]
 * Output: 99 (99 appears once, 0 and 1 appear three times)
 *
 * Time Complexity: O(32 * n) - Checks 32 bits for each number
 * Space Complexity: O(1) - Uses only constant extra space
 *
 * @param nums Vector of integers where all appear three times except one
 * @return The unique number that appears only once
 */
int singleNumber(const vector<int>& nums) {
    int uniqueNumber = 0;

    for (int i = 0; i < 32; i++) {
        int setBitCount = 0;

        for (const int& n : nums) {
            if ((n & (1 << i)) != 0)
                setBitCount++;
        }

        uniqueNumber |= ((setBitCount % 3) << i);
    }

    return uniqueNumber;
}

int testCount = 1;
void submitForTesting(vector<int> numbers, int expected) {
    int output = singleNumber(numbers);

    assert(output == expected);
    cout << "Test case no. " << testCount << " is done" << endl;
    testCount++;
}

int main() {
    submitForTesting({2, 2, 3, 2}, 3);
    submitForTesting({0, 1, 0, 1, 0, 1, 99}, 99);
    return 0;
}