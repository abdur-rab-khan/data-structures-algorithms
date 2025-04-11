#include <iostream>
using namespace std;

int main()
{
    // Variable Declaration
    int age = 21;
    float height = 5.8;
    double salary = 5832.888888888888;
    string name = "Abdur Rab Khan";
    char division = 'A';
    bool is_programmer = true;
    cout << name << endl
         << age << endl
         << height << endl
         << division << endl
         << is_programmer << endl;

    // We can declare Multiple Variable within single Line but should be the all value type same.
    int life_count = 21, salary_2 = 50000000, year = 2;

    // Constants --> It is used when you does not want to change the value inside the variable on declared.
    const string name_const = "Abdur Rab Khan";
    // name_const = "Abdur Rab"; ❌

    cout << name_const << endl;
    return 0;
}