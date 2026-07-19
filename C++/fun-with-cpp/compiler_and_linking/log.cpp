#include <iostream>
#include <string>

/*
 * [ Learn Extern ]:
 *        "extern" tells the compiler that the variable/function is defined
 * somewhere, not in this file but in another file I promise that you will get
 * from the linker
 */
extern int globalCounter;

void log(std::string message) {
  std::cout << "In log function, globalCounter is:: " << globalCounter++
            << std::endl;
  std::cout << "Log message is:: " << message << std::endl;
}
