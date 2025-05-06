#include <iostream>

#include "math.hpp"
#define LIMIT 5

using namespace std;

int Math::add(int a, int b) {
    return a + b;
}

int main() {
    Math m1;

    cout << LIMIT << endl;
    cout << "add(3, 4) " << m1.add(5, 5) << endl;
    return 0;
}