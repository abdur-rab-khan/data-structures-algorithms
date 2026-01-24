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
 A B
 A B C
 A B C D
 A B C D E

 */

void printPattern14(int n) {
    for (int i = 0; i < n; i++) {
        // Print latters
        for (char j = 'A'; j <= 'A' + i; j++) {
            cout << j << " ";
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern14(n);
    return 0;
}