# 💫 Structure
> In C++ structure is a type of user defined data type, that group different variables under a single name (It also can store functions). These variable can me different types, and they are called `Members`.

* It's similar to C++ class but with some key difference.

    * In `struct`, members are `public` by default.
    * In `class`, members are `private` by default.
* Struct Also support `OOPS` concepts.
    * `Encapulation`
    * `Abstraction`
    * `Inheritance`
    * `Polymorphism`



## 📔 Simple `Struct` Example
```cpp
struct name_struct {
    string name;
    int age;

    // Also you can define function here.
    void display(){
        cout << name << endl << age <<endl;
    }
} 

--> At here you can add the name if you want to directly initialize directly.


void main(){
    name_struct s1;

    s1.name = "Abdur Rab Khan";
    s1.age = 21;

    s1.display(); // Print all the informations.

    return 0;
}
```

## 🥇 `Struct` with constructor
```cpp
struct Student{
    string name;
    int age;
    int roll_no;
    
    // Contructor
    Student(string name,int age,int roll){
        this->name = name;
        this->age = age;
        roll_no = roll;
    }

    void display(){
        cout<< name << age << roll_no <<endl;
    }
}

int main(){
    Student s1("Abdur Rab",21,32);

    s1.display();

    return 0;
}
```

## 📃 `Struct` in Array and vector
```cpp
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


struct Student{
    string name;
    int age;
    int roll_no;
    int marks[4];

    void enterDetails(){
        cin.ignore();
        
        cout<<"Enter you name:- ";
        getline(cin,name);

        cout<< endl <<"Enter your age:- ";
        cin >> age;

        cout << endl << "Enter your roll no:- ";
        cin >> roll_no;

        cout << endl <<"Enter you marks:- " <<endl;
        for(int i = 0; i < 4; i++){
            cin >> marks[i];
        }
    }

    void displayInfo(){
        cout<<endl<<"Student Details"<<endl;

        cout<<"Name:- " << name<<endl;
        cout<<"Age:- " << age<<endl;
        cout<<"Roll No. " << roll_no<<endl;

        cout<<"Marks:- ";
        for(int i = 0; i < 4; i++){
            cout << marks[i] << " ";
        }
    }
};

int main(){
    Student students[2];

    for(int i = 0; i < 2; i++){
        students[i].enterDetails();
    }

    for(int i = 0; i < 2; i++){
        students[i].displayInfo();
    }

    return 0;
}


// Struct in Vector
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
```

## 🏛️ `OOPS` in `Struct`
```cpp
#include <iostream>
using namespace std;

struct Animal {
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

struct Dog : public Animal {
    void speak() override {
        cout << "Bark" << endl;
    }
};

int main() {
    Animal* a = new Dog();
    a->speak();  // Output: Bark

    delete a;
    return 0;
}


```