#include <bits/stdc++.h>

using namespace std;

int main() {
    // Declaring String using C-Style.
    char myName[] = "Abdur Rab Khan";

    // Declaring String using std::string class.
    string my_name = "Abdur Rab Khan";

    printf("Using C-Style %s \n", myName);

    cout << "Using C++ Style " << my_name << "\n";

    // Strings are immutable in C++
    const char* name = "Abdur";

    // name[0] = 'B'; // ❌ You can't manipulate the string literal, It is immutable

    cout << name << endl;

    string firstName = "Abdul";

    firstName[firstName.length() - 1] = 'r';

    cout << firstName << endl;  // ✔️ It is possible to manipulate std::string.
    return 0;
}