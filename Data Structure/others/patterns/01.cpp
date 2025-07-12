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

 >> There are four rules to print a patterns.

 Rule 1: For outer loop, used to print number of line or rows.
 Rule 2: For inner loop, used to print number of columns and connect them with rows.
 Rule 3: Print "*" or something other inside the inner loop.
 Rule 4: Observe symmetric [OPTIONAL].


 * * * *
 * * * *
 * * * *
 * * * *


 -- In the pattern what we saw.

 >> Rule 1: Outer loop run 4 times.
 >> Rule 2: Inner loop run 4 times.
 */

// o(n²)
void printPattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern1(n);

    return 0;
}