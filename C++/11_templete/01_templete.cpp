#include <iostream>
#include <typeinfo>
using namespace std;

// Function Template
template <typename T>
T add(T a, T b) {
    cout << endl << "The type of " << "a " << typeid(a).name() << " b " << typeid(b).name() << endl;
    return a + b;
};

template <size_t N>
void printAnArray(int (*arr)[N]) {
    cout << "Array element are ";
    for (int i = 0; i < N; i++) {
        cout << (*arr)[i] << " ";
    }
    cout << endl;
}

template <typename N>
N myMax(N a, N b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Add two int " << add(5, 5) << endl;
    cout << "Add two float " << add(1.5, 1.5) << endl;
    cout << "Add two strings " << add(string("Abdur Rab "), string("Khan")) << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    printAnArray(&arr);

    // Get Max Value
    cout << "Max value from int " << myMax(5, 10) << endl;
    cout << "Max value from float " << myMax(5.2, 2.5) << endl;
    cout << "Max value from char " << myMax('a', 'z') << endl;
    return 0;
}