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

 *********
  *******
   *****
    ***
     *

 */

void printPattern8(int n) {
    for (int i = 0; i < n; i++) {
        // Left Space
        for (int l = 0; l < i; l++) {
            cout << " ";
        }

        // Star
        for (int j = 0; j < (2 * (n - i)) - 1; j++) {
            cout << "*";
        }

        // Right Space
        for (int r = 0; r < i; r++) {
            cout << " ";
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern8(n);
    return 0;
}