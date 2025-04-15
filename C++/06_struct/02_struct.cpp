#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    int age;

    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    };

    void showInfo() const
    {
        cout << "Name of the Student is: " << name << endl;
        cout << "Age of the Student is: " << age << endl
             << endl;
    }
};

// Working with array and vectors
int main()
{
    // Working with Vector.
    vector<Student> students;

    students.push_back(Student("Alice", 32));
    students.push_back(Student("Charlie", 25));
    students.push_back(Student("John", 23));

    for (const Student &s : students)
    {
        s.showInfo();
    }

    // Working with Array
    return 0;
}