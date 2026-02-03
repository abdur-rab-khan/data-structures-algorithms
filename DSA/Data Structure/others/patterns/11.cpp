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
 0 1
 1 0 1
 0 1 0 1
 1 0 1 0 1

 */

void printPattern11(int n) {
    for (int i = 1; i <= n; i++) {
        int startNum = i % 2 == 0 ? 0 : 1;

        for (int j = 1; j <= i; j++) {
            cout << startNum;
            startNum = 1 - startNum;
        }

        cout << "\n";
    }
}

int main() {
    int n = 0;
    cout << "Enter number: ";
    cin >> n;

    printPattern11(n);
    return 0;
}