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

     A
    ABA
   ABCBA
  ABCDCBA

  n = 4
  [3, 1, 3]
  [2, 3, 2]
  [1, 5, 1]
  [0, 7, 0]
 */

void printPattern15(int n) {
    for (int i = 0; i < n; i++) {
        // Left Space
        for (int l = 0; l < n - i - 1; l++) {
            cout << " ";
        }

        // Value
        char val = 'A' - 1;
        // Star
        for (int j = 0; j < (2 * i) + 1; j++) {
            val = j <= i ? val + 1 : val - 1;

            cout << val;
        }

        // Print new line
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern15(n);
    return 0;
}