#include "lib.h"

#include <iostream>

#include "../inline-fn.h"

/*
 * [ Learn Static Keyword ]:
 *                           As we know, we already have "add" function inside "math/math.h", it will successfully compile but when it came to the linker, the linker will found that we already have this
 *                           function inside "math/math.h", now it will throw an error, because linker will confuse which "add" function do I need to pick.
 *
 * 🟡 "Static keyword": Now we use static keyword that will tell the linker to use the "add" function in "lib.cpp" instead of the "add" function in "math/math.h".
 */
static int add(int a, int b) {
    return a + b;
}

void init() {
    std::cout << "10000 + 10000 is: " << add(10000, 10000) << std::endl;
    std::cout << "Initializing library...\n";
    greetMe("King KONG!!!");
}

void cleanup() {
    std::cout << "Cleaning up library...\n";
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
