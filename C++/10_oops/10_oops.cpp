#include <iostream>
using namespace std;

class Shape {
    int height;
    int width;
    int* x;
    int* y;

   public:
    Shape(int height, int width, int* x, int* y) {
        this->height = height;
        this->width = width;
        this->x = x;
        this->y = y;
    }

    Shape(const Shape& obj) {
        height = obj.height;
        width = obj.width;
        x = new int(*obj.x);
        y = new int(*obj.y);
    }

    void Show() {
        cout << endl << "Shape Properties " << endl;
        cout << "Height " << height << endl;
        cout << "Width " << width << endl;
        cout << "X " << *x << endl;
        cout << "Y " << *y << endl;
    }

    ~Shape() {
        delete x;
        delete y;
    }
};

int main() {
    int* x = new int(55);
    int* y = new int(555);

    Shape* s1 = new Shape(100, 300, x, y);

    cout << "Shape 1" << endl;
    s1->Show();

    Shape* s2 = new Shape(*s1);

    cout << "Shape 2 " << endl;
    s2->Show();

    *x = 1000;
    *y = 5000;

    cout << "Shape 1" << endl;
    s1->Show();

    cout << "Shape 2" << endl;
    s2->Show();

    delete s1;
    delete s2;
    return 0;
}