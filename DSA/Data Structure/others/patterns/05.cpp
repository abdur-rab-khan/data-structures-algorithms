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

 * * * * *
 * * * *
 * * *
 * *
 *

 */

void printPattern5(int n) {
    // for (int i = n; i >= 0; i--) {
    //     for (int j = 0; j < i; j++) {
    //         cout << "*" << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern5(n);
    return 0;
}