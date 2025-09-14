#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Longest Substring Without Repeating Characters <==================>

    ◎ Given a string "s" having lowercase characters. Our task is to find longest substring without
        repeating characters.

    -> EXAMPLE

    Input: s = "geeksforgeek"
    Output: 7
    Explanation: The longest substrings without repeating characters are "eksforg” and "ksforge",
                    with lengths of 7.

    Input: s = "aaa"
    Output: 1
    Explanation: The longest substring without repeating characters is "a"

    Input: s = "abcdefabcbb"
    Output: 6
    Explanation: The longest substring without repeating characters is "abcdef".
*/

// Brute force approach TIME_COMPLEXITY o(n²) SPACE_COMPLEXITY o(1)
int longestSubstringBR1(string& str) {
    int n = str.size();
    int maxLen = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Initialize all character as not visited.
        vector<bool> vis(26, false);

        for (int j = i; j < n; j++) {
            // If already visited simply, break the loop.
            if ((vis[str[j] - 'a']) == true)
                break;
            // Else mark current character as visited, update window size.
            else {
                maxLen = max(maxLen, j - i + 1);
                vis[str[j] - 'a'] = true;
            }
        }
    }

    return maxLen;
}

// Expected Approach Using Sliding Widnow o(n) Time and o(1) Space.
int longestSubstring(string& str) {
    if (str.length() == 0 || str.length() == 1)
        return str.length();

    int n = str.size();
    int maxLen = INT_MIN, start = 0;

    // Initialize all character as not visited
    vector<bool> vis(26, false);
    vis[str[start] - 'a'] = true;  // Making first element as visited

    // Let's find maxSubstring
    for (int i = 1; i < n; i++) {
        if (vis[str[i] - 'a'] == true) {
            // Mark all visited as false from start to i.
            while (vis[str[start] - 'a'] == true) {
                vis[str[start] - 'a'] = false;
                start++;
            }
        }

        maxLen = max(maxLen, i - start + 1);
        vis[str[i] - 'a'] = true;
    }

    return maxLen;
}

// Using Last Index of Each Characters o(n) Time and o(1) Space
int longestSubString(string& s) {
    int n = s.size(), start = 0;
    int maxLen = INT_MIN;

    vector<bool> lastIndex(26, -1);

    for (int end = 0; end < n; end++) {
        start = max(start, lastIndex[s[end] - 'a'] + 1);

        // Update result if we get a larger window
        maxLen = max(maxLen, end - start + 1);

        // Update last index of s[end]
        lastIndex[s[end] - 'a'] = end;
    }

    return maxLen;
}

int main() {
    string s = "geeksforgeeks";
    string s2 = "abcdefabcbb";
    string s3 = "aaaaaaa";

    // Using Brute force method
    cout << "Using brute force method: " << endl;
    cout << "Max Substring length is: " << longestSubstringBR1(s) << endl;
    cout << "Max Substring length is: " << longestSubstringBR1(s2) << endl;
    cout << "Max Substring length is: " << longestSubstringBR1(s3) << endl;

    // Using Sliding Window Technique
    cout << "Using Sliding Window Technique: " << endl;
    cout << "Max Substring length is: " << longestSubstring(s) << endl;
    cout << "Max Substring length is: " << longestSubstring(s2) << endl;
    cout << "Max Substring length is: " << longestSubstring(s3) << endl;

    // Using Sliding Window Technique
    cout << "Using Last Index of Each Character: " << endl;
    cout << "Max Substring length is: " << longestSubString(s) << endl;
    cout << "Max Substring length is: " << longestSubString(s2) << endl;
    cout << "Max Substring length is: " << longestSubString(s3) << endl;

    return 0;
}