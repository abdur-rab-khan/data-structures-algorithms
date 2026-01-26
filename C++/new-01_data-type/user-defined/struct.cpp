/*
+--------------------------------------------------------------------+ STRUCT IN C++ +---------------------------------------------------------------------+
|                                                                                                                                                          |
| 🟡 Structs in C++ are user-defined data types that allow grouping of variables of different types in a single unit. They are similar to classes but      |
|     they are usually used for simpler data structures.                                                                                                   |                                               
| 🟡 By default, all members of a struct are public. Structs are commonly used for simple data structures.                                                 |
|                                                                                                                                                          |
| 🟡 There are two ways to define structs in C++:                                                                                                          |
|     1️⃣. Static Structs: Defined at compile time with a fixed size. --> Members are accessed directly using the dot (.) operator.                         |
|     2️⃣. Dynamic Structs: Created at runtime using pointers and dynamic memory allocation.  --> Members are accessed using the arrow (->) operator.       |
|                                                                                                                                                          |
| 🟡 There are two ways to access members from an object.                                                                                                  |                                   
|    1️⃣. Static object: dot (.)                                                                                                                            |                                             
|    2️⃣. Dynamic object: arrow (->)                                                                                                                        |
|                                                                                                                                                          |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          STRUCT                                                                          |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                          |
| struct StructName {                                                                                                                                      | 
|     dataType1 member1;                                                                                                                                   |
|     dataType2 member2;                                                                                                                                   |
|     // ... more members                                                                                                                                  |
|                                                                                                                                                          | 
|     // Constructor (optional)                                                                                                                            | 
|     StructName(parameters) {                                                                                                                             | 
|         // Initialization code --> this is used to refer to the current instance of the struct                                                           | 
|     }                                                                                                                                                    |
|                                                                                                                                                          | 
|     // Member function (optional)                                                                                                                        | 
|     returnType functionName(parameters) {                                                                                                                | 
|         // Function code                                                                                                                                 | 
|     }                                                                                                                                                    |
|                                                                                                                                                          |
|   };                                                                                                                                                     | 
| }                                                                                                                                                        |
|                                                                                                                                                          |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                           OOPS                                                                           |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                          |    
| 🟡 Structs can have constructors, member functions, and access specifiers (public, private, protected) just like classes.                                |
| 🟡 The main difference between structs and classes in C++ is the default access level: structs are public by default, while classes are private          |
|   by default.                                                                                                                                            |
|                                                                                                                                                          |
|  struct Parent {                                                                                                                                         |                                                         
|      int x; // public by default                                                                                                                         |
|  };                                                                                                                                                      |
|                                                                                                                                                          |                                                       
|  struct Child: [public, private, protected] Parent { // Inheritance                                                                                      |
|      // Child struct members                                                                                                                             |
|  };                                                                                                                                                      |
|                                                                                                                                                          |    
+-------------------------------------------------------------------------+ END +--------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

struct Colors {
    string haxCode;

    // Colors(string code) : haxCode(code) {}

    Colors(string code){
        
        // Add directly if color is in hex format
        if(code[0] == '#'){
            haxCode = code;
            return;
        }

        if(code.substr(0, 3) == "RGB"){
            int r, g, b;
            sscanf(code.c_str(), "RGB(%d, %d, %d)", &r, &g, &b);
            char buffer[8];
            sprintf(buffer, "#%02X%02X%02X", r, g, b);
            haxCode = string(buffer);
        }

        throw invalid_argument("Unsupported color format");
    }

    string toRGB() {
        int r = stoi(haxCode.substr(1, 2), nullptr, 16);
        int g = stoi(haxCode.substr(3, 2), nullptr, 16);
        int b = stoi(haxCode.substr(5, 2), nullptr, 16);

        return "RGB(" + to_string(r) + ", " + to_string(g) + ", " + to_string(b) + ")";
    }
};

int main() {
    Colors c2("RGB(34, 139, 34)"); // Static allocation --> Stack memory --> No need to delete
    Colors* c1 = new Colors("#FF5733"); // Dynamic allocation

    cout << "RGB value of " << c1->haxCode << " is: " << c1->toRGB() << endl;

    delete c1;

    return 0;
}