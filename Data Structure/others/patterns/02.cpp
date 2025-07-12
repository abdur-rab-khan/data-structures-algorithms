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
 * *
 * * *
 * * * *
 * * * * *

 */

//  n (n + 1) / 2 + n / 2 == n² / 2 >> o(n² / 2)
void printPattern2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern2(n);
    return 0;
}