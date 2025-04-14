#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10, c = 50, d = 4;

    bool and_opera = (a > b) && (b < c); // False --> Both have to be True.
    bool or_opera = (a < b) || (c > d);  // True --> From both of them if single one is true then True.
    bool not_opera = !(c > d);           // False --> Condition is True. reverse the result we get False.

    cout << and_opera << endl
         << or_opera << endl
         << not_opera << endl;
    return 0;
}