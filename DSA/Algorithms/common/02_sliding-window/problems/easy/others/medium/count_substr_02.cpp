#include <bits/stdc++.h>
using namespace std;

/*
    <======================> Count of substrings of length K with exactly K-1 distinct characters
   <======================>

    ◎ Given a string "s" consisting of lowercase characters and an integer "k". find the count of
        all substring of length "k" which have exactly "k - 1" distinct characters.

    -> Examples:

    Input: s = "aabab", k = 3
    Output: 3
    Explanation: Substrings of length 3 are "aab", "aba", "bab". All 3 substrings contains 2
                distinct characters.

    Input: s = "abcc", k = 2
    Output: 1
    Explanation: Substrings of length 2 are "ab", "bc" and "cc". Only "cc" has 2-1 = 1 distinct
                character.
*/

// Using Brute force approach o(n²) Time o(1) Space
int subStrCount(string& s, int k) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n - k + 1; i++) {
        vector<bool> vis(26, false);  // Initialize vis and mark all element as non-visited
        int distCnt = 0;

        for (int j = i; j < i + k; j++) {
            if (vis[s[j] - 'a'] == false) {
                vis[s[j] - 'a'] = true;
                distCnt++;
            }
        }

        if (distCnt == k - 1)
            count++;
    }

    return count;
}

// Using Sliding Window Technique o(n) Time o(1) Space
int subStrCountSW(string& s, int k) {
    int n = s.length();
    int count = 0;

    // Initialize freq to use
    vector<int> freq(26, 0);
    int distCnt = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 1)
            distCnt++;

        if ((i - start) % k == 0) {
            if (distCnt == k - 1) {
                count++;
            } else {
                if (--freq[s[start++] - 'a'] == 0)
                    distCnt--;
            }
        }
    }

    return count;
}

int main() {
    string s = "aabab";
    int k = 3;

    string s1 = "abcc";
    int k1 = 2;

    cout << "Using Brute Force Approach: " << endl;
    cout << "Count Substring for " << s << " : " << subStrCount(s, k) << endl;
    cout << "Count Substring for " << s1 << " : " << subStrCount(s1, k1) << endl;

    cout << "Using Sliding Window Technique: " << endl;
    cout << "Count Substring for " << s << " : " << subStrCountSW(s, k) << endl;
    cout << "Count Substring for " << s1 << " : " << subStrCountSW(s1, k1) << endl;

    return 0;
}