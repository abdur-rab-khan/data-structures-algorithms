/*
+--------------------------------------------------------------------+ UNION IN C++ +---------------------------------------------------------------------+
|                                                                                                                                                         |
| 🟡 Union in C++ is a user-defined data type that allows storing different data types in the same memory location. It is similar to struct,              |
|     but with a key difference: in a union, all members share the same memory span, meaning only one member can hold a value at any given time.          |
|                                                                                                                                                         |
| 🟡 Unions are useful when you need to work with different data types but want to optimize memory usage, as the size of the union is determined by its   |
|     largest member.                                                                                                                                     |
|                                                                                                                                                         |
| 🟡 "variant" is a special type of union provided by C++17 that can hold one value from a set of specified types, providing type safety and easier       |
|       management.                                                                                                                                       |
|                                                                                                                                                         |
| 🟡 If already a value is stored in the union, assigning a new value to another member will overwrite the previous value.                                |
|                                                                                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          EXAMPLE                                                                        |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                         |
| union Value {                                                                                                                                           |
|     Node* p;                                                                                                                                            |
|     int i;                                                                                                                                              |
|  }                                                                                                                                                      |
|                                                                                                                                                         |
| struct Entry {                                                                                                                                          |
|     std::string key;                                                                                                                                    |
|     Value* value;                                                                                                                                       |
|     enum { INT, PTR } type;                                                                                                                             |
| };                                                                                                                                                      |
|                                                                                                                                                         |
| void processEntry(Entry* e) {                                                                                                                           |
|     if (e->type == Entry::INT) {                                                                                                                        |
|         cout << "Integer: " << e->value->i << endl;                                                                                                     |
|     } else if (e->type == Entry::PTR) {                                                                                                                 |
|         cout << "Pointer: " << e->value->p << endl;                                                                                                     |
|     }                                                                                                                                                   |
|                                                                                                                                                         |
| 🔵 We can use "variant" from C++17 for better type safety and management.                                                                               |
|                                                                                                                                                         |
| #include <variant>                                                                                                                                      |
|                                                                                                                                                         |
| struct Entry {                                                                                                                                          |
|     std::string key;                                                                                                                                    |
|     std::variant<int, Node*> value;                                                                                                                     |
| };                                                                                                                                                      |
|                                                                                                                                                         |
| void processEntry(Entry* e) {                                                                                                                           |
|     if (std::holds_alternative<int>(e->value)) {                                                                                                        |
|         cout << "Integer: " << std::get<int>(e->value) << endl;                                                                                         |
|     } else if (std::holds_alternative<Node*>(e->value)) {                                                                                               |
|         cout << "Pointer: " << std::get<Node*>(e->value) << endl;                                                                                       |
|     }                                                                                                                                                   |
|                                                                                                                                                         |
+-------------------------------------------------------------------------+ END +-------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
#include<variant>   
using namespace std;

// Define an enum
enum Type {
    INT,
    FLOAT,
    STRING
};

// Define a union
union Data {
    int i;
    float f;
    char str[20];
};

struct Entry {
    std::string key;
    Data value;
    Type type;
};

void processEntry(Entry* e){
    if(e->type == INT){
        cout << "Integer: " << e->value.i << endl;
    } else if(e->type == FLOAT){
 } else if(e->type == STRING){
        cout << "String: " << e->value.str << endl;
    }
}

// Let's use variant from C++17 for better type safety and management
struct EntryVariant {
    std::string key;
    std::variant<int, float, std::string> value;
};

void processEntryVariant(EntryVariant* e) {
    if(std::holds_alternative<int>(e->value)) {
        cout << "Integer: " << std::get<int>(e->value) << endl;
    } else if(std::holds_alternative<float>(e->value)) {
        cout << "Float: " << std::get<float>(e->value) << endl;
    } else if(std::holds_alternative<std::string>(e->value)) {
        cout << "String: " << std::get<std::string>(e->value) << endl;
    }
}

int main() {
    Entry e1;

    e1.key = "example_int";
    e1.type = INT;
    e1.value.i = 42;

    processEntry(&e1);

    EntryVariant ev1;
    ev1.key = "example_string";
    ev1.value = std::string("Hello, World!");
    processEntryVariant(&ev1);


    return 0;
}