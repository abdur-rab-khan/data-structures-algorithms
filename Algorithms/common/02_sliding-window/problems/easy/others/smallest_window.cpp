#include <bits/stdc++.h>
using namespace std;

/*
    <===================> Smallest window containing 0, 1 and 2 <===================>

    ◎ Given a string containing only 0, 1 and 2, find the length of the smallest substring that
   contains all three characters 0, 1 and 2.

    → Example 1:
        Input: str = "012"
        Output: 3
        Explanation: The smallest substring is "012" itself.

    → Example 2:
        Input: str = "12012"
        Output: 3
        Explanation: The smallest substring is "120".

    → Example 3:
        Input: str = "22120"
        Output: 4
        Explanation: The smallest substring is "2120".

    -> Example 4:
        Input: str = "536731863620"
        Output: -1
        Explanation: There is no substring that contains 0, 1 and 2.

    ◎ If there is no such substring then return -1.
*/

// Using Brute force approach o(n), space complexity o(1).
int smallestSubString(string& s) {
    bool findZero = false, findOne = false,
         findTwo = false;  // Check whether all three are found or not.

    int zeroIdx = -1, oneIdx = -1, twoIdx = -1;  // Index of all three
    int maxLen = INT_MAX;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            zeroIdx = i;
            findZero = true;
        } else if (s[i] == '1') {
            oneIdx = i;
            findOne = true;
        } else if (s[i] == '2') {
            twoIdx = i;
            findTwo = true;
        }

        if (findZero && findOne && findTwo) {
            maxLen = min(maxLen, (max({zeroIdx, oneIdx, twoIdx}) - min({zeroIdx, oneIdx, twoIdx})));
        }
    }

    return (maxLen == INT_MAX) ? -1 : maxLen + 1;
}

// Using Sliding Window technique
int smallestSubStringSW(string& s) {
    int n = s.size(), k = 0;
    int freq[3] = {0};
}

int main() {
    string t = "01200123";

    cout << "The max length of substring is: " << smallestSubString(t) << endl;

    return 0;
}