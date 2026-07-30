#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    array<int, 6 * 6> twoDArray = {
        1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
        1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
    };

    return 0;
}
