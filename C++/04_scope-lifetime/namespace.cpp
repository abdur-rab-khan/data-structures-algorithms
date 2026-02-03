/*
+-------------------------------------------------------------+ NAMESPACE IN C++ +--------------------------------------------------------------+
|                                                                                                                                               |
| 🟡 Namespace in C++ allows us to group related names (variables, functions, classes, etc.) together to avoid name conflicts and improve code  |
|     organization, especially in large projects or when using multiple libraries.                                                              |
|                                                                                                                                               |
| 🟡 Names within a namespace has directly access to other names within the same namespace without needing to qualify them with the namespace  |
|     name.                                                                                                                                     |
|                                                                                                                                               |
| 🟡 Namespace has there own scope called 'Namespace Scope'. Names declared within a namespace are accessible throughout that namespace. They   |
|   can be accessed using the namespace name as a qualifier. It can access using the 'using' directive with '<namespace_name>::<name>'.         |
|                                                                                                                                               |
| 🟡 There are many ways to access names within a namespace:                                                                                    | 
|                                                                                                                                               |
|    1️⃣. Using the 'using' directive to bring all names from a namespace into the current scope:                                               |
|         using namespace <namespace_name>;                                                                                                     |
|                                                                                                                                               |
|    2️⃣. Using the 'using' declaration to bring a specific name from a namespace into the current scope:                                        |
|        using <namespace_name>::<name>;                                                                                                        |
|                                                                                                                                               |
|    3️⃣. Using the scope resolution operator (::) to access namespace name for single use:                                                      |
|        <namespace_name>::<name>;                                                                                                              |
|                                                                                                                                               |
+-----------------------------------------------------------------------------------------------------------------------------------------------+
|                                                              EXAMPLES OF NAMESPACE                                                            |
+-----------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                               |
| 🔵 Syntax for Namespace:                                                                                                                      |
|                                                                                                                                               |
|    1️⃣. Defining a Namespace:                                                                                                                  |
|         namespace <namespace_name> {                                                                                                          |
|             // Declarations and definitions                                                                                                   |
|         }                                                                                                                                     |
|                                                                                                                                               |
|   2️⃣. Accessing Names in a Namespace:                                                                                                         |
|         using namespace <namespace_name>; // Bringing all names from the namespace into the current scope.                                    |
|         using <namespace_name>::<name>; // Bringing a specific name from the namespace into the current scope.                                |
|                                                                                                                                               |
|         <namespace_name>::<name>; // Using the scope resolution operator (::) to access a name within a namespace.                            |
|                                                                                                                                               |
|                                                                                                                                               |
+--------------------------------------------------------------------+ END +--------------------------------------------------------------------+
*/
#include <bits/stdc++.h>

namespace MyNamespace {
    int myVariable = 42;

    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }

    void MAIN(){
        // Accessing names within the same namespace directly
        std::cout << "myVariable: " << myVariable << std::endl;
        myFunction();
    }

    struct MyStruct {
        void display() {
            std::cout << "Inside MyStruct of MyNamespace" << std::endl;
        }
    };
}

int main(){
    MyNamespace::MAIN(); // Directly calling main function of MyNamespace ( bring main function for only this line )

    using MyNamespace::myFunction; // Bringing specific name from MyNamespace into current scope
    myFunction(); // Now we can call myFunction directly

    using namespace MyNamespace; // Bringing all names from MyNamespace into current scope
    std::cout << "Accessing myVariable directly: " << myVariable << std::endl;

    MyStruct obj; // Now we can use MyStruct directly
    obj.display();


    MAIN(); // Calling global MAIN function if exists

    return 0;
}