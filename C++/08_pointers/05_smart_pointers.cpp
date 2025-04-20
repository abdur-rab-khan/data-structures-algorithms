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

class Car1 {
   public:
    void drive() { cout << "Drawing the Car" << endl; }
};

class File {
   public:
    void open() { cout << "File is opened" << endl; }
};

class Car;

class Owner {
   public:
    string owner_name = "Abdur Rab Khan";
    shared_ptr<Car> car = make_shared<Car>();

    ~Owner() { cout << "Car is destroyed" << endl; }
};

class Car {
   public:
    // shared_ptr<Owner> owner = make_shared<Owner>();
    weak_ptr<Owner> owner;  // --> By using this we only share resource instead of owning it.

    string get_owner_name() {
        if (auto temp = owner.lock()) {
            return temp->owner_name;
        }
    }

    ~Car() { cout << "Owner is destroyed" << endl; }
};

int main() {
    // unique_ptr
    // unique_ptr<Car> carPtr = make_unique<Car>();
    unique_ptr<Car1> carPtr(new Car1);

    cout << "Memory Address is:- " << carPtr.get() << endl;

    carPtr->drive();
    // unique_ptr<Car> copyCarPtr = carPtr; ❌ Error: can't copy
    unique_ptr<Car1> copyCarPtr = move(carPtr);  // ✅ Ownership transferred
    carPtr->drive();
    copyCarPtr->drive();

    // With Basic Data Type
    unique_ptr<int> num = make_unique<int>(54);

    cout << *(num.get()) << endl;
    cout << *num << endl;

    // shared_pointer
    // shared_ptr<File> f1 = make_shared<File>();
    shared_ptr<File> f1(new File);
    f1->open();

    shared_ptr<File> f2 = f1;
    f2->open();

    cout << "Address of f2:- " << f2.get() << endl;
    cout << "Reference Count:- " << f2.use_count() << endl;

    shared_ptr<int> num1 = make_shared<int>(42);
    shared_ptr<int> num2 = make_shared<int>(52);

    shared_ptr<int> num3 = num1;

    if (*num1 == *num3) {  // True
        cout << "Both num1 and num2 shared same memory address." << endl;
    }

    cout << "Before swapping" << endl;
    cout << "Value of num2 is:- " << *num2 << endl;
    cout << "Value of num3 is:- " << *num3 << endl;

    num2.swap(num3);

    cout << "After swapping" << endl;
    cout << "Value of num2 is:- " << *num2 << endl;
    cout << "Value of num3 is:- " << *num3 << endl;

    // Weak ptr
    shared_ptr<int> number1 = make_shared<int>(55);
    shared_ptr<int> number2 = number1;

    cout << "Reference count:- " << number1.use_count() << endl;
    cout << "Both number1 and number2 address:- " << number1 << " " << number2 << endl;

    weak_ptr<int> number3 = number1;

    cout << "Reference count:- " << number1.use_count()
         << endl;  // 2 instead of 3 because it does not own it.

    if (auto temp = number3.lock()) {
        cout << "Value of number 3 is:- " << *temp << endl;
    }

    cout << endl << endl;
    std::shared_ptr<Owner> p = std::make_shared<Owner>();
    cout << p.use_count() << endl << endl;

    std::shared_ptr<Car> c = std::make_shared<Car>();

    p->car = c;
    c->owner = p;

    cout << "Owner name is:- " << c->get_owner_name() << endl;

    return 0;
}