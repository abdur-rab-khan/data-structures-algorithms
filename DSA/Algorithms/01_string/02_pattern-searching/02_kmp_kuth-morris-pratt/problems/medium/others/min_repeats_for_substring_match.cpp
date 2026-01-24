#include <bits/stdc++.h>
using namespace std;

/*
    <=================> Min Repeats for Substring Match <=================>

    ◎ Given string s1 and s2, How many repeats of s1 are needed to s2 becomes substring of s1.
    ◎ If it's not possible to s2 becomes substring of s1, then simply return -1.

    <===========> Examples <===========>

    ◎ Example 1:
                s1 = "abac", s2 = "cabaca"
                result = 3

                Explanation: After repeating s1 three times, s1 will becomes "cabacacabacacabaca"
                Now, You can see s2 becomes substring of s1 "cabaca'cabaca'cabaca", Also s2 is not
                substring of s1, when it repeated 3 times

    ◎ Example 2:
                s1 = "ab", s2 = "cab"
                result = -1

                Explanation: s2 can not becomes substring of s1, after any repetition of s1.

*/

// Naive Approach TIME_COMPLEXITY o(n * m) SPACE_COMPLEXITY o(1)
int minRepeatsSubstrings(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    for (int i = 0; i < n; i++) {
        int rep = 1, idx1 = i;
        bool isFound = true;

        for (int idx2 = 0; idx2 < m; idx2++) {
            // Here we check s1[idx1 % n] != s[idx2]
            // Why using "s1[idx1 % n]" ==> If somehow idx1 is equal to n then simply check will 0
            // (4 % 4 = 0)
            if (s1[idx1 % n] != s2[idx2]) {
                isFound = false;
                break;
            }

            idx1++;

            // If we have reached at the end of s1, simply reset the index to 0
            if (idx1 == n) {
                idx1 = 0;

                // There will be condition occur where we are at the end of s2, at this movement
                // repeat not happen.
                // If we have remaining characters in s2, then s1 needs to repeated again so
                // increment repetitions by 1.
                if (idx2 != m - 1)
                    rep++;
            }
        }

        // If s2 is found, return the number times s1 repeated.
        if (isFound)
            return rep;
    }

    // If no occurrence of s2 is found simply return -1
    return -1;
}

// Expected Approach Using LPS TIME_COMPLEXITY o(n + m) SPACE_COMPLEXITY (1)
vector<int> constructLPS(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    rev = str + "$" + rev;

    int n = rev.length();

    vector<int> lps(n, 0);

    lps[0] = 0;  // LPS[0] will always 0.

    int i = 1;
    int prevLPS = 0;

    while (i < n) {
        if (rev[i] == rev[prevLPS]) {
            prevLPS++;
            lps[i] = prevLPS;
            i++;
        } else {
            if (prevLPS == 0) {
                i++;
            } else {
                prevLPS = lps[prevLPS - 1];
            }
        }
    }

    return lps;
}

int KMPSearch(string s1, string s2) {
    return -1;
}

int main() {
    string s1 = "abac";
    string s2 = "cabaca";

    cout << "Min Repeats for Substrings: " << minRepeatsSubstrings(s1, s2);
    cout << "Min Repeats for Substrings: " << KMPSearch(s1, s2);

    return 0;
}