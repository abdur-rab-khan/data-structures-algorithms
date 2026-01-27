/*
+------------------------------------------------------------------------+ ENUM IN C++ +------------------------------------------------------------------------+
|                                                                                                                                                               |
| 🟡 Enum (enumeration) in C++ is a user-defined data type that consists of a set of named integral constants, known as enumerators. It is used to assign       |
|   names to integral values, making the code more readable and maintainable.                                                                                   |
|                                                                                                                                                               |
| 🟡 Enums can be defined using the "enum" keyword. By default, the underlying type of the enumerators is "int", but you can specify a different integral       |
|     type if needed.                                                                                                                                           |
|                                                                                                                                                               |
| 🟡 C++11 introduced "enum class" (scoped enums) which provides better type safety and avoids name conflicts by scoping the enumerators within the enum type.  |
|                                                                                                                                                               |
| 🟡 Enumerators in an enum class do not implicitly convert to integers, which helps prevent accidental misuse, We can specify custom value on it.              |
|                                                                                                                                                               |
| 🟡 The only different between enum and enum class is that enum class provides better type safety and scoping, while enum is more permissive but can lead to   |
|    name conflicts.                                                                                                                                            |
|                                                                                                                                                               |
+----------------------------------------------------------------------------+ END +----------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

enum class HTTPStatus { Ok = 200, NotFound = 404, InternalError = 500 };
enum Color { red, blue };

int main() {
    HTTPStatus status = HTTPStatus::Ok;

    if(status == HTTPStatus::Ok){
        cout << "Status is OK" << endl;
    }else{
        cout << "Error found" << endl;
    }

    cout << "Code is: " << static_cast<int>(status) << endl;

    // Color enum
    Color col = red;

    cout << col << endl;

    return 0;
}