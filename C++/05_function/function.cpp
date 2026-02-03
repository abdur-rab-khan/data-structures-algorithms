/*
+---------------------------------------------------------------+ FUNCTION IN C++ +----------------------------------------------------------------+
|                                                                                                                                                  |
| 🟡 Function in C++ is similar to functions in other programming languages. It contains a block of code that performs a specific task and can be  |
|    called from other parts of the program.                                                                                                       |
|                                                                                                                                                  |
| 🟡 The main reason of using functions is to break down a large program into smaller, manageable, and reusable pieces of code, that makes code    |
|     more organized and easier to read, maintain, and debug. Instead of putting all logic into single block it's better to chuck the logic        |
|     into smaller functions.                                                                                                                      |
|                                                                                                                                                  |
| 🟡 Suppose we have a program that handle video processing, Instead of writing all the code in a single block, we can break it down into smaller  |
|     functions like "loadVideo()", "processFrame()", "applyFilter()", "saveVideo()" etc.                                                          |
|     Each function will handle a specific task, making the code more organized and easier to manage.                                              |
|                                                                                                                                                  |
| 🟡 In C++, We can pass functions as a arguments their are following ways to do that.                                                             |
|                                                                                                                                                  |
|        1. Using Function Pointers: "function_name(return_type (*name)(args_type, ...args_type))".                                                |
|        2. Using "std::function": "function_name(std::function<return_type(args_type, ...args_type)> name)"
|                                                                                                                                                  |
|                                                                                                                                                  |
| 🟡 It's better to build generic functions instead of overloading same functions with different names. For example:                               |
|                                                                                                                                                  |
|   void addIntegers(int a, int b);                                                                                                                |
|   void addFloats(float a, float b);                                                                                                              |
|                                                                                                                                                  |
| 🔵 Instead, we can create a single generic function using templates:                                                                             |
|                                                                                                                                                  |
|   template <typename T>                                                                                                                          |
|   T add(T a, T b);                                                                                                                               |
|                                                                                                                                                  |
+--------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                         FUNCTION ARGS AND RETURN VALUES                                                          |
+--------------------------------------------------------------------------------------------------------------------------------------------------+                                                                                                                                             |
|                                                                                                                                                  |
| 🟡 In C++, Passing an arguments to a function can be done in two ways:                                                                           |
|                                                                                                                                                  |
|   1️⃣. Pass by Value: In this method, a copy of the actual argument is passed to the function. Which means if the size of the data is large,       |
|                       passing by value can be inefficient as it involves copying the entire data.                                                |
|                                                                                                                                                  |
|   2️⃣. Pass by Reference: In this method, instead of passing a copy, We pass the reference (address) of the actual argument to the function.       | 
|                          This allows more efficient memory usage, especially for large data structures, as it avoids copying the entire data.    |
|                                                                                                                                                  |
| ⭐ Note: The concern with pass by reference is that the modification of the parameter inside the function will affect the original arguments.    |
|           to avoid this, we can use "const" keyword to make the reference read-only.                                                             |
| ⭐ Note: We care about performance, So prefer passing large data structures by reference and small data types (int, char, float) by value.       |
|                                                                                                                                                  |
| 🔵 Example:                                                                                                                                      |  
|                                                                                                                                                  |
|  void updateValue(int& refValue, int copyValue){                                                                                                 |
|      refValue = refValue + 10; // Modifies the original variable                                                                                 |
|      copyValue = copyValue + 20; // Modifies only the local copy                                                                                 |
|  }                                                                                                                                               |
|                                                                                                                                                  |
+----------------------------------------------------------------+ RETURN VALUES +-----------------------------------------------------------------+
|                                                                                                                                                  |
| 🟡 By computing the result, We have to ways to return it back to the caller by "reference" or by "value".                                        |
|                                                                                                                                                  |
| 🟡  We also have to know that after functions goes out of scope, all local variables inside it are destroyed, So we have to be careful when      |
|     returning references. So it's better to return by value unless we are returning references to "static variables" or "class members".         |
|                                                                                                                                                  |
| 🟡 Example:                                                                                                                                      |
|                                                                                                                                                  |
|    int& getStaticVariable(){                                                                                                                     |
|        static int staticVar = 100;                                                                                                               |
|        return staticVar; // Safe to return reference to static variable                                                                          |
|    }                                                                                                                                             |
|                                                                                                                                                  |
|    // BAD:                                                                                                                                       |
|    int& bad(){                                                                                                                                   |
|        int localVar = 200;                                                                                                                       |
|        return localVar; // Unsafe: returning reference to local variable which will be                                                           |
|    } // destroyed after function ends                                                                                                            | 
|                                                                                                                                                  |
+--------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                      SYNTAX                                                                      |
+--------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                  |
| return_type function_name(parameter_type paremeter_name, ...) [qualifiers] {                                                                     |
|     // function body                                                                                                                             |
|     return [return_data]                                                                                                                         |
| }                                                                                                                                                |
|                                                                                                                                                  |
+---------------------------------------------------------------------+ END +----------------------------------------------------------------------+
*/


#include <bits/stdc++.h>
using namespace std;

// MATRIX to demonstrate pass by reference and pass by value
class Matrix {
    int rows, cols;
    double* data;

    public:
        Matrix(int r, int c): rows(r), cols(c), data(new double[r * c]()) {}
        ~Matrix() {
            delete[] data;
        }
    
    // Copy constructor (expensive)
    Matrix(const Matrix& other)
        : rows(other.rows), cols(other.cols),
          data(other.data ? new double[rows*cols] : nullptr)
    {
        for (int i = 0; i < rows * cols; i++)
            data[i] = other.data[i];
    }


    // Move constructor (cheap)
    Matrix(Matrix&& other) noexcept
        : rows(other.rows), cols(other.cols), data(other.data)
    {
        other.data = nullptr;
        other.rows = other.cols = 0;
    }

    Matrix operator+(const Matrix& other) const
    {
        Matrix res(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res(i, j) = (*this)(i, j) + other(i, j);

        return res; // key line
    }


    double& operator()(int r, int c) {
        return data[r * cols + c];
    }

    const double& operator()(int r, int c) const {
        return data[r * cols + c];
    }
};

void test(vector<int>& v1, vector<int> v2){
    v1[0] = 100; // Modifies the original vector
    v2[1] = 200; // Modifies only the local copy
}

int main() {
    int x = 10;
    int& ref = x;

    printf("Address of x and ref: %p %p\n", (void*)&x, (void*)&ref, static_cast<int*>(&ref));

    // Testing function with pass by reference and pass by value
    vector<int> vec1 = {1, 2, 3};

    test(vec1, vec1);

    cout << "After function call:\n";
    cout << "vec1[0]: " << vec1[0] << "\nvec1[1]: " << vec1[1] << "\n";

    return 0;
}
