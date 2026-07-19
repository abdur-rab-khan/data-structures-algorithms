#ifndef INLINE_FN_H
#define INLINE_FN_H

#include <iostream>
#include <string>

/*
 * [ Learn Inline Functions ]:
 *      Why Actually "inline functions" needed, When we compile a program there
 * are two main steps you know (compilation and linking),
 *
 *    1. "Compilation Step": The compiler just copies the include files content
 * into the source file before compiling it. here the compiler won't give any
 * error.
 *
 *    2. "Linking Step": The linker tries to find the function definitions in
 * this case, without "inline keyword", there will be multiple definitions of
 * the same function, which causes an confusion to the linker which function
 * definition to use.
 *
 * 🔶 (Same Question Why we use "inline functions"):
 *          Let's see how the compiler handles "inline functions" vs regular
 * functions, it does two things:
 *
 *    1. "Compilation Step": The compiler may replace the function call with the
 * function body directly (it's just a suggestion not guaranteed)
 *
 *    2. "Linking Step": Linker allows multiple definitions of inline functions
 * because they are marked as "weak symbols" internally. Linker simply picks one
 * and discards the rest. Unlike normal functions ("strong symbols") which are
 * "strong symbols" where two definitions cause an error.
 *
 * 🔶 Example:
 *       Consider the following code:
 *
 *                                                  ```cpp
 *                                                  // "greet.cpp"
 *                                                  inline void
 * greetMe(std::string name) { std::cout << "Hello, " << name << "!" <<
 * std::endl;
 *                                                  }
 *                                                  ```
 *
 *                                                  ```cpp
 *                                                  // "main.cpp"
 *                                                  #include "greet.cpp"
 *                                                  int main() {
 *                                                      greetMe("John");
 *                                                      return 0;
 *                                                  }
 *                                                  ```
 *
 *                                                  ```cpp
 *                                                  // When it arrives to the
 * linker, the inline function is replaced with its definition
 *                                                  // "main.cpp"
 *                                                  int main() {
 *                                                      std::cout << "Hello,
 * John!" << std::endl; // 🟡 Now the compiler has the function definition to
 * work with return 0;
 *                                                  }
 *                                                  ```
 */
inline void greetMe(std::string name) {
  std::cout << "Hello, " << name << "!" << std::endl;
}

#endif
