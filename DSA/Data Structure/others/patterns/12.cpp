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

 1      1
 12    21
 123  321
 12344321

 n = 4
 [0, 6]
 [1, 4]
 [2, 2]
 [3, 0]

 */

void printPattern12(int n) {
    for (int i = 0; i < n; i++) {
        // Print left numbers;
        for (int l = 1; l <= i + 1; l++)
            cout << l;

        // Space
        for (int s1 = 0; s1 < ((n - i) - 1) * 2; s1++)
            cout << " ";

        // Print right numbers
        for (int r = i + 1; r >= 1; r--) {
            cout << r;
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern12(n);
    return 0;
}