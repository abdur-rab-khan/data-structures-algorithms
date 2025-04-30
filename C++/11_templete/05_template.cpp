#include <iostream>
using namespace std;

template <typename T>
void add(T a, T b) {
    T result = a + b;
    cout << "The result is " << result << endl;
}

template <>
void add<int>(int a, int b) {
    int result = a + b;
    cout << "The result of two integer is " << result << endl;
}

int main() {
    add<int>(2, 2);                             // The result of two integer is 4
    add(2.5, 2.5);                              // The result is 5
    add(string("Abdur Rab"), string(" Khan"));  // The result is Abdur Rab Khan
    return 0;
}