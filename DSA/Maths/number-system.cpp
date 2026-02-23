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
|    Example for "10"                                                                                                                                                                |
|                                                                                                                                                                                    |
|                    10 / 2 = 5, Remainder = 0                                                                                                                                       |
|                    5 / 2 = 2, Remainder = 1                                                                                                                                        |
|                    2 / 2 = 1, Remainder = 0                                                                                                                                        |
|                    1 / 2 = 0, Remainder = 1                                                                                                                                        |
|                                                                                                                                                                                    |
|    🔷 To get the binary we can to get the result from bottom So it will goes like this "1010"                                                                                      |
|                                                                                                                                                                                    |
|                                                                                                                                                                                    |
| 🔶 HOW TO CONVERT BINARY TO DECIMAL                                                                                                                                                |
|                                                                                                                                                                                    |
|    Example for "10"                                                                                                                                                                |
|                                                                                                                                                                                    |
|                    1x2³ + 0x2² + 1x2¹ + 0x2⁰                                                                                                                                       |
|                     8   +  0   +  2   +  0                                                                                                                                         |
|                   = 10                                                                                                                                                             |
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
| 💠 "Remove Last Set Bit": To remove last set bit we will use "n & (n - 1)"                                                                                                         |
|                                                                                                                                                                                    |
| 💠 "Extract Last Set Bit": To extract last set bit we will use "n & (-n)", -n means two's compliment.                                                                              |
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
        int countNumSetBits(int n){
            int count = 0;

            while(n > 0){
                count++;
                n = n & (n - 1);
            }
            return count;
        }

        // CHECKING IF THE NUMBER IF POWER OF 2 OF NOT
        bool isPowerOfTwo(int n){
            return (n & (n - 1));
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
            cout << "Total number of set bits of " << 13 << " is: " << countNumSetBits(13) << endl;

            // CHECKING IF THE NUMBER IF POWER OF 2 OF NOT
            cout << "Is 16 is power of 2: " << isPowerOfTwo(16);
        }
    }

    namespace dsa_problems {
        void convertNumberToBinary(int n) {
            string binary = "";

            while(n != 0){
                binary += to_string(n % 2);
                n /= 2;
            }

            binary.reserve(); // Reversing the binary value

            for(const char b: binary){
                cout << b << " ";
            }
            cout << endl;
        }

        void findSingleElement(vector<int>& n){
            int unique = 0;

            for(const int& num: n){
                unique ^= num;
            }

            cout << "Unique Number is: " << unique << endl;
        }

        void findUniqueAndRepeated(vector<int>& n){
            int cal = 0;
            int nSize = n.size();

            for(int i = 0; i < nSize; i++){
                cal ^= n[i];
                cal ^= (i + 1);
            }

            // Extracting the rightmost set bit
            int setBit = cal & (-cal);

            // Grouping into two category
            int bucket1 = 0;
            int bucket2 = 0;

            for(int i = 0; i < nSize; i++){
                if(n[i] & setBit){
                    bucket1 ^= n[i];
                }else{
                    bucket2 ^= n[i];
                }

                if((i + 1) & setBit){
                    bucket1 ^= (i + 1);
                }else{
                    bucket2 ^= (i + 1);
                }
            }

            // Identifying missing and duplicates
            int missing = 0;
            int duplicate = 0;

            for(const int& num: n) {
                if(num == bucket1){
                    duplicate = bucket1;
                    missing = bucket2;
                }

                if(num == bucket2){
                    duplicate = bucket2;
                    missing = bucket1;
                }
            }

            cout << "Missing number is: " << missing << endl;
            cout << "Duplicate number is: " << duplicate << endl;
        }

        void findTwoUniques(vector<int>& n){
            int cal = 0;
            int nSize = n.size();

            for(int i = 0; i < nSize; i++){
                cal ^= n[i];
            }

            // Finding the differ set bit
            int setBit = cal  & (-cal);

            // Getting two unique
            int unique1 = 0;
            int unique2 = 0;

            for(const int& num: n){
                if(num & setBit){
                    unique1 ^= num;
                }else{
                    unique2 ^= num;
                }
            }

            cout << "Two unique numbers are: " << unique1 << ", " << unique2 << endl;
        }

        bool hasUniqueChar(string& str){
            int mask = 0;

            for(int i = 0; i < str.size(); i++){
                int position = str[i] - 'a';

                if(mask & (1 << position)){
                    return false;
                }

                mask |= 1 << position;
            }

            return true;
        }

        vector<vector<int>> findSubsets(vector<int>& nums){
            vector<vector<int>> subsets = {};
            int numsSize = nums.size();

            // Looping through all subset masks
            for(int mask = 0; mask < (1 << numsSize); mask++){
                subsets.push_back({});

                // Checking the set bit
                for(int j = 0; j < numsSize; j++){
                    bool hasSetBit = mask & (1 << j);

                    if(hasSetBit){
                        subsets.back().push_back(nums[j]);
                    }
                }
            }

            return subsets;
        }

        unsigned int reverseBits(unsigned int n){
            int result = 0;

            // Looping from 0 to 32 (32 bit integer will be there)
            for (int i = 0; i < 32; i++) {
                result = result << 1;
                result = result | (n & 1);
                n = n >> 1;
            }        
           
            return result;
        }

        int findOneUniquesFromThree(vector<int>& nums) {
            unsigned int result = 0;

            for(int i = 0; i < 32; i++){
                int count = 0;

                for(int n: nums){
                    if(((unsigned int)n >> i) & 1u)
                        count++;
                }


                if(count % 3){
                    result |= (1u << i);
                }
            }

            return (int)(result);
        }

        int findXORSubarray(vector<int>& nums, int k){
            int count = 0;
            map<int, int> prefix;

            prefix.insert({0, nums[0]});

            // Building prefix for all element
            for(int i = 1; i < nums.size(); i++) {
                prefix[i] = prefix[i - 1] ^ nums[i];
            }

            // Count the number of prefix
            for(int i = 0; i < nums.size(); i++){
                int currentPrefix = prefix[i];

                if(currentPrefix ^ k == 0){
                    count++;
                }
            }
                

            return count;
        }

        // Main function
        void main() {
            vector<int> k = {4, 2, 3, 2};
            vector<int> xorSubarray = {2, 3, 1, 6, 7};
            vector<int> n = {1023, 4567, 1023, 8910, 4567};
            vector<int> sensorIds = {10, 5, 3, 10, 4, 5, 8, 4};
            vector<int> threeRepeated = {3, 3, 3, 4, 2, 2, 2};

            string str = "abdur";

            findSingleElement(n);
            convertNumberToBinary(5);
            findUniqueAndRepeated(k);
            findTwoUniques(sensorIds);

            cout << str << " has a unique numbers: " << hasUniqueChar(str) << endl;
            
            // Find all subsets
            cout << "Printing subsets: ";
            vector<int> num = {1, 2, 3};
            for(const vector<int>& subsets: findSubsets(num)){
                cout << "[ ";
                for(const int& val: subsets){
                    cout << val << " ";
                }
                cout << "]" << endl;
            }

            // Reversing bits
            cout << "Reverse bits of " << 3 << " is: " << reverseBits(3) << endl;

            // Finding one unique from three
            cout << "Finding one unique from three: " << findOneUniquesFromThree(threeRepeated)
                 << endl;

            // Count XOR Subarray
            cout << "Total XOR Subarrays are: " << findXORSubarray(xorSubarray, 6) << endl;
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