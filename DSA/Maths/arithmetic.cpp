/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                MODULO                                                                             |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 The following steps shows how to find modulo:                                                                                                  |
|                                                                                                                                                   |
|    1. Suppose 7 / 3:                                                                                                                              |
|                                                                                                                                                   |
|             => How many whole time 3 will fit into 7 (3 * 2 = 6).                                                                                 |
|             => So to find the modulo, we can do: 7 - (3 * 2) = 7 - 6 = 1.                                                                         | 
|             => So the answer is 1.                                                                                                                | 
|                                                                                                                                                   |
|    2. Suppose 10 / 4:                                                                                                                             | 
|                                                                                                                                                   |
|             => How many whole time 4 will fit into 10 (4 * 2 = 8).                                                                                |
|             => So to find the modulo, we can do: 10 - (4 * 2) = 10 - 8 = 2.                                                                       |
|             => So the answer is 2.                                                                                                                |
|                                                                                                                                                   |
|    3. 4 % 2:                                                                                                                                      |
|             => How many whole time 2 will fit into 4 (2 * 2 = 4).                                                                                 |
|             => So to find the modulo, we can do: 4 - (2 * 2) = 4 - 4 = 0.                                                                         |
|             => So the answer is 0.                                                                                                                |
|                                                                                                                                                   |
|    4. 2 % 5:                                                                                                                                      |
|             => How many whole time 5 will fit into 2 (5 * 0 = 0).                                                                                 |
|             => So to find the modulo, we can do: 2 - (5 * 0) = 2 - 0 = 2.                                                                         |
|             => So the answer is 2.                                                                                                                |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/


#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
   // Suppose i want
   for(int i = 1; i <= 5; i++){
        int j = 1;
        
        // It will print the value of j until it is divisible by 5, and then it will stop.
        while((j % 6) != 0){
            cout << j << " ";
            j++;
        }
        cout << endl;

        sleep(1);
   }
    
    return 0;
}