#include <bits/stdc++.h>

#include <cassert>
using namespace std;

/**
 * Reverses a string represented as a vector of characters in place.
 *
 * This function swaps characters from both ends of the vector until the
 * middle is reached, so the original order is reversed without using extra
 * space.
 *
 * Example:
 * Input: str = ['h', 'e', 'l', 'l', 'o']
 * Output: ['o', 'l', 'l', 'e', 'h']
 *
 * Example:
 * Input: str = ['H', 'a', 'n', 'n', 'a', 'h']
 * Output: ['h', 'a', 'n', 'n', 'a', 'H']
 *
 * Time Complexity: O(n) - Swaps each character at most once
 * Space Complexity: O(1) - Uses only constant extra space
 *
 * @param str Vector of characters to reverse in place
 */
void reverseString(vector<char>& str) {
    int leftIndex = 0;
    int rightIndex = str.size() - 1;

    while (leftIndex < rightIndex) {
        swap(str[leftIndex++], str[rightIndex--]);
    }
}

int main() {
    vector<char> str = {'o', 'l', 'l', 'e', 'h'};
    reverseString(str);

    cout << "String is: ";
    for (const char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    vector<char> str2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(str2);

    cout << "String is: ";
    for (const char ch : str2) {
        cout << ch << " ";
    }
    cout << endl;

    // Testing
    vector<char> expected = {'h', 'e', 'l', 'l', 'o'};
    assert(str == expected);

    vector<char> expected2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    assert(str2 == expected2);

    return 0;
}
