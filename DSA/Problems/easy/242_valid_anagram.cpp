#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// APPROACH 1 USING "''HASHMAP''"
/**
 * Checks whether two strings are anagrams using a hash map.
 *
 * Counts the frequency of each lowercase letter in s, then decrements using t.
 * Non-alphabetic characters are ignored, and it assumes lowercase a-z input
 * for correct indexing.
 *
 * Example:
 * Input: s = "cat", t = "act"
 * Output: true
 *
 * Example:
 * Input: s = "computer", t = "desktop"
 * Output: false
 *
 * Time Complexity: O(n) - Single pass over both strings
 * Space Complexity: O(1) - Fixed alphabet size (26)
 *
 * @param s First string
 * @param t Second string
 * @return True if s and t are anagrams, otherwise false
 */
bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<int, int> charTracker(26);

    // Adding element for tracking
    for (const char ch : s) {
        if (!isalpha(ch))
            continue;

        int charNo = ch - 'a';
        charTracker[charNo]++;
    }

    // Checking whether every elements exists or not.
    for (const char ch : t) {
        if (!isalpha(ch))
            continue;

        int charNo = ch - 'a';
        if (charTracker.count(charNo)) {
            charTracker[charNo]--;
            if (charTracker[charNo] == 0)
                charTracker.erase(charNo);
        }
    }

    return charTracker.size() == 0;
}

// APPROACH 2 USING "''ARRAY''";
/**
 * Checks whether two strings are anagrams using a fixed-size array.
 *
 * Increments counts for s and decrements for t in the same loop, then verifies
 * all counts return to zero. Assumes lowercase a-z input.
 *
 * Example:
 * Input: s = "evil", t = "liev"
 * Output: true
 *
 * Example:
 * Input: s = "abc", t = "abd"
 * Output: false
 *
 * Time Complexity: O(n) - Single pass over both strings
 * Space Complexity: O(1) - Fixed array of size 26
 *
 * @param s First string
 * @param t Second string
 * @return True if s and t are anagrams, otherwise false
 */
bool isAnagram1(string s, string t) {
    if (s.size() != t.size())
        return false;

    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (const int check : arr) {
        if (check != 0)
            return false;
    }

    return true;
}

int testCount = 0;
void submitForTesting(string s, string t, bool expected) {
    bool checkIsAnagram = isAnagram(s, t);

    assert(checkIsAnagram == expected);
    cout << "Test no." << testCount << " passed successfully" << endl;
    testCount++;
}

int main() {
    submitForTesting("cat", "act", true);
    submitForTesting("evil", "liev", true);
    submitForTesting("computer", "desktop", false);

    return 0;
}