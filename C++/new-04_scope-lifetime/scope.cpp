/*
+---------------------------------------------------------------+ SCOPE IN C++ +---------------------------------------------------------------+
|                                                                                                                                              |
| 🟡 In C++, scope refers to the visibility and lifetime of variables and functions within different parts of a program.                       |
|                                                                                                                                              |
| 🟡 C++ has several types of scopes, including:                                                                                               |
|                                                                                                                                              |
|    1️⃣. Local Scope: A name (variable or function) declared within a block (enclosed by curly braces {}) as local to that block. It cannot be |
|                     accessed outside that block, As that scope goes out of scope, the variable is destroyed and memory is freed.             |
|                                                                                                                                              |
|    2️⃣. Class Scope: Names declared within a class are accessible to all member functions of that class. They can be accessed using the 'this'|
|                     pointer or directly within member functions. Function in a class have their own scope.                                   |
|                                                                                                                                              |
|    3️⃣. Namespace Scope: Names declared within a namespace are accessible throughout that namespace. They can be accessed using the namespace |
|                         name as a qualifier. It can access using the 'using' directive with '<namespace_name>::<name>'.                      |
|                                                                                                                                              |
|    4️⃣. Global Scope: A name not belongs to any above scopes is considered to be in the global scope. It can be accessed from any part of the |
|                       program after its declaration.                                                                                         |
|                                                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                    OTHERS                                                                    |
+----------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                              |
| 🟡 "const": A keyword used to declare variables whose values cannot be changed after initialization. It helps in preventing accidental       |
|          modifications.                                                                                                                      |
|                                                                                                                                              |
| 🟡 "constexpr": A keyword used to declare variables or functions that can be evaluated at compile-time. It ensures that the value is constant|
|              and can be used in contexts that require compile-time constants.                                                                |
|                                                                                                                                              |
| 🟡 "static": A keyword used to declare variables with static storage duration. Static variables retain their values between function         |
|             calls. In the context of classes, static members are shared among all instances of the class.                                    |
|                                                                                                                                              |
+-------------------------------------------------------------------+ END +--------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std; // This syntax is used to include all the names from the std namespace into the global scope.

constexpr int HP = 100; // 'constexpr' is used to declare a compile-time constant variable, and not changeable. Great specially for constants like health points in games.
const double PI = 3.14159; // 'const' is used to declare a variable whose value cannot be changed after initialization.


constexpr int doubleHP() {
    // We can't use variable or functions that are not resolved at compile-time here.
    return HP * 2; // Function that returns double the health points.
}

int getScore() {
    static int score = 0; // 'static' variable retains its value between function calls.
    score += 10; // Increment score by 10 each time the function is called.
    return score;
}

int main() {
    using std::cout; // This syntax is used to include only the 'cout' name from the std namespace into the current scope.
    using std::endl; // This syntax is used to include only the 'endl' name from the std namespace into the current scope.

    cout << "Scope in C++" << endl;
   
    cerr << "This is an error message." << endl; // 'cerr' is used to output error messages to the standard error stream.
   

    cout << "Health Points: " << HP << endl;
    cout << "Double Health Points: " << doubleHP() << endl;

    // Demonstrating static variable in function
    cout << "Score after first call: " << getScore() << endl; // Outputs: 10 -- Without static, it would output 10 every time.
    cout << "Score after second call: " << getScore() << endl; // Outputs: 20
    cout << "Score after third call: " << getScore() << endl; // Outputs: 30
    
    return 0;
}