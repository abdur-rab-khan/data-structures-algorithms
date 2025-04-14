#include <iostream>
using namespace std;

// These comparsion operation always return bool (1,0), either TRUE 1 or FALSE 0.

int main()
{
    int x = 5, y = 10;

    bool is_equ = x == y;     // False
    bool is_not_equ = x != y; // True
    bool is_greater = y > x;  // True
    bool is_smaller = y < x;  // False

    cout << is_equ << endl
         << is_not_equ << endl
         << is_greater << endl
         << is_smaller << endl;

    x = 5, y = 5;

    bool is_greater_equ = x >= y; // True
    bool is_smaller_equ = x <= y; // True

    cout << is_greater_equ << endl
         << is_smaller_equ << endl;

    return 0;
}