#include <iostream>
using namespace std;

int main()
{
    int table;
    cout << "Enter the table number" << endl;

    cin >> table;

    int i = 1;

    while (i <= 10)
    {
        cout << table << " * " << i << " = " << table * i << endl;

        i++;
    }

    return 0;
}