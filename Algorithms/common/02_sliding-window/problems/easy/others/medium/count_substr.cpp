#include <bits/stdc++.h>
using namespace std;

/*
    <=====================> Count substrings with k distinct characters <=====================>

    ◎ Given a string "s" containing lowercase english latter and an integer "k".
    ◎ Our task is to find total number of substrings (not necessary distinct) of "s" that contain
        exactly "k" distinct characters.

    -> Example:

    Input: s = "abc", k = 2
    Output: 2
    Explanation: Possible substrings are ["a", "ab", "abc", "b", "bc", "c"]
                "a" -> 1 distinct char ❌
                "ab" -> 2 distinct char ✔️
                "abc" -> 3 distinct char ❌
                "b" -> 1 distinct char ❌
                "bc" -> 2 distinct char ✔️
                "c" -> 1 distinct char ❌

            TOTAL COUNT: 2

    Input: s = "aba", k = 2
    Output: 3
    Explanation: Possible substring are ["a", "ab", "aba", "b", "ba", "a"]
                 "a" -> 1 distinct char ❌
                "ab" -> 2 distinct char ✔️
                "aba" -> 2 distinct char ✔️
                "b" -> 1 distinct char ❌
                "bc" -> 2 distinct char ✔️
                "c" -> 1 distinct char ❌

            TOTAL COUNT: 2

    Input: s = "aa", k = 1
    Output: 2
    Explanation: Possible substrings are ["a", "aa", "a"]
                "a" -> 1 distinct char ✔️
                "aa" -> 1 distinct char ✔️
                "a" -> 1 distinct char ✔️

            TOTAL COUNT: 3
*/

// Using brute force approach o(n²) Time o(1) Space
int countSubStrBR(string& str, int k) {
    int n = str.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // array to check if a character
        // is present in substring i..j
        vector<bool> cntChar(26, false);
        int distinctCnt = 0;

        for (int j = i; j < n; j++) {
            // Only increase count if visited for first time.
            if (cntChar[str[j] - 'a'] == false) {
                cntChar[str[j] - 'a'] = true;
                distinctCnt++;
            }

            // Increase count
            if (distinctCnt == k)
                cnt++;
        }
    }

    return cnt;
}

int count(string& str, int k) {
    int n = str.size();
    int ans = 0;

    // Using sliding window technique
    vector<int> freq(26, 0);
    int distCnt = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
        freq[str[j] - 'a']++;
        if (freq[str[j] - 'a'] == 1)
            distCnt++;

        while (distCnt > k) {
            freq[str[i] - 'a']--;
            if (freq[str[i] - 'a'] == 0)
                distCnt--;

            i++;
        }

        ans += j - i + 1;
    }

    return ans;
}

// Using Sliding Window Technique o(n) Time and o(1) Space
int countSubStr(string& str, int k) {
    cout << endl << count(str, k) << " - " << count(str, k - 1) << endl;

    return (count(str, k) - count(str, k - 1));
}
/*
    <==================> LET'S UNDERSTAND HOW IT WORKS <==================>

    ◎ We use sliding window technique to count the number of substrings with at most k distinct
        characters.
    ◎ Instead of counting substrings with exactly k distinct characters directly, we count the
        number of substrings with at most k distinct characters and subtract the number of
        substrings with at most (k-1) distinct characters from it.
    ◎ This is because the substrings with exactly k distinct characters are included in the
        substrings with at most k distinct characters but not in the substrings with at most (k-1)
        distinct characters.

    ◎ It works as follows:
        -> We maintain a sliding window defined by two pointers, i and j.
        -> We expand the window by moving the right pointer j and include characters in the window.
        -> We keep track of the frequency of characters in the current window using a frequency
            array.
        -> If the number of distinct characters in the window exceeds k, we shrink the window by
            moving the left pointer i until we have at most k distinct characters.
        -> For each position of j, we add the number of valid substrings ending at j to the answer.
        -> The number of valid substrings ending at j is given by (j - i + 1), which
            represents all substrings that can be formed with the current window.

    ◎ Finally, we return the difference between the counts of substrings with at most k
        distinct characters and at most (k-1) distinct characters to get the count of substrings
        with exactly k distinct characters.
*/

int main() {
    string s = "abc";
    string s1 = "aa";
    string s2 = "aba";

    cout << "Using Brute Force Approach: " << endl;
    cout << "Count Substrings for " << s << " : " << countSubStrBR(s, 2) << endl;
    cout << "Count Substrings for " << s1 << " : " << countSubStrBR(s1, 1) << endl;
    cout << "Count Substrings for " << s2 << " : " << countSubStrBR(s2, 2) << endl;

    cout << "Using Sliding Window Approach: " << endl;
    cout << "Count Substrings for " << s << " : " << countSubStr(s, 2) << endl;
    cout << "Count Substrings for " << s1 << " : " << countSubStr(s1, 1) << endl;
    cout << "Count Substrings for " << s2 << " : " << countSubStr(s2, 2) << endl;

    return 0;
}