#include <bits/stdc++.h>
using namespace std;

// Approach 1 o(m * n)
int checkSubstring(string txt, string pt) {
    int n = txt.size();
    int m = pt.size();

    // Instead of running till n we can substact with m, We know that at every index we already
    // check i + m, So no need to run till n;
    for (int i = 0; i <= n - m; i++) {
        // Check for substring match
        int j;
        for (j = 0; j < m; j++) {
            // If miss match
            if (txt[i + j] != pt[j]) {
                break;
            }
        }

        // j == m  which means that, j is running til pt.length without any break means pt is the
        // substring of txt.
        if (j == m) {
            return i;
        }
    }

    return -1;
}

// Using build-in method
int checkSubString(string txt, string pt) {
    int idx = txt.find(pt);

    if (idx != string::npos) {
        return idx;
    }

    return -1;
}

int main() {
    // Task: Given a two string txt and pt, the task is to find if pat is a substring of txt. If yes
    // return index of first occurrence otherwise return -1.
    string txt = "Abdur Khan Rab Khan";
    string pt = "Khan";

    cout << "Check " << pt << " is substring of " << txt << " : " << checkSubstring(txt, pt)
         << "\n";
    cout << "Check " << pt << " is substring of " << txt << " : " << checkSubString(txt, pt)
         << "\n";
    return 0;
}