#include <iostream>
using namespace std;

template <typename... Args>
void print(Args... args) {
    (cout << ... << args) << endl;
}

int main() {
    print(1, 2, 3);            // Prints: 123
    print("Hello", 42, 3.14);  // Prints: Hello423.14
    return 0;
}