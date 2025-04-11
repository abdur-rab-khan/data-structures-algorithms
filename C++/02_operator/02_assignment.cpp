#include <iostream>
#include <cmath>
using namespace std;

// a = assignment

int main()
{
    int a = 10, b = 10;

    // Addition a Operator
    a += 2; // --> Increase by 2 --> 12

    // Substraction a Operator
    a -= 2; // --> Decrease by 2 --> 10

    // Multiplication a Operator
    a *= 5; // --> Multiple by 5. --> 50

    // Divition a Operator
    a /= 4; // --> Divide by 4. --> 12

    // Modules a Operator
    a %= 2; // --> 	Returns the division remainder if divide by 2 --> after 12/2 => r = 0

    a = 10; // a operator

    /*
    Bitwise OR a Operator
    It will compare each bit of a with each bit of 3 and perform OR operation on it.

    1010 --> 10
    0011 --> 3

    PERFORM OR | OPERATION
    1 | 0 = 1
    0 | 0 = 0
    1 | 1 = 1
    0 | 1 = 1

    --> 1011 which is 11
    */
    a |= 3; // 11

    /*
    Bit wise AND & operation
    It will compare each bit of a with each bit of 1 and perform AND operation on it.

    1010 --> 10
    0001 --> 1

    1 & 0 --> 0
    0 & 0 --> 0
    1 & 0 --> 0
    1 & 1 --> 1

    0001 --> 1
    */
    a &= 1; // 0

    /*
    Bitwise XOR a Operator

    */
    a ^= 3;

    // Right Shift a Operator
    a >>= 3;

    //  Left Shift a Operator
    a <<= 3;
    return 0;
}