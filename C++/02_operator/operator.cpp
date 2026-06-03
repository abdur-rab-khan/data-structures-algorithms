/*
+------------------------------------------------------------------------+ OPERATOR IN C++ +-----------------------------------------------------------------------+
|                                                                                                                                                                  |
| 🟡 In C++, operators are special symbols or keywords that perform operations on one or more operands (variables, constants, or expressions) to produce a         |
|        new value. Operators can be classified into several categories based on their functionality.                                                              |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     TYPE OF OPERATORS IN C++                                                                     |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 🟡 C++ supports a wide range of operators, including:                                                                                                            |
|                                                                                                                                                                  |
|    1️⃣. Arithmetic Operators:   +, -, *, /, %, ++, --                                                                                                             |
|                                                                                                                                                                  |
|    2️⃣. Relational Operators:    ==, !=, >, <, >=, <=                                                                                                             |
|                                                                                                                                                                  |
|    3️⃣. Logical Operators:       &&, ||, !                                                                                                                        |
|                                                                                                                                                                  |
|    4️⃣. Bitwise Operators:        &, |, ^, ~, <<, >>                                                                                                              |
|                                                                                                                                                                  |
|    5️⃣. Assignment Operators:     =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=                                                                                     |
|                                                                                                                                                                  |
|    6️⃣. Miscellaneous Operators:   sizeof, ?: (ternary operator), , (comma operator), & (address-of operator), * (dereference operator)                           |
|                                                                                                                                                                  |
+-----------------------------------------------------------------------------+ END +------------------------------------------------------------------------------+
*/


#include <bits/stdc++.h>
using namespace std;


void arithmeticOperators(){
    int a = 10;
    int b = 5;

    // Addition
    int sum = a + b; // 15

    // Subtraction
    int diff = a - b; // 5

    // Multiplication
    int prod = a * b; // 50

    // Division
    int quot = a / b; // 2

    // Modulus
    int mod = a % b; // 0

    // Increment
    a++; // a becomes 11

    // Decrement
    b--; // b becomes 4
}

void relationalOperators(){
    int x = 10;
    int y = 20;

    // Equal to
    bool isEqual = (x == y); // false

    // Not equal to
    bool isNotEqual = (x != y); // true

    // Greater than
    bool isGreater = (x > y); // false

    // Less than
    bool isLess = (x < y); // true

    // Greater than or equal to
    bool isGreaterOrEqual = (x >= y); // false

    // Less than or equal to
    bool isLessOrEqual = (x <= y); // true
}

void logicalOperators(){
    bool p = true;
    bool q = false;

    // Logical AND
    bool andResult = p && q; // false

    // Logical OR
    bool orResult = p || q; // true

    // Logical NOT
    bool notResult = !p; // false
}

void assignmentOperators(){
    int a = 10; // Assignment

    a += 5; // a = a + 5; a becomes 15

    a -= 3; // a = a - 3; a becomes 12

    a *= 2; // a = a * 2; a becomes 24

    a /= 4; // a = a / 4; a becomes 6

    a %= 4; // a = a % 4; a becomes 2
}

void bitwiseOperators(){
    // It helps to perform bit-level operations on intergers, which can be useful in low-level programming, optimization, and certain algorithms.

    unsigned int a = 5;  // Binary: 0101
    unsigned int b = 3;  // Binary: 0011

    // Bitwise AND --> It compares each bit of two numbers "perform AND operation on corresponding bit (0 & 0 = 0, 0 & 1 = 0, 1 & 1 = 1)"
    unsigned int andResult = a & b; // Result: 0001 (1 in decimal)

    // Bitwise OR --> It compares each bit of two numbers "perform OR operation on corresponding bit (0 | 0 = 0, 0 | 1 = 1)"
    unsigned int orResult = a | b; // Result: 0111 (7 in decimal) --> 0101 | 0011 => (0|0=0, 1|0=1, 0|1=1, 1|1=1)

    // Bitwise XOR --> It compares each bit of two numbers "perform XOR operation on corresponding bit if both are same 1 if bits are different otherwise 0".
    unsigned int xorResult = a ^ b; // Result: 0110 (6 in decimal) --> 0101 ^ 0011 => (0^0=0, 1^0=1, 0^1=1, 1^1=0)

    // Bitwise NOT --> It inverts all the bits of a number, changing 0s to 1s and 1s to 0s.
    unsigned int notResult = ~a; // Result: 1010 (in 4-bit representation, this is -6 in decimal due to two's complement)

    // Left Shift --> It shifts the bits of a number to the left by a specified number of positions, filling the rightmost bits with 0s.
    unsigned int leftShiftResult = a << 1; // Result: 1010 (10 in decimal) --> 0101 << 1 => 1010

    // Right Shift --> It shifts the bits of a number to the right by a specified number of positions. For unsigned numbers, it fills the leftmost bits with 0s.
    unsigned int rightShiftResult = a >> 1; // Result: 0010 (2 in decimal) --> 0101 >> 1 => 0010)
}

int main() {

    arithmeticOperators();
    relationalOperators();
    logicalOperators();
    assignmentOperators();
    bitwiseOperators();

    return 0;
}