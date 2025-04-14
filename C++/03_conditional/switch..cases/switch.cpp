#include <iostream>
using namespace std;

int main()
{
    int day;
    string week;

    cout << "Enter day:- ";
    cin >> day;

    switch (day)
    {
    case 1:
        week = "Monday";
        break;

    case 2:
        week = "Tuesday";
        break;

    case 3:
        week = "Wednesday";
        break;

    case 4:
        week = "Thurday";
        break;

    case 5:
        week = "Friday";
        break;

    case 6:
        week = "Saturday";
        break;

    case 7:
        week = "Sunday";
        break;
    }

    cout << endl
         << week << endl;
    return 0;
}