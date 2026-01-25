/*
+------------------------------------------------------------------+ POINTERS +-------------------------------------------------------------------+
|                                                                                                                                                 |
| 🟡 In C++, Pointers are special data-type that stores the "memory address" of a variable, It usage "*" to store and "*" to deference it for     |
|    retrieving  value from it, "&" is use to get the address for the variable.                                                                   |
| 🟡 C++, Provides a ways to directly reference a variable instead of store them using a pointer, "type& variable_name = ref_variable;"           | 
| 🟡 To store address of a pointer and the address of that pointer so on, we would add "**..." as level of memory address increases.              |
| 🟡 "nullptr" is represent a pointer variable that does not point to any variable address yet.                                                   | 
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                    About "&"                                                                    |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| In C++, "&" has two different meanings based on the context it is used:                                                                         |
|                                                                                                                                                 |
| 1. Address-of Operator: When used in an expression, "&" is the address-of operator, which returns the memory address of a variable.             |
|    Example:                                                                                                                                     |
|       int x = 10;                                                                                                                               |
|       int* ptr = &x; // Here, &x gives the address of variable x.                                                                               |
|                                                                                                                                                 |
| 2. Reference Declaration: When used in a variable declaration, "&" is used to declare a reference, which is an alias for another variable.      |
|    Example:                                                                                                                                     |
|       int y = 20;                                                                                                                               |
|       int& ref = y; // Here, ref is a reference to variable y.                                                                                  | 
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                  TYPE POINTERS                                                                  |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| 1. Wild Pointers                                                                                                                                |                                                                                                                                                  |
|    int* ptr; // Wild pointer, not initialized                                                                                                   |
|                                                                                                                                                 |
| 2. Null Pointer                                                                                                                                 |
|    int* ptr = nullptr; // Null pointer, points to nothing                                                                                       |
|                                                                                                                                                 |
| 3. Void Pointer                                                                                                                                 |
|    void* ptr; // Void pointer, can point to any data type --> It's helpful in generic programming, but needs type casting before dereferencing  |
|                                                                                                                                                 |
| 4. Dangling Pointer                                                                                                                             |
|    int* ptr = new int(10);                                                                                                                      |
|    delete ptr; // ptr is now a dangling pointer, as it points to a memory location that has been freed                                          |
|                                                                                                                                                 |
| 5. Double Pointer                                                                                                                               |
|    int** ptr; // Pointer to a pointer                                                                                                           |
|    int x = 10;                                                                                                                                  |
|    int* p1 = &x;                                                                                                                                |
|    int** p2 = &p1;                                                                                                                              |
|                                                                                                                                                 |
+---------------------------------------------------------------------+ END +---------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

void dynamicAllocation(int** ptr){
    *ptr = new int;
    **ptr = 42;
}

int main() {
    // Reference Example
    int b = 5;
    int& ref = b;  // Ptr stores the address of b;

    cout << b << endl;  // 5;
    cout << ref << endl;  // 5;

    ref = 55; // Because of ref directly point to b, directly update to the memory location where both ref and b points

    cout << b << endl;  // 55;
    cout << ref << endl;  // 55;

    // Double Pointer Example
    int x = 9;
    int* y = &x;
    int** z = &y;

    cout << "\nDouble Pointer Example 1\n";
    cout << x << endl;
    cout << *y << endl;
    cout << **z << endl;

    // Double Pointer in dynamic allocation
    int* ptr = nullptr;

    dynamicAllocation(&ptr);

    cout << "Value of ptr is: " << *ptr << endl;

    return 0;
}