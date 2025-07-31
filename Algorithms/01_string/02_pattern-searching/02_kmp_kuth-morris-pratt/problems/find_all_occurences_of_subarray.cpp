#include <bits/stdc++.h>
using namespace std;

/*
    <====================> Find all Occurrence of Subarray in Array <======================>
    ◎ Give an Array "arr" and a SubArray "sub", The task is the search
    occurrence of "sub" in "arr".


    <====================> Example <======================>
    arr = [2, 3, 0, 3, 0, 3, 0]
    sub = [3, 0, 3, 0]

    ◎ Output is: [1, 3]
*/

// Brute force o(n * m)
void bSearch(vector<int>& arr, vector<int>& sub) {
    int n = arr.size();
    int m = sub.size();

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m) {
            if (arr[i + j] != sub[j])
                break;

            j++;
        }

        if (j == m) {
            cout << "Match found at: " << i << endl;
        }
    }
}

void constructLPS(vector<int>& sub, vector<int>& lps) {
    int i = 1;
    int prevLPS = 0;

    lps[0] = 0;

    while (i < sub.size()) {
        if (sub[i] == sub[prevLPS]) {
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

void search(vector<int>& arr, vector<int>& sub) {
    int n = arr.size();
    int m = sub.size();

    vector<int> lps(m, 0);

    constructLPS(sub, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (arr[i] == sub[j]) {
            i++;
            j++;

            if (j == m) {
                cout << "Match found at: " << i - j << endl;

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
    vector<int> arr = {2, 3, 0, 3, 0, 3, 0};
    vector<int> sub = {3, 0, 3, 0};

    // bSearch(arr, sub);
    search(arr, sub);

    return 0;
}