#include <bits/stdc++.h>
using namespace std;

/*
    <====================> Case Insensitive Search <======================>
    ◎ We can string "txt" and a pattern "pat", So the task is the search
    occurrence of pat in txt match also if case is insensitive.


    <====================> Example <======================>
    txt = "aBcAb"
    pat = "aB"

    ◎ Output is: [0, 3] ==> at 0 we have "aB" and at 3 we have "Ab".
*/

// Brute Force Approach o(n * m)
void bSearch(string& txt, string& pat) {
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i < n; i++) {
        // Let's search it.
        int j = 0;

        while (j < m) {
            if (tolower(txt[i + j]) != tolower(pat[j]))
                break;
            j++;
        }

        if (j == m) {
            cout << "Substring found at: " << i << endl;
        }
    }
}

// Using KMP algorithm o(n + m)
void constructLPS(string& pat, vector<int> lps) {
    int i = 1;
    int prevLPS = 0;
    int m = pat.length();

    // Always lps[0] = 0;
    lps[0] = 0;

    while (i < m) {
        // Logic to construct LPS
        if (tolower(pat[i]) == tolower(pat[prevLPS])) {
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
}

void search(string& txt, string& pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);

    constructLPS(pat, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (tolower(txt[i]) == tolower(pat[j])) {
            i++;
            j++;

            if (j == m) {
                cout << "Substring found at: " << i - j << endl;
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
    string txt = "aBcAb";
    string pat = "aB";

    // bSearch(txt, pat);
    search(txt, pat);

    return 0;
}