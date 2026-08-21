/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                MODULO                                                                             |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Like "divide" splits a number into "n" parts, "modulo (%)" is used to get the remainder—the leftover part that cannot form another full group. |
|                                                                                                                                                   |
|    🔷 Example:                                                                                                                                    |
|              🔹 Suppose we have an array of size 5, and we want to fill it using groups of 2 elements.                                            |
|              🔹 We can fit two full groups of 2 (occupying index 1, 2, 3, and 4).                                                                 |
|              🔹 We cannot fit | another group of 2, leaving exactly 1 slot empty at the end.                                                      |
|              🔹 Therefore: 5 % 2 = 1.                                                                                                             |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    // Suppose i want
    for (int i = 1; i <= 5; i++) {
        int j = 1;

        // It will print the value of j until it is divisible by 5, and then it will stop.
        while ((j % 6) != 0) {
            cout << j << " ";
            j++;
        }
        cout << endl;

        sleep(1);
    }

    return 0;
}
