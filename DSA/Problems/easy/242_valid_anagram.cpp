#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// APPROACH 1 USING "''HASHMAP''"
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