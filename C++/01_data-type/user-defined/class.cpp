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

class IStack {
   public:
    // virtual IStack(int size) = 0; ❌ Wrong because, IStack  is called with object is created but for "ABSTRACT CLASS" no object will created.
    // 1️⃣. Member function can be a virtual function
    // 2️⃣. Destructure can be a virtual
    // 3️⃣. Constructor ❌
    // 4️⃣. Member variables ❌

    // 👉 To understand why, Because abstract class is for creating a blueprint, like what member function will be there. There we only add things which are required in the main class.

    virtual ~IStack() = 0;

    // 👉 "Virtual: " Actually "virtual" keyword in C++, that tell C++ compiler don't decide that will run instead decide on run time.
    virtual void push(int n) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
    // 👉 Enforce "= 0", We should have to implement this on "main" class, but it's not a case with "DESTRUCTURE" because even if you aren't define, C++ compiler will automatically create this.
    // 👉 Which is bad sometimes, Like suppose we are creating dynamic object, 100% will going to need a ""DESTRUCTURE"" for cleaning things.
};

IStack::~IStack() = default;  // 👉 It's very important to have.

class Vector {
   private:
    double* elem;
    int sz;

   public:
    Vector(int s) : elem {new double[s]}, sz {s} {}
    double& operator[](int i) {
        return elem[i];
    }  // subscript operator --> means we can access like this --> v[0], v[1]
    int size() { return sz; }
};

int main() {
    Vector v(5);

    for (int i = 0; i < v.size(); i++) {
        v[i] = i * 2;  // using subscript operator
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";  // using subscript operator
    }

    return 0;
}