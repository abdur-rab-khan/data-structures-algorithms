#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the number of students ";
    cin >> size;

    string* student = new string[size];

    cin.ignore();
    for (int i = 0; i < size; i++) {
        cout << "Enter name of the students ";
        getline(cin, student[i]);
    }

    cout << "List students " << endl;
    for (int i = 0; i < size; i++) {
        cout << student[i] << endl;
    }

    delete[] student;
    return 0;
}