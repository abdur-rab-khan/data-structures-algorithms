#include <iostream>
using namespace std;

enum class TypeData {
    I,
    D,
};

void CallbackFunction(void* data, TypeData dataType) {
    switch (dataType) {
        case TypeData::I:
            cout << "Callback for integer: " << *(int*)data << endl;
            break;

        case TypeData::D:
            cout << "Callback for double: " << *(static_cast<double*>(data)) << endl;
            break;
        default:
            cout << "Unsupported data type in callback!" << endl;
    }
}

void performOperation(void* data, TypeData dataType, void (*callback)(void*, TypeData)) {
    callback(data, dataType);
}

int main() {
    // int x = 55;

    // int* ptr = &x;

    // cout << "In this memory address:- " << ptr << " we have:- " << *ptr << endl;

    // float y = 20.3;

    // // ptr = &y; // It cause error here

    // void* address = nullptr;

    // int num = 121;
    // float sal = 2000.50;
    // char grade = 'A';

    // address = &num;
    // cout << endl;
    // cout << "The value of num is:- " << *(static_cast<int*>(address)) << endl;
    // cout << "The Address of num is:- " << address << endl;

    // address = &sal;
    // cout << "The value of sal is:- " << *(static_cast<float*>(address)) << endl;
    // cout << "The Address of sal is:- " << static_cast<float*>(address) << endl;

    // address = &grade;
    // cout << "The value of sal is:- " << *(static_cast<char*>(address)) << endl;
    // cout << "The Address of sal is:- " << address << endl;

    // CALLBACK FUNCTIONs.
    int num = 121;
    double doubleValue = 121.21151131;

    performOperation(&num, TypeData::I, CallbackFunction);
    performOperation(&doubleValue, TypeData::D, CallbackFunction);
    return 0;
}