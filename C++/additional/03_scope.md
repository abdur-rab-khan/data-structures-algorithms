# 🚧 Scope in C++
> In C++, Scope of a variable is the extent (`area`) in the code up to which the variable can be accessed or worked with. It is the `region` of the program where the variable is accessible.

## Table of Contents
- [🚧 Scope in C++](#🚧-scope-in-c)
    - [Global Scope](#1-global-scope)
    - [Local Scope](#2-local-scope)
    - [🪞 Variable Shadowing](#🪞-variable-shadowing)
    - [⭐ Variations of scopes in C++](#⭐-variations-of-scopes-in-c)
        - [1. Instance Scope](#1-instance-scope)
        - [2. Static Member Scope](#2-static-member-scope)
        - [3. Namespace Scope](#3-namespace-scope)
            - [➕ Defining a namespace](#➕-defining-a-namespace)
            - [🔁 Nested namespace](#🔁-nested-namespace)
            - [🪜 Extending Namespace](#🪜-extending-namespace)
            - [📛 Unnamed namespace](#📛-unnamed-namespace)
            - [🧾 Namespace in Header file](#🧾-namespace-in-header-file)

- There are **two** types of Scope
    1. ### Global Scope
        > Global scope is a `region` outside any function or block. Variables declared here are accessible throughout the entire program and are called **Global Variables**.

        ```cpp
        #include<iostream>

        using namespace std;

        int global = 52; // Global variable - accessible from anywhere

        void display(){
            cout << "From Function: " << global << endl;
        }

        int main(){
            cout << "From main: " << global << endl;
            display();
            return 0;
        }
        ```
    2. ### Local Scope
        > Local Scope is the `region` inside the curly braces **`{}`**. Variable defined within a **function** or **block** are said to be local to those function or block are called **local scope**. Local variable do not exits outside the block or function.

        ```cpp
        #include<iostream>

        using namespace std;

        int main(){
            {
                int age = 55;

                cout << age << endl; // 55
            }

            cout << age << endl; // Error because 'age' is not declared within this scope and cannot be accessed here.

            return 0;
        }
        ```
    ## 🪞 Variable Shadowing
    > Local variable inside a function with the same name as that of a global variable, the main function variable `num` shadow the variable of outer function `num`. And compiler take the value from current scope like in the below (`which is main`).

    ```cpp
    #include<iostream>

    using namespace std;

    int num = 42;

    int main(){
        int num = 52;

        cout << num << endl;
    }
    ```

    ## ⭐ Variations of scopes in C++
    > Apart from primary classification of the scopes as global and local, there are few more other specialized variations of these scopes that divides the declared variable based on its visibility and accessibility.
    - Instance Scope
    - Static Member Scope
    - Namespace Scope

        ### 1. Instance Scope
         > Instance Scope is refers to the **`region`** inside the class but outside from any member function of the class. The variable declared here is called **Instance variable**, That can access throughout whole class and They can be access using class Object.

        ```cpp
        #include<iostream>
        using namespace std;

        class A{
            public:
            int instanceVar; // Instance Variable

            A(int val){
                instanceVar = value
            }

            void display(){
                cout << "Value is:- " << instanceVar << endl;
            }
        }

        int main(){
            // Create a1 with instance variable instanceVar = 42;
            A a1(42);
            a1.display(); // 42

            // Create a2 with instance variable instanceVar = 52;
            A a2(52);
            a2.display() // 52

            return 0;
        }

        ```

        ### 2. Static Member Scope 
        > The static variable and functions are declare using `static` keyword. These variable and functions shared across all instance of a class and can be accessed using the class name without creating the instance.
        ```cpp
        #include<iostream>
        using namespace std;

        class A{
            public:
            // This is static variable that can access in the class as well as outside the class without creating there instance.
            static int var;
        }

        A::var = 55;

        int main(){
            // Access static variable
            cout << A::var << endl; // 55

            return 0;
        }
        ```

        ### 3. Namespace Scope
        > A namespace is a container that allows developers to create a separate scope where we can define variables, function, class. It helps to avoid name conflict and group related code together. These variable, function and class can access by namespace name and scope resolution operator.

        * #### ➕ Defining a namespace
            ```cpp
            namespace namespace_name 
            {
            // code declarations i.e. variable  (int a;)
            method (void add();)
            classes ( class student{};)
            }
             ```
        * To use namespace we have to method
            1. Using directly `namespace_name::variable,class,function`.
            2. Using **using directive** `using namespace first_name_space`. and directly call variable,function,class.

            ```cpp
            #include<iostream>
            using namespace std;

            namespace first_name_space{
                void display(int value){
                    cout << value << endl;
                }
            }

            namespace second_name_space{
                void sayName(string name){
                    cout << name << endl;
                }
            }

            using namespace first_name_space; // Instead of getting whole namespace we can you like this also.
            using first_name_space::display;
            int main(){
                display(44); // 44

                second_name_space::sayName("Abdur Rab Khan"); // Abdur Rab Khan
                return 0;
            }
            ```

    * #### 🔄 Nested namespace   
        > Namespace can be nested, where you can define one namespace inside another namespace as follows:
        ```cpp
        namespace first_namespace{
            // code declaration
            name space nested_namespace{
                // code declaration
            }
        }
        ```
        ```cpp
        #include <iostream>
        using namespace std;

        // first name space
        namespace first_space
        {
        void func()
        {
            cout << "Inside first_space" << endl;
        }
        // second name space
        namespace second_space
        {
            void func()
            {
                cout << "Inside second_space" << endl;
            }
        }
        }
        using namespace first_space::second_space;
        int main ()
        {
            // This calls function from second name space.
            func();
        
            return 0;
        }

        ```
    * #### 🪜 Extending Namespace
        > It is also possible to create two namespace with same name. The second name space is nothing but actually continuation of the first namespace.
        
        ```cpp
        #include<iostream>
        using namespace std;

        namespace first{
            int value1 = 50;
        }

        namespace first{
            int value2 = 51;
        }

        int main(){
            cout << first::value1 << endl; // 50
            cout << first::value2 << endl; // 51
        }
        ```

    * #### 📛 Unnamed namespace
        > It is a type of namespace where the namespace does not have any name, and we can directly use it in our code. Here, the name of the namespace is uniquely generated by the compiler. This is only accessible within a file. Unnamed namespaces are the replacement for static declaration variables.

        ```cpp
        // C++ program to demonstrate working of unnamed 
        // namespaces
        #include <iostream>
        using namespace std;

        // unnamed namespace declaration
        namespace
        {
            int rel = 300; 
        }

        int main()
        {
            cout << rel << "\n"; // prints 300
            return 0;
        }
        ```

    * #### 🧾 Namespace in Header file
        > We can create namespace is one file and access content using another file This done using following manner.

        * `file_01.cpp`
        ```cpp
        namespace first{
            int age = 21;
        }
        ```

        * `file_02.cpp`
        ```cpp
        #include<iostream>
        #include "file_01.cpp"

        using namespace std;

        int main(){
            cout << first::age << endl; // 21

            return 0;
        }
        ```