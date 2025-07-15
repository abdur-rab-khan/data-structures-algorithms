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

 1
 2 3
 4 5 6
 7 8 9 10
 11 12 13 14

 */

void printPattern13(int n) {
    int count = 1;

    for (int i = 0; i < n; i++) {
        // Print count numbers
        for (int j = 0; j <= i; j++) {
            cout << count << " ";
            count++;
        }
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern13(n);
    return 0;
}