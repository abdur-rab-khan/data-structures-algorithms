# 💫 Structure
> In C++ structure is a type of user defined data type, that group different variables under a single name (It also can store functions). These variable can me different types, and they are called `Members`.

* It's similar to C++ class but with some key difference.

    * In `struct`, members are `public` by default.
    * In `class`, members are `private` by default.

## 📔 `Struct` Declaration
* ### Simple `Struct` Example
```
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

* ### `Struct` with constructor
```
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

