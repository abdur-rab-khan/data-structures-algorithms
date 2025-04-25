#include <iostream>
using namespace std;

enum Color
{
    RED,
    GREEN,
    BLUE,
};

int main()
{
    Color color = RED;

    cout << color << endl;

    cout << (color == RED) << endl;
    return 0;
}