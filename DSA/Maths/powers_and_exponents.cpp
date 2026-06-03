/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                 POWERS AND EXPONENTS                                                              |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Power mean how many times a number multiply by itself.                                                                                         |
|                                                                                                                                                   |
| 🔶 Example:                                                                                                                                       |
|                                                                                                                                                   |
|    => 2³  MEANS 2 x 2 x 2 = 8                                                                                                                     |
|                                                                                                                                                   |
|    2 ==> BASE                                                                                                                                     |
|    3 ==> EXPONENTS                                                                                                                                |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

namespace power_expo {
    // Brute force to find power and exponents
    void bruteForce(int b, int e){
        int ans = b;

        for(int i = 1; i < e; i++ ){
            ans = ans * b;
        }

        cout << "Power of " << b << " " << e << " is: " << ans << endl;
    }
   
    // Optimized solution
    int powerFastIt(int a, int n) {
        if(n == 0)
            return 1;

        int result = 1;

        while(n > 0){
            if(n % 2 == 1){
                result = result * a;
            }

            a = a * a;
            n /= 2;
        }

        return n < 0 ? (1 / result) : result;
    }

    int powerFastRec(int a, int n){
        if(n == 0){
            return 1;
        }

        int half = powerFastRec(a, n / 2);

        if(n % 2 == 0){
            return half * half;
        }else{
            return a * half * half;
        }
    }
    
    void main(){
        bruteForce(2, 5);
        cout << "Power of " << 2 << " " << 5 << " is: " << powerFastIt(2, 5) << endl;
        cout << "Power of " << 2 << " " << 5 << " is: " << powerFastRec(2, 5) << endl;
        cout << "Power of " << 2 << " " << 4 << " is: " << powerFastRec(2, 4) << endl;
    }
}

int main() {
    power_expo::main();
    return 0;
}