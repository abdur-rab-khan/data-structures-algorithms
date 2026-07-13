/*
+--------------------------------------------------------------------+ STRUCT IN C++ +---------------------------------------------------------------------+
|                                                                                                                                                          |
| 🟡 Structs in C++ are user-defined data types that allow grouping of variables of different types in a single unit. They are similar to classes but      |
|     they are usually used for simpler data structures.                                                                                                   |
| 🟡 By default, all members of a struct are public. Structs are commonly used for simple data structures.                                                 |
|                                                                                                                                                          |
| 🟡 There are two ways to define structs in C++:                                                                                                          |
|     1️⃣. Static Structs: Defined at compile time with a fixed size. --> Members are accessed directly using the dot (.) operator.                          |
|     2️⃣. Dynamic Structs: Created at runtime using pointers and dynamic memory allocation.  --> Members are accessed using the arrow (->) operator.        |
|                                                                                                                                                          |
| 🟡 There are two ways to access members from an object.                                                                                                  |
|    1️⃣. Static object: dot (.): used when you have a regular object.                                                                                       |
|    2️⃣. Dynamic object: arrow (->): used when you have a pointer to an object.                                                                             |
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

    //  1. STRUCT CONSTRUCTOR
    // Colors(string code) : haxCode(code) {}
    explicit Colors(const string& code) {
        // Add directly if color is in hex format
        if (code[0] == '#') {
            haxCode = code;
            return;
        }

        if (code.substr(0, 3) == "RGB") {
            int r, g, b;
            sscanf(code.c_str(), "RGB(%d, %d, %d)", &r, &g, &b);
            char buffer[8];
            sprintf(buffer, "#%02X%02X%02X", r, g, b);
            haxCode = string(buffer);
        }

        throw invalid_argument("Unsupported color format");
    }

    string toRGB() const {
        const int r = stoi(haxCode.substr(1, 2), nullptr, 16);
        const int g = stoi(haxCode.substr(3, 2), nullptr, 16);
        const int b = stoi(haxCode.substr(5, 2), nullptr, 16);

        return "RGB(" + to_string(r) + ", " + to_string(g) + ", " + to_string(b) + ")";
    }
};

struct Student {
    string name;
    int    age;
    string address;
    // Student(const string name, const int age, const string address)
    //     : name(name), age(age), address(address) {
    //     cout << "Constructor is called" << endl;
    // }
    void print() const {
        cout << "Student name is: " << name << endl;
        cout << "Student age is: " << age << endl;
        cout << "Student address is: " << address << endl;
    }
};

int main() {
    // Static allocation and store on Stack, and automatically got remove after main remove from the stack.
    Colors c2("#FF5733");

    // Dynamic allocation and store on heap memory and automatically got removed after it gone out of scope
    const auto c1 = make_unique<Colors>("#FF5733");
    cout << "RGB value of " << c1->haxCode << " is: " << c1->toRGB() << endl;

    // 🟡 Different ways, To create an object via "Struct (blue print). See struct as just a blue print for creating an object.
    // 👉 On struct it's possible to add constructor, but sometime it's not required we can initilize the value of struct in a very easy way.

    // 1. Using "{}" it's the quickest way to create an object, and we can put value based on position on struct, but in modern C++ we can directly assign value via there .names like { .name = "Khan", .age = 21};
    // 👉 The good thing about this appraoch is it won't automatically convert the type like using () C++ will automatically convert sometypes like "float" -> "int".
    const Student s1 {"Abdur Rab Khan", 21, "Indira Nagar"};
    s1.print();

    // 2. Zero initilizing: Nothing will going to pass while creating an object to it will give default value, if it's not there will be no value
    const Student s2 {};
    s2.print();

    const Student s3 {.name = "Abdur Rab Khan", .age = 21, .address = "Indira Nagar"};
    cout << "Using named initialization: " << endl;
    s3.print();

    return 0;
}
