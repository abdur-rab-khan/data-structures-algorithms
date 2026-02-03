/*
+-----------------------------------------------------+ TYPE CASTING IN C++ +---------------------------------------------------+
|                                                                                                                               |
| 🟡 In C++ or any other programming language, Type Casting is a ways to convert one data type to another datatype. It could be |
|    done using implicitly (automatically), explicitly (manually).                                                              |
|                                                                                                                               |
| 🔵 Implicitly (Automatically by Compiler)                                                                                     |
|                                                                                                                               |
|    - Here compiler automatically convert from one datatype to another.                                                        |
|    - Here compiler decide the conversion.                                                                                     |
|    - Example: "int a = 10; double b = 10; ---> (automatically convert from int to double)"                                    |
|                                                                                                                               |
|                                                                                                                               |
| 🔵 Explicitly (Manually by developer)                                                                                         |
|                                                                                                                               |
|    - Here developer manually convert from datatype to another.                                                                |
|                                                                                                                               |
|  🔴 Their are ways to do that:                                                                                                |
|                                                                                                                               |
|    1. "C-Style Casting": "(type)value"                                                                                        |
|       - Example: float x = 5.9; int y = (int)x; // ---> x (float) will be converted into "int"                                |
|                                                                                                                               |
|    2. "static_cast": "static_cast<int>(x)"                                                                                    |
|       - It's more safer than previous "C-Style Casting".                                                                      |
|       - Example: float x = 5.9; int y = static_cast<int>(x); // ---> x (float) will be converted into "int"                   |
|                                                                                                                               |
+-------------------------------------------------------------+ END +-----------------------------------------------------------+
*/
#include <iostream>


int main () {
  // Automatically by compiler
  float x = 5.9;
  int y = x;

  std::cout << "X=" << x << "\nY=" << y << std::endl;

  // Explicit type conversion
  float x1 = 5.9;
  float y1 = static_cast<int>(x1);

  std::cout << "X1=" << x1 << "\nY1=" << y1 << std::endl;

  return 0;
}
