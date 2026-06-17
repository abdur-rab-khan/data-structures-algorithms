#include <iostream>
#include <string>

// Including every header file
#include "math/math.h"
#include "utils/utils.h"

/*
 * [ Learn C++ Code Compile ]:
 *                             Steps to compile C++ code into ".exe" file:
 *                                  1. Preprocessing:
 *                                                   At this stage, the preprocessor is responsible for following tasks:
 *                                                      - Expanding macros (replacing macro names with their definitions)
 *                                                               - Example: `#define PI 3.14` will be replaced with `3.14` in the code
 *                                                      - Including header files
 *                                                               - Example: `#include <iostream>` will include the standard input/output stream library, just copy the header file to your project
 *                                                      - Removing comments
 *                                                               - Example: `// This is a comment` will be removed from the code
 *                                  2. Compilation
 *                                                   At this stage, the compiler takes the preprocessed code and compiles it into an intermediate representation (IR), often called as the object code.
 *                                                   The object code is then passed to the linker to resolve external references and create the final executable.
 *                                  3. Linking
 *                                                   The linkers job is to merge multiple ".o" files into a single executable file, by resolving the function definitions for the external references.
 *                                                   There are few rules that the linker follows to resolve external references:
 *                                                      1. "One definition rules": Mean that there should be only one definition for a single function in the entire program.
 */

/*
 * [ Learn Header/Include ]:
 *                          After compiling the above code will be replaced with the actual function definition
 *
 *                          "math/math.h"
 *                          ```cpp
 *                          int add(int a, int b);
 *                          int subtract(int a, int b);
 *                          int multiply(int a, int b);
 *                          int divide(int a, int b);
 *                          ```
 *
 *                          "utils/utils.h"
 *                          ```cpp
 *                              void log(std::string message);
 *                          ```
 *
 *                         Rule 2:  Every promise must be fulfilled Declaration exists but no definition anywhere → undefined reference error.
 *                         Rule 3:  static functions are invisible to linker Only that file can use them.
 *                         Rule 4:  Libraries come last in compile command g++ main.o math_utils.o -lm ✅
 *
 *
 * 🟡 By this, the compiler knows the function signatures that's why it won't give any error, and this function will replace with the actual function before creating ".exe" file.
 */

int globalCounter = 0;

void log(std::string message);

int main() {
    print();

    log("Hello from main!");

    int result = add(5, 3);
    std::cout << "Result: " << result << std::endl;

    int result2 = subtract(5, 3);
    std::cout << "Result2: " << result2 << std::endl;

    int result3 = multiply(5, 3);
    std::cout << "Result3: " << result3 << std::endl;

    int result4 = divide(5, 3);
    std::cout << "Result4: " << result4 << std::endl;

    return 0;
}
