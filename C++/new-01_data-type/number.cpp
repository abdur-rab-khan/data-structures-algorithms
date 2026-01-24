/*
+----------------------------------------------------------------------+ NUMBER IN C++ +-----------------------------------------------------------------------+
|                                                                                                                                                              |
| 🔢 Number in C++:                                                                                                                                            | 
|                                                                                                                                                              |
|    1️⃣. int: Used to store whole numbers.                                                                                                                     | 
|    2️⃣. float: Used to store floating number.                                                                                                                 |
|    3️⃣. double: Used to store floating number, more accurate than float.                                                                                      |
|    4️⃣. long long: Used to store very large whole number.                                                                                                     |
|                                                                                                                                                              |
| 🪧 Signed and UnSigned Numbers                                                                                                                               |
|                                                                                                                                                              |
|    1️⃣. signed [int, float]: Number can be positive or negative                                                                                               |
|    2️⃣. unsigned [int, float]: Number can only positive                                                                                                       |
|                                                                                                                                                              |
|                                                                                                                                                              |
+----------------------------------------------------------------------------+ END +---------------------------------------------------------------------------+
*/

#include<iostream>

int main(int argc, char const *argv[])
{
    int a = -10;
    unsigned int b = 10;

    float c = 5.5f;
    double d = 9.99;
    long long e = 123456789012345;

    std::cout << "Signed int a: " << a << std::endl;
    std::cout << "Unsigned int b: " << b << std::endl;
    std::cout << "Float c: " << c << std::endl;
    std::cout << "Double d: " << d << std::endl;
    std::cout << "Long long e: " << e << std::endl;

    int sum = 1.5 + 2.3;  // Implicit type conversion from float to int --> sum = 3;
    std::cout << "Sum of 1.5 and 2.3 as int: " << sum << std::endl;

    return 0;
}
