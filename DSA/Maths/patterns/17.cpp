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



 */

void printPattern16(int n) {
    // Upper Symetric
    for (int i = 0; i < n; i++) {
        // Left Stars
        for (int l = 0; l < n - i; l++) {
            
        }

        // Space

        // Right Stars
        for (int r = 0; r < n - i; r++) {
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern16(n);
    return 0;
}