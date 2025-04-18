#include <iostream>
using namespace std;

void allocate(int** ptr) {
    *ptr = new int;  // Allocates memory for an integer and stores the address in the pointer
    **ptr = 42;      // Dereferences twice to store the value 45 in the allocated memory
}

int main() {
    // Modify pointer inside function.
    int* p = nullptr;
    allocate(&p);
    cout << *p << endl;

    void* ptr = nullptr;
    void** doublePointer = &ptr;  // Address of ptr

    cout << "Initial ptr (nullptr): " << *doublePointer
         << endl;  // Getting the value inside ptr. --> 0

    *doublePointer = new int;
    *(static_cast<int*>(*doublePointer)) = 50;

    cout << "Value at int ptr: " << *(static_cast<int*>(ptr)) << endl;

    delete static_cast<int*>(ptr);  // Free the memory to prevent memory leak

    *doublePointer = new float;
    *((float*)ptr) = 50.50;

    cout << "Value at float ptr: " << *(static_cast<float*>(ptr)) << endl;

    delete static_cast<float*>(ptr);  // Clean up

    int** num = new int*;

    *num = new int;
    **num = 99;

    cout << **num << endl;

    delete num;

    // Draw Matrix
    int row = 3;
    int col = 3;

    // Allocate the memory location
    int* matrix = new int[row];
    int** matrix_ptr = &matrix;

    // Initialize memory location for row
    for (int i = 0; i < row; i++) {
        matrix_ptr[i] = new int[col];
    }

    // Initialize memory location for cols
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_ptr[i][j] = (i + 1) * (j + 1);
        }
    }

    // Print all value
    for (int i = 0; i < row; i++) {
        cout << "[ ";
        for (int j = 0; j < col; j++) {
            cout << matrix_ptr[i][j] << " ";
        }
        cout << " ]" << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < row; i++) {
        delete[] matrix_ptr[i];  // delete each row
    }
    delete[] matrix;  // delete the array of pointers

    return 0;
}