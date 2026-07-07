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

        return reverse(str.substr(1)) + str[0];
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

    void main() {
        cout << "Sum from 1 to 10 is: " << sum(10) << endl;
        cout << "Reverse of 'HELLO' is: " << reverse("HELLO") << endl;
        cout << "Factorial of 5 is: " << factorial(5) << endl;
        cout << "Fibonacci of 8 is: " << fibonacci(8) << endl;
    }
}  // namespace Recursion

int main() {
    Recursion::main();
    return 0;
}
