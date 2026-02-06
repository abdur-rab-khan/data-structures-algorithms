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
    ***
   *****
  *******
 *********

 0 = [4, 1, 4] => SPACE, START, SPACE
 1 = [3, 3, 3]
 2 = [2, 5, 2]
 3 = [1, 7, 1]
 4 = [0, 9, 0]

 Rule 1: There are 5 times it will run to print rows.
 Rule 2: In the inner loop there will be 3 loop run, 2 for printing spaces and 1 for printing *.
        SPACE LOOP:
            We clearly see for first time the space will run 0 to "n".
        STAR LOOP:
            So the start is print 2 * i + 1, For First time 2 * 0 + 1 = 1, For Second 2 * 1 + 1 = 3.
 */

void printPattern7(int n) {
    for (int i = 0; i < n; i++) {
        // Left Space
        for (int l = 0; l < n - i - 1; l++) {
            cout << " ";
        }

        for (int j = 0; j < (2 * i) + 1; j++) {
            cout << "*";
        }

        for (int r = 0; r < n - i - 1; r++) {
            cout << " ";
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern7(n);
    return 0;
}