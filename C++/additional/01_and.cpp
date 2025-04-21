#include <iostream>
using namespace std;

void reference_example(int &y)
{
    y = 500;
}

void looping_arr(int *arr)
{
    cout << arr[2] << endl;
}

int &getElement(int (&arr)[5], int index)
{
    return arr[index];
}

int main()
{
    // Address of Operator
    int x = 55;
    int *ptr = &x;

    int **double_ptr = &ptr;

    **double_ptr = 555; // Actual effect on x.

    // Reference Declaration
    int y = 66;
    int &ref = y;

    cout << ref << endl; // 66 --> Bcz if refer to y.
    ref = 100;

    cout << y << endl;   // 100
    cout << ref << endl; // 100

    // Pass By Reference
    reference_example(y); // Y = 500 --> Bcz we pass reference of the variable means we pass the actual variable.

    cout << y << endl;

    // * 2 Example
    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl; // We get the address of first array element.
    looping_arr(arr);

    cout << endl
         << endl;
    // Range-based For Loop with Reference
    for (int &num : arr)
    {
        num += 5; // It will modify the original value inside the array. Bcz it is not a copy it is origin one.
    }

    cout << arr[0] << endl; // 7

    // To Prevent this we can use `const int &num`

    int nums[] = {11, 22, 33, 44, 55};

    getElement(nums, 2) = 3333;

    cout << endl
         << nums[2] << endl;
    return 0;
}