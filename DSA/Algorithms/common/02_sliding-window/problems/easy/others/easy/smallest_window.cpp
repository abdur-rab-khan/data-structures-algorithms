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
    int n = s.size(), k = 0, i = 0, cnt = 0, min_len = INT_MAX;
    int freq[10] = {0};

    while (k < n) {
        freq[s[k] - '0']++;

        // If characters are (0, 1, 2), then increase by +1. and increase cnt by 1, if characters
        // are came first time. If cnt == 3 means we found all of these characters.
        if (freq[s[k] - '0'] == 1)
            cnt++;

        if (cnt == 3) {
            // Increase i by 1, if we got duplicate elements or value is greater than 1. reduce
            // the window size.
            while (freq[s[i] - '0'] > 1) {
                freq[s[i] - '0']--;
                i++;
            }

            min_len = min(min_len, k - i + 1);
            freq[s[i] - '0']--;
            i++;
            cnt--;
        }
        k++;
    }

    return (min_len == INT_MIN) ? -1 : min_len;
}

/*
    S = [0, 1, 2, 0, 0, 1, 2, 3], freq = [0, 0, 0];


*/

int main() {
    string t = "55636012";
    // string t = "0123564534534";

    cout << "The max length of substring is: " << smallestSubString(t) << endl;
    cout << "The max length of substring is: " << smallestSubStringSW(t) << endl;

    return 0;
}