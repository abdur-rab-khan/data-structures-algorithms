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
| 💠 "POWER OF 2": Power of 2 will always have only "1" in the binary.                                                                                                               |
|                                                                                                                                                                                    |
| 💠 "Remove Last Set Bit": To remove last set bit we will use "n & (n - 1)"                                                                                                         |
|                                                                                                                                                                                    |
| 💠 "Extract Last Set Bit": To extract last set bit we will use "n & (-n)", -n means two's compliment.                                                                              |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              BIT MANIPULATION OPERATORS                                                                            |
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
|              8 = 0010     ==> Used to divide by power of 2.     a << n = a / 2^n                                                                                                   |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                   BINARY NUMBERS                                                                                   |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                    |
| 1 = 0001                                                                                                                                                                           |
| 2 = 0010                                                                                                                                                                           |
| 3 = 0011                                                                                                                                                                           |
| 4 = 0100                                                                                                                                                                           |
| 5 = 0101                                                                                                                                                                           |
| 6 = 0110                                                                                                                                                                           |
| 7 = 0111                                                                                                                                                                           |
| 8 = 1000                                                                                                                                                                           |
| 9 = 1001                                                                                                                                                                           |
| 10 = 1010                                                                                                                                                                          |
| 11 = 1011                                                                                                                                                                          |
| 12 = 1100                                                                                                                                                                          |
| 13 = 1101                                                                                                                                                                          |
| 14 = 1110                                                                                                                                                                          |
| 15 = 1111                                                                                                                                                                          |
|                                                                                                                                                                                    |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

// Basic Problems
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
            cout << "Last bit is " << 1 << endl;
        }else {
            cout << "Last bit is " << 0 << endl;
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
    int countSetBits(int n){
        int count = 0;

        while(n > 0){
            count++;
            n = n & (n - 1);
        }
        
        return count;
    }

    // CHECKING WHETHER IT'S POWER OF 2 OR NOT
    bool isPowerOfTwo(int n){
        return (n & (n - 1));
    }

    int findMaximumXORWithConstraint(const vector<int>& numbers, int query, int limit){
        int maxXOR = 0;

        // Step 1.
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] > limit)
                continue;

            int xorValue = query ^ numbers[i];
            maxXOR = max(maxXOR, xorValue);
        }

    return maxXOR;
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
        cout << "Total number of set bits of " << 13 << " is: " << countSetBits(13) << endl;

        // CHECKING IF THE NUMBER IF POWER OF 2 OF NOT
        cout << "Is 16 is power of 2: " << isPowerOfTwo(16) << endl;
    }
}

// DSA Problems
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

    void findMissingAndRepeated(vector<int>& numbers){
        size_t size = numbers.size();
        int xOrAll = 0;

        // Step 1. Using XOR Operation We'll get "unique" and "duplicate" at end, All number will be canceled only remaining will be ("unique" ^ "duplicate").
        for (int i = 0; i < numbers.size(); i++){
            xOrAll ^= numbers[i];
            xOrAll ^= (i + 1);
        }

        // Step 2. Here we are calculating the different set bit from right side on ("unique" ^ "duplicate"), So that we can easily find it.
        int rightMostSetBit = xOrAll & (-xOrAll);

        // Step 3. Grouping: Right most set bit tells, which bit from right is different in both of them. To find "unique" and "duplicate".
        int bucket1 = 0;
        int bucket2 = 0;

        for (int i = 0; i < numbers.size(); i++){
            if(numbers[i] & rightMostSetBit){
                bucket1 ^= numbers[i];
            }else{
                bucket2 ^= numbers[i];
            } 

            if((i + 1) & rightMostSetBit){
                bucket1 ^= (i + 1);
            }else{
                bucket2 ^= (i + 1);
            }
        }

        // Step 4. Getting "missing", "duplicate" number by checking every number if num matches with "bucket1" mean number is already there in "numbers" mean it's duplicate.
        int missing = 0;
        int duplicate = 0;

        for(const int& num: numbers){
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

    void findTwoUniques(vector<int>& numbers){
        if(numbers.empty())
            return;

        size_t size = numbers.size();
        int xORCalculatedValue = 0;

        // Step 1. Performing "XOR" on the numbers so that, at the end we'll get ("unique" ^ "unique").
        for (const int& num:numbers){
            xORCalculatedValue ^= num;
        }

        // Step 2. Finding rightmost set bit, because "rightmost" set bit will tell which bit is different.
        int rightMostSetBit = xORCalculatedValue & (-xORCalculatedValue);

        // Step 3. Grouping both two "uniques" value into two variables.
        int firstUnique = 0;
        int secondUnique = 0;

        for(const int& num:numbers){
            if(num & rightMostSetBit){
                firstUnique ^= num;
            }else {
                secondUnique ^= num;
            }
        }

        cout << "Two unique numbers are: " << firstUnique << ", " << secondUnique << endl;
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

    unsigned int computeReverseBits(unsigned int number){
        unsigned int reverseBits = 0;

        for (int i = 0; i < 32; i++){
            reverseBits <<= 1;
            reverseBits |= (number & 1);
            number >>= 1;
        }

        return reverseBits;
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

    int findXORSubarray(vector<int>& nums, int k) {
        int count = 0;
        int prefixXOR = 0;

        // This map stores:
        // prefixXOR value -> how many times it appeared
        unordered_map<int, int> freq;

        // Important: prefix before array starts is 0
        freq[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            // Build running prefix XOR
            prefixXOR ^= nums[i];

            // Check if there exists a prefix such that:
            // prefixXOR ^ previousPrefix = k
            // So previousPrefix = prefixXOR ^ k
            int required = prefixXOR ^ k;

            if (freq.find(required) != freq.end()) {
                count += freq[required];
            }

            // Store current prefix
            freq[prefixXOR]++;
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
        findMissingAndRepeated(k);
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
        cout << "Reverse bits of " << 3 << " is: " << computeReverseBits(3) << endl;
        cout << "Reverse bits of " << 3221225472 << " is: " << computeReverseBits(3221225472) << endl;

        // Finding one unique from three
        cout << "Finding one unique from three: " << findOneUniquesFromThree(threeRepeated)
                << endl;

        // Count XOR Subarray
        cout << "Total XOR Subarrays are: " << findXORSubarray(xorSubarray, 6) << endl;
    }
}

int main() {
    basic::main();
    dsa_problems::main();
    return 0;
}