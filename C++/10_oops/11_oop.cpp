#include <iostream>
using namespace std;

class Test {
    int x;
    int y;

   public:
    Test(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Test& setX(int a) {
        x = a;
        return *this;
    }
    Test* setY(int a) {
        y = a;
        return this;
    }

    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int main() {
    Test t1(55, 155);

    t1.print();

    t1.setX(155).setY(55);

    t1.print();
    return 0;
}