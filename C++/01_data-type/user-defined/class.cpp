/*
+-----------------------------------------------------------------------------+ CLASS IN C++ +------------------------------------------------------------------------------+
|                                                                                                                                                                           |   
| 🟡 Class is a user-defined data type in C++ that allows us to bundle data and function together as a single unit. It serves as a blueprint for creating objects.          | 
| 🟡 It helps to separate the data with operations on that data, providing a way to model real-world entities more effectively.                                             |
| 🟡 Classes support the principles of Object-Oriented Programming (OOP) such as encapsulation, inheritance, and polymorphism.                                              |   
| 🟡 A class can contain data members (attributes) and member functions (methods) that operate on the data.                                                                 |
|                                                                                                                                                                           |   
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                   SYNTAX                                                                                  | 
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                           |                                                   
| class ClassName {                                                                                                                                                         |
|                                                                                                                                                                           |                                                   
|   ClassName(){                                                                                                                                                            |
|       // constructor body --> called when object is created                                                                                                               |
|   }                                                                                                                                                                       |
|                                                                                                                                                                           |
|   ~ClassName(){                                                                                                                                                           |
|       // destructor body  --> called when object goes out of scope                                                                                                        |
|   }                                                                                                                                                                       |
|                                                                                                                                                                           |
|   [public, private, protected]: // --> default is private access specifier                                                                                                |
|       // data_type variable_name                                                                                                                                          |
|                                                                                                                                                                           | 
|       // member functions                                                                                                                                                 |
|       [static] return_type function_name(parameters) {                                                                                                                    |
|           // function body                                                                                                                                                |
|       }                                                                                                                                                                   |
|                                                                                                                                                                           |
|                                                                                                                                                                           |
|       virtual return_type function_name(parameters) {                                                                                                                     |
|           // function body --> can be overriden in derived class at runtime --> "return_type function_name(parameters) override"                                          |
|       }                                                                                                                                                                   |                                         
|   }                                                                                                                                                                       |
|                                                                                                                                                                           | 
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                            OPERATOR OVERLOADING                                                                           |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                           |
| 🟡 In C++, operator overloading is a technique that allows developers to redefine the behavior of operators for user-defined data types (like classes).                   |
| 🟡 There are several operators that can be overloaded, including:                                                                                                         |
|                                                                                                                                                                           | 
|  - Arithmetic Operators: +, -, *, /, %, ++, --                                                                                                                            | 
|  - Comparison Operators: ==, !=, <, >, <=, >=                                                                                                                             |
|  - Assignment Operators: =, +=, -=, *=, /=, %=                                                                                                                            |                                  
|  - Subscript Operator: []                                                                                                                                                 |
|  - Stream Insertion and Extraction Operators: <<, >>                                                                                                                      |
|  - Function Call Operator: ()                                                                                                                                             |
|  - Member Access Operators: ->, .*, ->*                                                                                                                                   | 
|                                                                                                                                                                           |
+----------------------------------------------------------------------------------+ END +----------------------------------------------------------------------------------+
*/


#include <bits/stdc++.h>
using namespace std;

class Vector {
    private:
     double* elem;
     int sz;
    
    public:
        Vector(int s): elem{new double[s]}, sz{s} {}
        double& operator[](int i) { return elem[i]; } // subscript operator --> means we can access like this --> v[0], v[1]
        int size() { return sz; }
};

int main() {
    Vector v(5);

    for (int i = 0; i < v.size(); i++) {
        v[i] = i * 2; // using subscript operator
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // using subscript operator
    }

    return 0;
}