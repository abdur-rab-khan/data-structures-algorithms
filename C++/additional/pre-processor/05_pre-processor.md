# Pre Processor in C++

> C++ offers variety of pre-build functions which is includes in header file. In C++, all the header files may or may not be end with `.h` extension. Unlike C where all the header file end with `.h` extension. Header file usually used to declare an interface of a module or library.

![Pre-Processors](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)

- [Pre Processor in C++](#pre-processor-in-c)
  - [Types of header file in C++](#types-of-header-file-in-c)
    - [Standard Header Files](#standard-header-files)
    - [User Defined Header File](#user-defined-header-file)
      - [How to create our own Header File?](#how-to-create-our-own-header-file)
  - [Preprocessor Directives](#preprocessor-directives)
    - [Types of Preprocessor Directives](#types-of-preprocessor-directives)
      - [Macros](#macros)
      - [File Inclusions](#file-inclusions)
      - [Conditional Completions](#conditional-completions)
      - [Other directive](#other-directive)
        - [#pragma](#pragma)
        - [#pragma Directives](#pragma-directives)

## Types of header file in C++

### Standard Header Files

> Standard Header Files that are already available in C++ compiler we just need to import them. Standard Header Files is the part of the C++ **Standard Library** and provides commonly used functionality. Basically they contain standard function, constants and classes.

| Header File | Description |
|-------------|-------------|
| `<iostream>` | It contains declarations for input and output operations using streams, such as std::cout, std::cin, and std::endl |
| `<cmath>` | It is used to perform mathematical operations like sqrt(), log2(), pow(), etc. |
| `<cstdlib>` | Declares functions involving memory allocation and system-related functions, such as malloc(), exit(), and rand() |
| `<cstring>` | It is used to perform various functionalities related to string manipulation like strlen(), strcmp(), strcpy(), size(), etc. |
| `<vector>` | It is used to work with container class for dynamic arrays (vectors) functions like begin(), end() |
| `<string>` | Provides the std::string class and functions for string manipulation |
| `<iomanip>` | It is used to access set() and setprecision() function to limit the decimal places in variables |
| `<cerrno>` | It is used to perform error handling operations like errno(), strerror(), perror(), etc. |
| `<ctime>` | It is used to perform functions related to date() and time() like setdate() and getdate(). It is also used to modify the system date and get the CPU time respectively |

### User Defined Header File

> These files are defined by the user and can be includes by **`#include " "`**. These are mainly used **encapsulate** our own function, classes, declaration, so that we can organize our code and reuse our code.

- **Example**

    ```cpp
    #include "math_utils.h"
    #include<iostream>

    using namespace std;

    int main(){
        int a = 52, b = 26;

        cout << add(a,b) << endl;
        return 0;
    }
    ```

#### How to create our own Header File?

> Instead of writing all the functions and class in single file that can be complex, instead we can write our own header file and include them in our program to use it whenever we want. It enhances the code functionality and readability. Below are the steps to create our own header files.

1. Write our own code of C++ code and save that file with **`".h"`** extension.

    ```cpp
    int  sumOfTwoNumbers(int a, int b) { return (a + b); }
    ```

2. Include your header file with **`#include " "`** in your C++ program.

    ```cpp
    #include<iostream>

    // Including custom header file
    #include "sum.h"

    int main(){
        int a = 55, b = 55;

        cout << add(a, b) << endl; 
        return 0;
    }
    ```

## Preprocessor Directives

> The Preprocessor directives are the instructions to the preprocessor for doing some tasks such as **text substitutions**, **macro expansions**, **including header file**, and many more before compiling the code. All of these **directives** starts with **`#`** symbol. One of the most commonly used preprocessor is **`#include`** to include the header files in the program.

- **List of Preprocessor Directives**

| Preprocessor Directives | Description |
|-------------------------|-------------|
| `#define` | Used to define a macro |
| `#undef` | Used to undefine a macro |
| `#include` | Used to include a file in the source code program |
| `#ifdef` | Used to include a section of code if a certain macro is defined by `#define` |
| `#ifndef` | Used to include a section of code if a certain macro is not defined by `#define` |
| `#if` | Check for the specified condition |
| `#else` | Alternate code that executes when `#if` fails |
| `#elif` | Combines else and if for another condition check |
| `#endif` | Used to mark the end of `#if`, `#ifdef`, and `#ifndef` |

### Types of Preprocessor Directives

- Mainly there are 4 types of Preprocessor directives
    1. [Macros](#macros)
    2. File inclusion
    3. Condition Compilation
    4. Other directives

#### Macros

> Macros are used to define **constants** or **create function** that are substituted by the pre-processor before the code is compiled. The two preprocessor **#defined**, **#undef** are used to created and remove macros in C. \
> Another use case is to change certain string in the code will be changed before compilation.

- where after preprocessing, the token will be expanded to its **value** in the program.

- **Example**

    ```cpp
    #include <stdio.h>

    // Macro Definition
    typedef vector<int>  vi // It used to change the certain type name with custom one.

    #define LIMIT 5
    #define PB push_back

    int main(){
        vi nums; // Equivalent to vector<int> nums;

        nums.PB(1); // Equivalent to nums.push_back(1) 
        nums.PB(2);
        nums.PB(3);
        nums.PB(4);
        
        for (int i = 0; i < LIMIT; i++) {
            printf("%d \n", i);
        }
        return 0;
    }
    ```

  - In the above program, before the compilation begins, the word **LIMIT** is replaced by **5**. The word **LIMIT** is micro definition is called a **micro template** and 5 is **micro expansion**.
  - **💀 Note:** There is no semicolon `(;)` at the end of the micro definition.
  - A macro defined previously can be undefined using #undef preprocessor.

- **Macros with Arguments**

> Macros by work as functions also by passing arguments into them.

- **Example**

    ```cpp
    #include<iostream>
    #define AREA(l, b) (l * b)
    using namespace std;

    int main(){
        cout << "Area " << AREA(10, 5) << endl; // 50
        return 0;
    }
    ```

#### File Inclusions

> File inclusions allow us to includes external files (header files, libraries) into the current program. This is typically done using **`#include`** directives, which can include both **system** and **user-defined**.

- **Syntax**
- There are two to include files
    1. `#include<fileName>`
    2. `#include "fileName"`

- Where **<** and **>** brackets tell compiler to look for a file in the **standard directives** while double quotes ("") tell compiler to look header file in the source directory.

- **Example**

    ```cpp
    // Includes the standard I/O library
    #include <iostream>  
    
    int main() {
        cout << "Hello World" << endl;
                
        return 0;
    }
    ```

#### Conditional Completions

> Conditional Completions allows us to **include** or **exclude** based on certain conditions. The is useful for creating platform-specific code or for debugging. There are the following conditional preprocessor directives: **#if**, **#ifdef**, **#ifndef**, **else**, **#elif** and **#endif**

- **endif** directive is used to close off **if**, **ifdef** and **ifndef** opening directive.

- **Example**

    ```cpp
    #include <stdio.h>

    // Defining a macro for PI
    #define PI 3.14159
    
    int main(){
    
    // Check if PI is defined using #ifdef
    #ifdef PI
        printf("PI is defined\n");
    
    // If PI is not defined, check if SQUARE is defined
    #elif defined(SQUARE)
        printf("Square is defined\n");
    
    // If neither PI nor SQUARE is defined, trigger an error
    #else
        #error "Neither PI nor SQUARE is defined"
    #endif
    
    // Check if SQUARE is not defined using #ifndef
    #ifndef SQUARE
        printf("Square is not defined");
    
    // If SQUARE is defined, print that it is defined
    #else
        printf("Square is defined");
    #endif
    
        return 0;
    }
    ```

  - **Output**

    ```shell
    PI is defined
    Square is not defined
    ```

#### Other directive

> Apart from primary preprocessor directive, C also provides other directives to manage compiler behavior and debugging.

##### #pragma

> Provides specify instruction to control its behaviors. It is used to disable warning, set alignments etc.

- **Syntax**

    ```cpp
    #pragma directive
    ```

##### #pragma Directives

| Directive | Purpose | Supported Compilers | Notes |
|-----------|---------|---------------------|-------|
| `#pragma once` | Prevents multiple inclusions of a header | All major compilers | Modern alternative to include guards |
| `#pragma pack(n)` | Sets structure alignment to `n` bytes | GCC, MSVC, Clang | Controls padding/alignment |
| `#pragma pack(push, n)` / `#pragma pack(pop)` | Saves/restores alignment | GCC, MSVC, Clang | Used for nested alignment changes |
| `#pragma warning(disable:4996)` | Suppress specific warnings | MSVC | `4996` disables "deprecated function" warning |
| `#pragma warning(push)` / `#pragma warning(pop)` | Save/restore warning state | MSVC | Allows scoped suppression |
| `#pragma GCC diagnostic ignored "-Wwarning"` | Disable specific GCC/Clang warnings | GCC, Clang | Replace `-Wwarning` with real flag (e.g. `-Wunused`) |
| `#pragma GCC diagnostic push/pop` | Save/restore warning state | GCC, Clang | Like MSVC's push/pop |
| `#pragma message("text")` | Outputs a message during compilation | All | Good for debug reminders |
| `#pragma region` / `#pragma endregion` | Enables code folding in IDEs | MSVC, some IDEs | No effect on compiler behavior |
| `#pragma optimize("g", on)` | Controls compiler optimizations | MSVC | `"g"` is one of several options |
