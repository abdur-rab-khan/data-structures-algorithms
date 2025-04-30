#include <iostream>
using namespace std;

template <typename T>
class Box {
   private:
    T value;

   public:
    Box(T val) : value(val) {}

    T getBoxValue() { return value; }
};

template <typename T1, typename T2, typename T3>
class Example {
   private:
    T1 value1;
    T2 value2;
    T3 value3;

   public:
    Example(T1 val1, T2 val2, T3 val3) : value1(val1), value2(val2), value3(val3) {}

    void getValues() {
        cout << "Value 1 " << value1 << " Value 2 " << value2 << " Value 3 " << value3 << endl;
    }
};

template <typename T, int size>
class Array {
   private:
    T arr[size];

   public:
    void setElement(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    T getElement(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }

        return T();  // Return default value if index is out of bounds
    }
};

template <int* p>
void printValue() {
    cout << "The value of p is " << *p << endl;
}

int num = 55;

int main() {
    Box<int> intBox(10);
    Box<double> doubleBox(5.5);

    cout << intBox.getBoxValue() << endl;
    cout << doubleBox.getBoxValue() << endl;

    Example<string, int, string> ex1("Hello", 22, "Bye");

    ex1.getValues();

    // Array
    Array<int, 5> intArr;

    intArr.setElement(1, 55);
    cout << "At 1 index " << intArr.getElement(1) << endl;
    return 0;
}