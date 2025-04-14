#include <iostream>
using namespace std;

int main()
{
    int table;
    cout << "Enter the table number" << endl;

    cin >> table;

    for (int i = 0; i <= 10; i += 1)
    {
        cout << table << " * " << i << " = " << i * table << endl;
    }

    return 0;
}