#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Recursion {
    int sum(const int n) {
        if (n == 1)
            return 1;

        // On n = 4, this will go to give me the answer 4 + (3 + 2 + 1) = 4 + (6);
        return n + sum(n - 1);
    }

    string reverse(const string& str) {
        if (str.size() <= 1) {
            return str;
        }

        return string(1, str.back()) + reverse(str.substr(0, str.size() - 1));
    }

    int factorial(const int n) {
        if (n == 0)
            return 1;

        return n * factorial(n - 1);
    }

    int fibonacci(const int n) {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    void main() {}
}  // namespace Recursion

int main() {
    Recursion::main();
    return 0;
}