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

int main() {
    return 0;
}