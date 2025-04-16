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
        // if (s.name == "Alice")
        // {
        //     s.name = "Abdur Rab Khan";
        //     s.age = 21;
        // } --> It work when we does not put const. Bcz it refering to original variable, not COPY.

        s.showInfo();
    }

    // Working with Array
    Student stu2[3] = {{"Alice", 32}, {"Abdur Rab Khan", 21}, {"John", 23}};

    cout << endl
         << endl;
    for (const Student &stu : stu2)
    {
        stu.showInfo();
    }
    return 0;
}