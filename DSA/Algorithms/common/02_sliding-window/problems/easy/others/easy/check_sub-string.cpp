#include <bits/stdc++.h>
using namespace std;

/*
    <===================> Check if Permutation of Pattern is Substring <===================>

    ◎ Given a string "txt" and "pat" in lowercase, task is to check if any permutation of "pat" is a
        substring of "txt".
    ◎ "Permutation of pat" means any arrangement of characters of "pat" like "abc" -> "abc", "acb",
        "bac", "bca", "cab", "cba".
    ◎ "Substring of txt" means any contiguous sequence of characters in "txt".
        For example, "abc" is a substring of "abdec" but "acb" is not.

    → Example 1:
        Input: txt = "oidbcaf", pat = "abc"
        Output: true
        Explanation: "bca" is a permutation of "abc" and is a substring of "oidbcaf". "bca" is the
                        permutation of pat so "abc" -> "abc", "cba", "bca" --> "bca" found in txt.

    → Example 2:
        Input: txt = "odicf", pat = "dc"
        Output: false
        Explanation: No permutation of "dc" is a substring of "odicf".

    → Example 3:
        Input: txt = "geeks", pat = "eke"
        Output: true
        Explanation: "eke" is a permutation of "eke" and is a substring of "geeks".

    ◎ Understand that we have to check any arrangement of characters of "pat" is substring of "txt".
*/

const int MAX_SIZE = 26;

// Time complexity o(m) Space Complexity o(n)
bool arePermutation(string& txt, int startIdx, string& pat) {
    vector<int> hash(MAX_SIZE, 0);

    // Let's prepare hash in this hash we decrease the position of txt char by -1.
    // And if that char again found in pat than increase by 1.
    // At the end, we found that all char in pat are there in txt.
    for (int i = 0; i < pat.size(); i++) {
        // Decrease the position by 1;
        hash[(txt[startIdx + i]) - 'a'] -= 1;

        // Increase the position by 1;
        hash[(pat[i]) - 'a'] += 1;
    }

    for (const int& n : hash) {
        if (n != 0)
            return false;
    }
    return true;
}

// Total Time Complexity o(n * m) and Space Complexity o(n)
bool search(string& txt, string& pat) {
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i < n - m + 1; i++) {
        // Check if substring in txt starting from i
        // is a permutation of pat
        if (arePermutation(txt, i, pat)) {
            return true;
        }
    }

    return false;
}

bool check(vector<int>& hash) {
    for (const int& n : hash) {
        if (n != 0)
            return false;
    }

    return true;
}

// LET'S USE "SLIDING WINDOW TECHNIQUE" -> o(n * MAX_SIZE), o(MAX_SIZE)
bool searchOP(string& txt, string& pat) {
    int n = txt.size(), m = pat.size();  // Size of pat and txt
    vector<int> hash(MAX_SIZE, 0);

    // Let's build hash for first window
    for (int i = 0; i < m; i++) {
        // Decrease
        hash[(txt[i]) - 'a'] += 1;

        // Increase
        hash[pat[i] - 'a'] -= 1;
    }

    if (check(hash))
        return true;

    for (int i = m; i < n; i++) {
        // Decrease
        hash[(txt[i]) - 'a'] += 1;

        // Increase
        hash[(txt[i - m]) - 'a'] -= 1;

        if (check(hash))
            return true;
    }

    return false;
}

int main() {
    string txt = "oidbcaf";
    string pat = "abc";

    cout << "Is " << txt << " is permutation of " << pat << ": "
         << (search(txt, pat) ? "true" : "false") << "\n";
    cout << "Is " << txt << " is permutation of " << pat << ": "
         << (searchOP(txt, pat) ? "true" : "false") << "\n";

    return 0;
}