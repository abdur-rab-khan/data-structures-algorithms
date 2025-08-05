#include <bits/stdc++.h>
using namespace std;

/*
    <=============> FIND LONGEST PREFIX ALSO SUFFIX <=============>

    ◎ Given a string "s", find the length of longest "prefix proper prefix" which is also "suffix".
    ◎ A proper prefix is a string that does not include "whole string".
    ◎ For Example:
                    prefix of "abc" are "a", "ab" and "abc".
                    proper prefix of "abc" are "a", "ab".
*/

// Naive Approach TIME_COMPLEXITY o(n²)
int findLongestLPS(string str) {
    // Declaring prefix/suffix
    // string prefix;
    // string suffix;

    int length = 1;
    int n = str.length();

    for (int i = 1; i < n; i++) {
        // APPROACH 1
        // prefix = "";
        // suffix = "";

        // // Finding Prefix;
        // for (int j = 0; j <= i; j++) {
        //     prefix += str[j];
        // }

        // // Find Suffix;
        // for (int k = n - i; k <= n; k++) {
        //     suffix += str[k];
        // }

        // if (prefix == suffix)
        //     length = prefix.length();
        bool isBSame = true;
        int len = n - i;

        // APPROACH 2
        for (int j = 0; j < i; j++) {
            if (str[j] != str[len + j]) {
                isBSame = false;
                break;
            }
        }

        if (isBSame)
            length = i;
    }

    return length;
}

// TODO: AGAIN THING ABOUT LONGEST-PREFIX-SUFFIX -- HOW IT WORKS
int findLongestLPS_KMP(string str) {
    int n = str.length();
    vector<int> lps(n, 0);

    int longest = 0;

    lps[0] = 0;  // Always

    int i = 1;
    int prevLPS = 0;
    while (i < n) {
        if (str[i] == str[prevLPS]) {
            prevLPS++;
            lps[i] = prevLPS;
            i++;

            if (prevLPS > longest) {
                longest = prevLPS;
            }
        } else {
            if (prevLPS == 0) {
                i++;
            } else {
                prevLPS = lps[prevLPS - 1];
            }
        }
    }

    return longest;
}

int main() {
    string s = "aabcdaabc";
    string s1 = "aaaa";

    cout << "Using naive approach" << endl;
    cout << "The LPS of " << s << " is: " << findLongestLPS(s) << endl;
    cout << "The LPS of " << s1 << " is: " << findLongestLPS(s1) << endl;

    cout << "Using KMP approach" << endl;
    cout << "The LPS of " << s << " is: " << findLongestLPS_KMP(s) << endl;
    cout << "The LPS of " << s1 << " is: " << findLongestLPS_KMP(s1) << endl;

    return 0;
}