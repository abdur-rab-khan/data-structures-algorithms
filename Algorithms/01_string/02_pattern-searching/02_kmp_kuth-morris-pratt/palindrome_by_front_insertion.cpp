#include <bits/stdc++.h>
using namespace std;

/*
    <======================> Palindrome by Front Insertion <======================>

    ◎ Given a string "s" consisting only lowercase english letters.
    ◎ Find the minimum number of character that are need to be added to the front of "s" to make it
        a palindrome.

    <===============> Examples <================>

    Example 1:
                s = "abc";
                output = 2;
                ◎ There are two characters required to build a palindrome by using string "s",
                    "abc" So "cb" two characters are required to build a palindrome.

    Example 2:
                s = "aacecaaaa";
                output = 2;
                ◎ There are two characters required to build a palindrome, "abc" So "cb" two
                    characters are required to build a palindrome.

    <===============> How it works <================>

    Example 1:
    str = [a, b, c]
    revStr = [c, b, a]

    conStr = [a, b, c, $, c, b, a]
    lps = [0, 0, 0, 0, 0, 1]

    Example 2:
    str = [a, a, c, e, c, a, a, a, a]
    revStr = [a, a, a, a, c, e, c, a, a]

    conStr = [a, a, c, e, c, a, a, a, a, $, a, a, a, a, c, e, c, a, a]
    lsp = [0, 1, 0, 0, 0, 1, 2, 2, 0, 1, 2, 2, 2, 3, 4, 5, 6, 7]

    ◎ To fully understand we have to know what actually lps give, LPS give the longest prefix/suffix
    ◎ What if we create LPS from str + $ + revStr??, At lps.back() We will get how many pairs of
        palindrome is there.
    ◎ If we see above example we will get 1, means only str[0] itself is a
        palindrome
    ◎ If we see in second example we have longest 7 pairs of palindrome "aacecaa". 9 - 7 = 2, TWO
        pairs we needed to build a palindrome.
*/

bool isPalindrome(string s, int i, int j) {
    bool palindrome = true;

    while (i < j) {
        if (s[i] != s[j]) {
            palindrome = false;
            break;
        }

        i++;
        j--;
    }

    return palindrome;
}

// Naive Approach by using O(n^2)
int mainChar(string& str) {
    int cnt = 0;
    int i = str.size() - 1;

    while (i >= 0 && !isPalindrome(str, 0, i)) {
        i--;
        cnt++;
    }

    return cnt;
}

// Expected Approach by using KMP LSP array ==> time and space complexity is o(n), o(1)
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

int mainChar2(string& str) {
    int n = str.length();

    vector<int> lps = constructLPS(str);

    return (n - lps.back());
}

int main() {
    string s = "abc";
    string s2 = "aacecaaaa";
    string s3 = "abca";

    cout << "Using First Method: " << endl;
    cout << "For num:" << s << " " << mainChar(s) << endl;
    cout << "For num:" << s2 << " " << mainChar(s2) << endl;

    // By using second method
    cout << endl << "Using Second Method: " << endl;
    cout << "For num:" << s << " " << mainChar2(s) << endl;
    cout << "For num:" << s2 << " " << mainChar2(s2) << endl;
    cout << "For num:" << s3 << " " << mainChar2(s3) << endl;

    return 0;
}