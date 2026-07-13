#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../../dsa_utils.h"

using std::cout;
using std::endl;
using std::string;
using std::swap;
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

    int runningSum(vector<int> arr, int left = 0, int sum = 0) {
        if (left >= static_cast<int>(arr.size())) {
            return sum;
        }
        return runningSum(arr, left + 1, sum + arr[left]);
    }

    vector<string> reverseString(vector<string> str, int left, int right) {
        if (left > right) {
            return str;
        }
        swap(str[left], str[right]);
        return reverseString(str, left + 1, right - 1);
    }

    void main() {
        cout << "Sum from 1 to 10 is: " << sum(10) << endl;
        cout << "Reverse of 'HELLO' is: " << reverse("HELLO") << endl;
        cout << "Factorial of 5 is: " << factorial(5) << endl;
        cout << "Fibonacci of 8 is: " << fibonacci(8) << endl;
        cout << "Sum of {1, 2, 3, 4, 5} is: " << runningSum({1, 2, 3, 4, 5}) << endl;

        printArrayElements(reverseString({"H", "E", "L", "L", "O"}, 0, 4));
    }
}  // namespace Recursion

int main() {
    Recursion::main();
    return 0;
}
