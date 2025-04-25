#include <iostream>
using namespace std;

enum class HTTPStatus
{
    Ok = 200,
    NotFound = 404,
    InteralError = 500,
};

enum class Color
{
    RED,
    BLUE,
    GREEN,
    YELLOW,
};

void getColorName(Color color)
{
    switch (color)
    {
    case Color::BLUE:
        cout << "Color is blue" << endl;
        break;
    case Color::RED:
        cout << "Color is blue" << endl;
        break;
    case Color::GREEN:
        cout << "Color is blue" << endl;
        break;
    case Color::YELLOW:
        cout << "Color is blue" << endl;
        break;
    }
}

int main()
{
    HTTPStatus status = HTTPStatus::Ok;
    Color color = Color::BLUE;

    if (status == HTTPStatus::Ok)
    {
        cout << "Request is successfull" << endl;
    }

    getColorName(color);

    cout << static_cast<int>(status) << endl;
    return 0;
}