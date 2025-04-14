## Bitwise Operators

* ### Bitwise Operators in C++
    * Bitwise operators operate on bits and perform bit-by-bit operations.

* ### Bitwise AND Operator (`&`)
    * Performs a Boolean AND operation on each pair of corresponding bits.
    * Returns 1 if both bits are 1, otherwise returns 0.
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = 3;  // 011 in binary
        int c = a & b;  // 001 in binary = 1 in decimal

        /*

        101
        011

        1 & 0 = 0
        0 & 1 = 0
        1 & 1 = 1

        Answer = 001 = 1

        */
        ```

* ### Bitwise OR Operator (`|`)
    * Performs a Boolean OR operation on each pair of corresponding bits.
    * Returns 1 if at least one of the bits is 1, otherwise returns 0.
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = 3;  // 011 in binary
        int c = a | b;  // 111 in binary = 7 in decimal

        /*

        101
        011

        1 | 0 = 1
        0 | 1 = 1
        1 | 1 = 1

        111 = 7
        
        */
        ```

* ### Bitwise XOR Operator (`^`)
    * Performs a Boolean XOR operation on each pair of corresponding bits.
    * Returns 1 if the bits are different, otherwise returns 0.
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = 3;  // 011 in binary
        int c = a ^ b;  // 110 in binary = 6 in decimal


        /*
            101 = 5
            011 = 3

            1 ^ 0 = 1
            0 ^ 1 = 1
            1 ^ 1 = 0
        */
        ```


* ### Bitwise NOT Operator (`~`)
    * Flips all the bits (0 becomes 1, 1 becomes 0).
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = ~a;  // 11111111111111111111111111111010 (assuming 32-bit integer)
        ```

* ### Left Shift (`<<`)
    * Shifts the bits to the left by specified number of positions.
    * Each shift left multiplies the number by 2.
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = a << 1;  // 1010 in binary = 10 in decimal
        ```

* ### Right Shift (`>>`)
    * Shifts the bits to the right by specified number of positions.
    * Each shift right divides the number by 2.
    * Example:
        ```cpp
        int a = 5;  // 101 in binary
        int b = a >> 1;  // 10 in binary = 2 in decimal
        ```