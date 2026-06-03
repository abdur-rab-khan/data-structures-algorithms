#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    unordered_map<int, int> charFreq;
    unordered_map<int, int> window;

    int found = 0;
    int leftIndex = 0;

    // Step 1. Preparing charFreq hashmap
    for (const int& n : s1) {
        charFreq[n]++;
    }

    for (int rightIndex = 0; rightIndex < s2.size(); rightIndex++) {
        char ch = s2[rightIndex];

        // Increasing window size.
        if (charFreq.count(ch)) {
            window[ch]++;
        }

        if (charFreq.count(ch) && charFreq[ch] == window[ch]) {
            found++;
        }

        // Shrinking if window goes beyond s1.size();
        while (rightIndex - leftIndex + 1 > s1.size()) {
            char leftCh = s2[leftIndex];
            if (charFreq.count(leftCh) && charFreq[leftCh] == window[leftCh]) {
                found--;
            }
            window[leftCh]--;
            leftIndex++;
        }

        if (found == charFreq.size()) {
            return true;
        }
    }

    return false;
}

int testCount = 1;
void submitForTesting(string s1, string s2, bool expected) {
    int s = checkInclusion(s1, s2);

    assert(s == expected);
    cout << "Test no. " << testCount++ << " is done" << endl;
}

int main() {
    submitForTesting("ba", "eidbaaoo", true);

    return 0;
}