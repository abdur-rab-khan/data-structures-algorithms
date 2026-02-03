#include <bits/stdc++.h>
using namespace std;

/*

 ------------- Rows

 Columns

 |
 |
 |
 |
 |

 E
 DE
 CDE
 BCDE
 ABCDE

 */

void printPattern16(int n) {
    for (int i = 0; i < n; i++) {
        // Print latter
        char startChar = 'A' + ((n - i) - 1);

        for (char j = startChar; j <= startChar + i; j++) {
            cout << j << " ";
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern16(n);
    return 0;
}