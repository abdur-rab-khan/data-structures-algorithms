#include <iostream>
using namespace std;

struct
{
    string name;
    string model;
    int year;
    bool is_electric;

    void display()
    {
        cout << model << endl
             << year << endl
             << is_electric << endl;
    }
} c1;

int main()
{
    c1.name = "Tesla";
    c1.model = "S1";
    c1.year = 2022;
    c1.is_electric = true;

    c1.display();

    return 0;
}