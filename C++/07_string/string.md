# 🔠 String in C++
> String is a sequence of character that are used to store words and texts, In string we can store any type of data such as `string`, `number`, `symbol` in the form of text. String are provided by **<string>** header file.

## ➕ Creating String
```cpp
string variableName = "text";
```
## 🔍 Access string
> String can access using there name, and we can also get able to get the single character from the `string` using there `index`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName = "Abdur Rab ";
    string lastName;

    lastName.push_back('K');
    lastName.push_back('H');
    lastName.push_back('A');
    lastName.push_back('N');

    cout << firstName;
    cout << lastName << endl;

    // Access Element using INDEX
    cout << firstName[0] << firstName[1] << firstName[2] << firstName[3] << firstName[4] << endl;

    return 0;
}
```

## 🧑🏻 Get String From User
> To get string from user we can use `cin` and `getline()` function. The `cin` function will only get the first word, but the `getline()` function will get the whole line.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name; // only get the first word
    cout << "Your name is: " << name << endl;

    string fullName;
    cout << "Enter your full name: ";
    cin.ignore(); // ignore the previous newline character
    getline(cin, fullName); // get the whole line
    cout << "Your full name is: " << fullName << endl;

    return 0;
}
```

## Array of String
> String can also be define using `array`, and we can also use `array` to store multiple string.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstName[9]; // array of string
    string lastName[4]; // array of string
    
    // Get first name from user using cin
    for (int i = 0; i < 5; i++) {
        cout << "Enter first name: " << i + 1 << ": ";
        cin >> firstName[i];
    }

    // Get last name from user using getline
    for (int i = 0; i < 5; i++) {
        cout << "Enter last name: " << i + 1 << ": ";
        cin.ignore(); // ignore the previous newline character
        getline(cin, lastName[i]);
    } 

    // Print string
    for (int i = 0; i < 5; i++) {
        cout << "Name " << i + 1 << ": " << names[i] << endl;
    }

    return 0;
}
```

## 🔠 Tokenizing String
> Tokenizing is the process of splitting a string into smaller parts called tokens. In C++, we can use the `stringstream` class to tokenize a string.

```cpp
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str = "Hello, my name is Abdur Rab Khan";
    stringstream ss(str);
    string token;

    // Tokenize the string using space as a delimiter
    while (getline(ss, token, ' ')) {
        cout << token << endl;
    }

    return 0;
}
```


## 🔁 String Functions
> String functions are build-in function that are used to perform some tasks such as `concatenation`, `reversing`, `swapping` and more.

| Function Name | Description |
|-----------------|-------------|
| `length()` or `size()` | Returns the length of the string. |
| `append(variableName)` | Appends the string to the end of the string. |
| `insert(index, variableName)` | Inserts the string at the specified index. |
| `erase(index, length)` | Erases the string from the specified index. |
| `replace(index, length, variableName)` | Replaces the string from the specified index. |
| `variableName.find(text)` | Find the position of a substring |
| `substr(index, length)` | Returns the substring from the specified index. |
| `rfind(variableName)` | Finds the string from the end of the string. |
| `push_back(variableName)` | Pushes the character to the end of the string. |
| `pop_back()` | Pops the character from the end of the string. |
| `variableName.at(index)` | Returns the character at the specified index. |
