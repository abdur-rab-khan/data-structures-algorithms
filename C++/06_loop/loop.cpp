/*
+------------------------------------------------------+ LOOPING IN C++ +------------------------------------------------------+
|                                                                                                                              |
| 🟡 In C++, Loop is commonly used to execute a block of code multiple times. C++ loop is similar to other programming         |
|    languages.                                                                                                                |
|                                                                                                                              |
| 🔵 There are mainly several types of loops in C++:                                                                           |
|                                                                                                                              |
|     1. for loop                                                                                                              |
|     2. while loop                                                                                                            |
|     3. do-while loop                                                                                                         |
|     4. range-based for loop (introduced in C++11)                                                                            |
|     5. for-each loop (using standard library algorithms)                                                                     |
|                                                                                                                              |
+------------------------------------------------------------------------------------------------------------------------------+
|                                                          EXAMPLE                                                             |
+------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                              |
| 1. for loop:                                                                                                                 |
|            for(int i = 0; i < 5; i++) { cout << i << " "; } // Output: 0 1 2 3 4                                             |
|                                                                                                                              |
| 2. while loop ( commonly used for conditional based looping ):                                                               |
|            int i = 0;                                                                                                        |
|            while(i < 5) { cout << i << " "; i++; } // Output: 0 1 2 3 4                                                      |
|                                                                                                                              |
| 3. do-while loop (similar to while loop, but executes the block at least once):                                              |
|           int i = 0;                                                                                                         |
|           do { cout << i << " "; i++; } while(i < 5); // Output: 0 1 2 3 4                                                   |
|                                                                                                                              |
| 4. range-based for loop (introduced in C++11):                                                                               |
|           std::vector<int> vec = {0, 1, 2, 3, 4};                                                                            |
|           for(int num : vec) { cout << num << " "; } // Output: 0 1 2 3 4                                                    |
|                                                                                                                              |
| 5. for-each loop (using standard library algorithms):                                                                        |
|           std::vector<int> vec = {0, 1, 2, 3, 4};                                                                            |
|           std::for_each(vec.begin(), vec.end(), [](int num) { cout << num << " "; }); // Output: 0 1 2 3 4                   |
|                                                                                                                              |
|                                                                                                                              |
+-----------------------------------------------------------+ END +------------------------------------------------------------+ 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Example of for loop
    for(int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    // Output: 0 1 2 3 4

    // Example of while loop
    int j = 0;
    while(j < 5) {
        cout << j << " ";
        j++;
    }
    // Output: 0 1 2 3 4

    // Example of do-while loop
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while(k < 5);
    // Output: 0 1 2 3 4

    // Example of range-based for loop
    std::vector<int> vec = {0, 1, 2, 3, 4};
    for(int num : vec) {
        cout << num << " ";
    }
    // Output: 0 1 2 3 4

    // Example of for-each loop using standard library algorithm
    std::for_each(vec.begin(), vec.end(), [](int num) {
        cout << num << " ";
    });

    return 0;
}