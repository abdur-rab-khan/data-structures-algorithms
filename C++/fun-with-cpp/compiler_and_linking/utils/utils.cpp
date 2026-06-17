#include "utils.h"

#include <iostream>

#include "../inline-fn.h"
#include "../math/math.h"

extern int globalCounter;

void x() {
    std::cout << "Here's the X" << std::endl;
    std::cout << "In x function, globalCounter is:: " << globalCounter++ << std::endl;
}

void print() {
    x();
    greetMe("Abdur Rab Khan");
    std::cout << "Adding 2 + 2 = " << add(2, 2) << std::endl;
    std::cout << "Hello world!" << std::endl;
}

void greet() {
    std::cout << "Hello, Brother" << std::endl;
}

void concat(const std::string& str1, const std::string& str2) {
    std::cout << str1 << str2 << std::endl;
}
