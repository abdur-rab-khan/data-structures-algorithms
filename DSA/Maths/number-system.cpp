/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                     NUMBER SYSTEM                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                    |
| 🟡 Numbers in Computer are presented by binary bits using "0" and "1", their are some operator provide by programming language to perform operation efficiently which is called    |
|     bit manipulation.                                                                                                                                                              |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                     ABOUT BINARY                                                                                   |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                    |
| 🔶 HOW TO CONVERT DECIMAL TO BINARY                                                                                                                                                |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
| 🔶 HOW TO CONVERT BINARY TO DECIMAL                                                                                                                                                |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
| 🔷 HOW TO CHOOSE NUMBER OF BITS                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                 IMPORTANT CONCEPTS                                                                                 |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                    |
| 💠 "SET BITS": Number of "1" in an binary number are "set bits".                                                                                                                   |
|                                                                                                                                                                                    |
| 💠 "POWER OF 2": Power of 2 always have only "1" in the binary.                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                       KEY RULES                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                    |
| ⭐ "AND (&)":                                                                                                                                                                      |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|           &  1 = 0001                                                                                                                                                              |
|                  0001     ==> If corresponding bit are (1 & 1) then it will "1" otherwise "0"                                                                                      |
|                                                                                                                                                                                    |
| ⭐ "OR (|)":                                                                                                                                                                       |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|           |  1 = 0001                                                                                                                                                              |
|                  0101     ==> If one of the corresponding bit "1" then it will "1" otherwise "0"                                                                                   |
|                                                                                                                                                                                    |
| ⭐ "NOT (~)":                                                                                                                                                                      |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|              ~   1011     ==> Flip all the bits, If it's 0 "flip to 1", 1 "flip to 0"                                                                                              |
|                                                                                                                                                                                    |
| ⭐ "XOR (^)":                                                                                                                                                                      |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|           ^  1 = 0001                                                                                                                                                              |
|                  0101     ==> If corresponding bits are same then "0" otherwise "1".                                                                                               |
|                                                                                                                                                                                    |
|     🔵 Popular use cases are: "Swapping without temps", "Finding missing numbers"                                                                                                  |
|                                                                                                                                                                                    |
| ⭐ "LEFT-SHIFT (<<)": Shift bits to left                                                                                                                                           |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|          <<  1                                                                                                                                                                     |
|              8 = 1000     ==> Used to multiply by power of 2.     a << n = a x 2^n                                                                                                 |
|                                                                                                                                                                                    |
| ⭐ "RIGHT-SHIFT (>>)": Shift bits to right                                                                                                                                         |
|                                                                                                                                                                                    |
|              4 = 0100                                                                                                                                                              |
|          >>  1                                                                                                                                                                     |
|              8 = 1000     ==> Used to divide by power of 2.     a << n = a / 2^n                                                                                                   |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

// Problems solve using bitwise
namespace problems {
    // Basic problems
    namespace basic {
        // EASY PROBLEMS
        void isEvenOdd(int n){
            if(n & 1){
                cout << n << " is odd" << endl;
            }else {
                cout << n << " is even" << endl;
            }
        }

        // GETTING LAST BIT
        void getLastBit(int n){
            if(n & 1) {
                cout << "Last bit is " << 1;
            }else {
                cout << "Last bit is " << 0;
            }
        }

        // CHECKING K-TH BIT IS SET OR NOT
        void checkBitSet(int n, int k) {
            if((n & (1 << (k - 1))) == 0){
                cout << k << "th" << " bit is not set" << endl;
            }else{
                cout << k << "th" << " bit is set" << endl;
            }
        }

        // TOGGLING K-TH BIT TO SET 
        void toggleSet(int n , int k){
            int toggledN = n | (1 << k - 1);
            cout << "Toggle " << k << "th" << " bit to set " << toggledN << endl;
        }

        // FLIPPING K-TH BIT
        void flippingBit(int n, int k){
            int flippedN = n ^ (1 << k - 1);
            cout << "Flipped " << n << " is: " << flippedN << endl;
        }

        // COUNTING NUMBER OF SET BITS - In Binary decimal number are sum of power of 2 So (13 = 2³ + 2² + 2⁰ = 13 So in binary there wil be "3 set bits")
        void countSetBits(int n){
            int count = 0;

            while(n > 0){
                count++;
                n = n & (n - 1);
            }

            cout << "Total number of set bits are: " << count << endl;
        }

        // CHECKING IF THE NUMBER IF POWER OF 2 OF NOT
        void checkIfPowerOfTwo(int n){
            bool isPowerOfTwo = n & (n - 1);
            cout << "Number " << n << " is Power of 2" << endl;
        }

        // Main function
        void main() {
            // EVEN ODD
            isEvenOdd(4);
            isEvenOdd(3);

            // GETTING LAST BIT
            getLastBit(1);
            getLastBit(2);

            // CHECKING K-TH BIT IS SET OR NOT
            checkBitSet(5, 1);
            checkBitSet(5, 2);

            // TOGGLING K-TH BIT TO SET
            toggleSet(5, 2);

            // FLIPPING K-TH BIT
            flippingBit(5, 1);

            // COUNTING NUMBER OF SET BITS
            countSetBits(13);

            // CHECKING IF THE NUMBER IF POWER OF 2 OF NOT
            checkIfPowerOfTwo(16);
        }
    }

    namespace dsa_problems {
        // HARD PROBLEMS

        // Main function
        void main() {
            // HARD PROBLEMS
        }
    }

    // Main function
    void main() {
        basic::main();
        dsa_problems::main();
    }
}


int main() {
    problems::main();
    return 0;
}