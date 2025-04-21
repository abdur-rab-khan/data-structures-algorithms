# 🚧 Scope in C++
> In C++, Scope of a variable is the extent (`area`) in the code up to which the variable can be accessed or worked with. It is the `region` of the program where the variable is accessible.

- There are **two** types of Scope
    1. **Global Scope**
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
    2. **Local Scope**
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
    ### 🪞 Variable Shadowing
    > Local variable inside a function with the same name as that of a global variable.
