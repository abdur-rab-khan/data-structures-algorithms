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

  *
  **
  ***
  ****
  *****
  ****
  ***
  **
  *

  [1, 1]
  [2, 2]
  [3, 3]
  [4, 4]
  [5, 5]
  [6, 4]
  [7, 3]
  [8, 2]
  [9, 1]

  */

void printPattern10(int n) {
    for (int i = 1; i <= (2 * n) - 1; i++) {
        int stars = i > n ? (2 * n) - i : i;

        // Print Stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern10(n);
    return 0;
}