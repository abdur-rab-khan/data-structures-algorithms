#include <bits/stdc++.h>
using namespace std;

/*
    <=================> Check if Strings Are Rotations of Each Other <=================>

    ◎ Given two string "s1" and "s2", task is to check whether "s2" is rotation of "s1".
    ◎ A string is said to be a rotation of another, if it can obtained by shifting some leading
            character of the original string to its end without changing the order of characters.

    <=================> Examples <=================>

    ◎ Example 1:
                s1 = "abcd", s2 = "cdab"
                output = true

                ◎ After "two" rotation, s1 will become equal to s2.

    ◎ Example 2:
                s1 = "aab", s2 = "aba"
                output = true

                ◎ After "one" rotation, s1 will become equal to s2.

    ◎ Example 3:
                s1 = "abcd", s2 = "acbd"
                output = true
*/

// Naive Approach TIME_COMPLEXITY o(n²), SPACE_COMPLEXITY o(1)
bool checkRotateStr(string& s1, string& s2) {
    if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < s1.length(); i++) {
        // If both s1 and s2 are same after rotation simply return true
        if (s1 == s2)
            return true;

        char last = s1.back();
        s1.pop_back();
        s1 = last + s1;
    }

    return false;
}

// Constructing LPS array
vector<int> constructLPS(string str) {
    int n = str.length();

    vector<int> lps(n, 0);

    int i = 1;
    int prevLPS = 0;

    while (i < n) {
        if (str[i] == str[prevLPS]) {
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

// Using KMP Algorithm TIME_COMPLEXITY o(n), SPACE_COMPLEXITY o(1)
bool checkRotateKMP(string& s1, string& s2) {
    if (s1.length() != s2.length())
        return false;

    string conS1 = s1 + s1;
    vector<int> lps = constructLPS(conS1);

    // Let's start search s2 with lps, If some where they same means, it will same after certain
    // rotation.
    int i = 0;
    int j = 0;
    while (i < conS1.length()) {
        if (conS1[i] == s2[j]) {
            i++;
            j++;

            if (j == s2.length()) {
                return true;
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }

    return false;
}

int main() {
    string s1 = "abcd";
    string s2 = "acbd";

    // string s1 = "aab";
    // string s2 = "aba";

    cout << "Using Naive Approach: " << endl;
    cout << (checkRotateStr(s1, s2) ? "true" : "false") << endl;

    cout << "Using KMP Algorithm: " << endl;
    cout << (checkRotateKMP(s1, s2) ? "true" : "false") << endl;

    return 0;
}