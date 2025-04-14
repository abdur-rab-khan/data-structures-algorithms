#include <iostream>
using namespace std;

string get_fruit_color(int num)
{
    if (num != 1 && num != 2)
    {
        return "";
    }

    return num == 1 ? "Apple" : "Banana";
}

// ternary operator is best when you want to check only IF, ELSE
int main()
{
    int value;

    cout << "Choose between 1 and 2:- " << endl;
    cin >> value;

    cout << "Fruit is:- " << get_fruit_color(value) << endl;
    return 0;
}