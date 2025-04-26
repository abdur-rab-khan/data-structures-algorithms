#include <iostream>
using namespace std;

class Student {
    // data
   public:
    string name;
    int age;
    int roll_no;
    float cgpa;

    // member functions
    void getStudentInfo() {
        cout << "Name " << name << endl;
        cout << "Age " << age << endl;
        cout << "Roll No " << roll_no << endl;
        cout << "CGPA " << cgpa << endl;
    }
};

int main() {
    Student s1;

    s1.name = "Abdur Rab Khan";
    s1.age = 21;
    s1.roll_no = 32;
    s1.cgpa = 8.70;

    s1.getStudentInfo();

    return 0;
}