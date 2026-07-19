#include <bits/stdc++.h>
using namespace std;

/*
    <====================> Kuth Morris Pratt (KMP) Algorithm <====================>

    ◉ KMP Algorithm is used to find "pattern" in a "text". It compares character by character from
        "left" to "right", but it avoid to re-checking characters after miss-match.
    ◉ Whenever miss-match happen after some matches, we already know part of the pattern has matched
        earlier. So KMP algorithm use that information through pre-processed LPS (Longest Prefix
        Suffix) array, to shift pattern efficiently, without restarting from the next character in
        the text.
    ◉ That reduce the time complexity from o(n * m) to o(m + n), where "n" is the length of "txt"
        and "m" in length of pattern.

    <====================> How to use LPS Table <====================>

    ◉ So LPS (Longest Prefix and Suffix) is a "Longest Prefix" which is also a "suffix".
    ◉ Let's Generate LPS (Longest Prefix and Suffix):

    ◉ ====================> Example 1 <=====================

    ptr = "ababc"
    lps = [0, 0, 0, 0]
    i = 1;
    length = 0;

    ◉ Step 1: lsp[0] is always 0.
                ◈ A single character has no prefix and suffix.
                lps = [0, ?, ?, ?]

    ◉ Step 2: i = 1 ('b')
                ◈ Compair ptr[i] == ptr[length], a == b;
                ◈ They don't match. length is already = 0, we can't go back otherwise we will.
                ◈ lps[i] = lps[1] = 0;
                ◈ Pattern: a "b" a b c
                ◈ Substring: "ab"
                ◈ Prefixes: "a"
                ◈ Suffixes: "b"
                ◈ Result: No match. Length is 0.
                ◈ LPS: [0, 0, ?, ?, ?]

    ◉ Step 3: i = 2 ('a')
                ◈ Compair ptr[i] == ptr[length], a == a;
                ◈ They match!
                ◈ Increase length by "1", Set lps[i] to length;
                ◈ Pattern: a b "a" b c
                ◈ Substring: "aba"
                ◈ Prefixes: "a", "ab"
                ◈ Suffixes: "a", "ba"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 2, ?]

    ◉ Step 4: i = 3 ('b')
                ◈ Compair ptr[i] == ptr[length], b == b;
                ◈ They match!
                ◈ Increase length to "2", Set lps[i] to length, lps[3] becomes 2;
                ◈ Pattern: a b a "b" c
                ◈ Substring: "abab"
                ◈ Prefixes: "a", "ab", "aba"
                ◈ Suffixes: "a", "ab", "bab"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 2, ?]

    ◉ Step 5: i = 4 ('c')
                ◈ Compair ptr[i] == ptr[length], c == b;
                ◈ They don't match. length is already = 0, we can't go back otherwise we will.
                ◈ At there instead of making lps[4] = 0, We need to check if a shorter prefix might
                    match. We "fall back" by setting length = lps[length - 1];
                ◈ Pattern: a b a b "c"
                ◈ Substring: "abab"
                ◈ Prefixes: "a", "ab", "aba"
                ◈ Suffixes: "a", "ab", "bab"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 2, 0]

    ◉ ====================> Example 2 <=====================

    ptr = "abaac"
    lps = [?, ?, ?, ?]
    i = 1;
    length = 0;

    ◉ Step 1: lsp[0] is always 0.
                ◈ A single character has no prefix and suffix.
                lps = [0, ?, ?, ?]

    ◉ Step 2: i = 1 ('b')
                ◈ Compair ptr[i] == ptr[length], a == b;
                ◈ They don't match. length is already = 0, we can't go back otherwise we will.
                ◈ lps[i] = lps[1] = 0;
                ◈ Pattern: a "b" a a c
                ◈ Substring: "ab"
                ◈ Prefixes: "a"
                ◈ Suffixes: "b"
                ◈ Result: No match. Length is 0.
                ◈ LPS: [0, 0, ?, ?, ?]

    ◉ Step 3: i = 2 ('a')
                ◈ Compair ptr[i] == ptr[length], a == a;
                ◈ They match!
                ◈ Increase length by "1", Set lps[i] to length;
                ◈ Pattern: a b "a" a c
                ◈ Substring: "aba"
                ◈ Prefixes: "a", "ab"
                ◈ Suffixes: "a", "ba"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 2, ?]

    ◉ Step 4: i = 3 ('a')
                ◈ Compair ptr[i] == ptr[length], a == b;
                ◈ They don't match. We crucial fallback step, to see whether in prev any
                    prefix/suffix is there. length = lps[length - 1] = 0
                ◈ length = lps[length - 1] = 0;
                ◈ Pattern: a b a "a" c
                ◈ Substring: "abab"
                ◈ Prefixes: "a", "ab", "aba"
                ◈ Suffixes: "a", "ab", "bab"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 1, ?]

    ◉ Step 5: i = 4 ('c')
                ◈ Compair ptr[i] == ptr[length], c == b;
                ◈ They don't match. length is already = 0, we can't go back otherwise we will.
                ◈ At there instead of making lps[4] = 0, We need to check if a shorter prefix might
                    match. We "fall back" by setting length = lps[length - 1];
                ◈ Pattern: a b a a "c"
                ◈ Substring: "abab"
                ◈ Prefixes: "a", "ab", "aba", "abaa"
                ◈ Suffixes: "c", "ac", "aac", "baac"
                ◈ Result:  The longest match is "a" (length 1).
                ◈ LPS: [0, 0, 1, 1, 0]

*/

void constructLPS(string& pat, vector<int>& lps) {
    int prevLPS = 0;
    int i = 1;

    // LPS[0] will always 0
    lps[0] = 0;

    // Constructing LPS
    while (i < pat.length()) {
        if (pat[i] == pat[prevLPS]) {
            prevLPS++;
            lps[i] = prevLPS;
            i++;
        } else {
            if (prevLPS == 0) {
                lps[i] = 0;
                i++;
            } else {
                prevLPS = lps[prevLPS - 1];
            }
        }
    }
}

void search(string& txt, string& pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);

    // Let's constructLPS
    constructLPS(pat, lps);

    // Let's perform searching
    int i = 0;
    int j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                cout << "Found pattern at: " << i - j << endl;

                j = lps[j - 1];
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    search(txt, pat);
    return 0;
}