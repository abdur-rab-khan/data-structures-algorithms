// #include <iostream>
// using namespace std;

// class SmartPointer {
//    public:
//     int* ptr = nullptr;
//     explicit SmartPointer(int* p = nullptr) { ptr = p; }

//     // Destructor
//     ~SmartPointer() {
//         cout << "Deallocating the memory" << endl;
//         delete (ptr);
//     }

//     int& operator*() { return *ptr; }
// };

// class Try {
//    public:
//     string name = "Abdur Rab Khan";

//     string operator*() { return name + "Wow"; }
// };

// int main() {
//     SmartPointer ptr(new int());
//     *ptr = 45;

//     cout << ptr.operator*() << endl;
//     return 0;
// }

// Types of OwnerShip

#include <iostream>
#include <memory>
using namespace std;

class Car {
   public:
    void drive() { cout << "Drawing the Car" << endl; }
};

int main() {
    // unique_ptr
    // unique_ptr<Car> carPtr = make_unique<Car>();
    unique_ptr<Car> carPtr(new Car);

    cout << "Memory Address is:- " << carPtr.get() << endl;

    carPtr->drive();
    // unique_ptr<Car> copyCarPtr = carPtr; ❌ Error: can't copy
    unique_ptr<Car> copyCarPtr = move(carPtr);  // ✅ Ownership transferred
    carPtr->drive();
    copyCarPtr->drive();

    // With Basic Data Type
    unique_ptr<int> num = make_unique<int>(54);

    cout << *(num.get()) << endl;
    cout << *num << endl;
    return 0;
}