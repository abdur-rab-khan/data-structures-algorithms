#include <iostream>
#include <vector>
using namespace std;

void looping(int (&arr)[3]) {
    cout << endl << endl << endl;

    for (int num : arr) {
        cout << num << endl;
    }
}

// Fixed Size (Array) || Dynamic Size (Vector).
int main() {
    string car[] = {"Volvo", "BMW", "Tesla", "Maruti", "Toyota"};
    int numbers[] = {1, 2, 3, 4, 5, 6};

    car[0] = "Tata";

    cout << *car << endl;

    // Looping through an array.
    int car_size = sizeof(car);  // Getting 160 instead of 5 because it returns byte.
    int car_length = sizeof(car) / sizeof(car[0]);

    // Using for loop
    for (int i = 0; i < car_length; i++) {
        cout << i << " " << car[i] << endl;
    }

    cout << endl;
    // Using for each loop
    for (int num : numbers) {
        cout << num << endl;
    }

    // Omit Declaration.
    // int number[]; ❌ You have to define the size of the array.
    int number[3];

    number[0] = 11;
    number[1] = 22;
    number[2] = 33;

    // If we try to add the element above the size it will cause error.
    number[3] = 55;  // ❌

    looping(number);
    // VECTOR which is dynamic type.
    vector<string> cars = {"BMW", "TOYOTA", "BENZ"};

    cars.push_back("MARUTI");

    // Pointer in C++
    int num[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        cout << "The " << i << "th " << "Element is:- " << *(&(num[i])) << endl;
    }
    return 0;
}