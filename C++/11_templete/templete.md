# 🧾 Template in C++
>
> C++ Template allow use to write generic code, reusable code that can work with any data type. The idea is to use template type in the parameter so we don't need to write the same code for other datatype.

- [🧾 Template in C++](#-template-in-c)
  - [Define Template](#define-template)
    - [1. Function Template](#1-function-template)
    - [2. Class Template](#2-class-template)
    - [3. Template Parameter](#3-template-parameter)
    - [4. Variadic Template](#4-variadic-template)
    - [5. Specialization Template](#5-specialization-template)
  - [Working Mechanism of template](#working-mechanism-of-template)

## Define Template
>
> To define the `template` we use `template` and `typename` as show ⬇️.

```cpp
template<typename A, typename B, ...>
entity_definition
```

- The `template` keyword is use to define that the given entity is template and `typename` keyword is used to define that `template parameter` is nothing but types.
- The `typename` keyword can be replace by `class` anytime.

    ```cpp
    template<class A, class B>
    entity_definition
    ```

- There are six type of template
  1. [**Function Template**](#1-function-template)
  2. [**Class Template**](#2-class-template)
  3. [**Template Parameter**](#3-template-parameter)
  4. [**Variadic Template**](#4-variadic-template)
  5. [**Specialization Template**](#5-specialization-template)

### 1. Function Template

> Function Template allow as to write generic code that can be work with any type of datatype. To achieve this we use function template.

- **Example**: To build a function that can return max value and should work with any time of data. To achieve this we can write same code for all datatype, but we have solution call template.

    ```cpp
    #include<iostream>
    using namespace std;
    
    template<typename T>
    T getMaxValue(T a, T b){
        return (a > b) ? a : b;
    }

    int main(){
        cout << "Max value from int " << myMax(5, 10) << endl; // 10
        cout << "Max value from float " << myMax(5.2, 2.5) << endl; // 5.2
        cout << "Max value from char " << myMax('a', 'z') << endl; // z
        return 0;
    }
    ```

  - `template<typename T>` defines the template with type parameter `T`.
  - The function `getMaxValue` take two parameter of type `T` and return their sum, also of type `T`.

### 2. Class Template
>
> Similar to function, Class template is useful when you want to create class that can work with any type of data. It is helpful of classes like **LinkedList**, **BinaryTree**, **Stack**, **Queue**.

> 💀 **Note**: In Class Template we have to Specify Template Parameters. In Class automatic **deduction**  is not available.

- **Example**

    ```cpp
    #include <iostream>
    using namespace std;
    
    template <typename T>
    class Box {
    private:
        T value;
    
    public:
        Box(T val) : value(val) {}
    
        T getBoxValue() { return value; }
    };
    
    int main() {
        Box<int> intBox(10);
        Box<double> doubleBox(5.5);
    
        cout << intBox.getBoxValue() << endl;
        cout << doubleBox.getBoxValue() << endl;
        return 0;
    }
    ```

  - `template <typename T>` defines the template with parameter `T`.
  - The class `Box` contains member variable `value` of type `T`. and a member function `getBoxValue()` return value of type `T`.

  - Template with more than one arguments.

    ```cpp
    template <typename T1, typename T2, typename T3 = string>
    class Example {
    private:
        T1 value1;
        T2 value2;
        T3 value3;
    
    public:
        Example(T1 val1, T2 val2, T3 val3) : value1(val1), value2(val2), value3(val3) {}
    
        void getValues() {
            cout << "Value 1 " << value1 << " Value 2 " << value2 << " Value 3 " << value3 << endl;
        }
    };
    
    int main() {
        Box<int> intBox(10);
        Box<double> doubleBox(5.5);
    
        cout << intBox.getBoxValue() << endl;
        cout << doubleBox.getBoxValue() << endl;
    
        Example<string, int, string> ex1("Hello", 22, "Bye");
    
        ex1.getValues();
        return 0;
    }
    ```

    - `template<typename T1, typename T2, typename T3 = string>` define the template with three types `T1`, `T2`, `T3`. `T3 = string` is a default string.

### 3. Template Parameter

> C++ templates support several types of parameter beyond just type (i.e `typename`, `class`), such as non-type template parameter (for constant value, pointers etc) and **template template parameter**. We can also define variable as a template variable.

> 💀 **Note**: You can't pass local variable as pointer or reference only work with global variable. Template support pointer or reference as to be send at compile time, but when pass from main function(main function run at runtime not compile time) it will cause error.

- **Non-type template parameter**
  - You can pass integers, reference, pointer, enum, `size_t` (for array size) as template parameter

- **Example**

    ```cpp
    #include<iostream>
    using namespace std;

    template<typename T, int size> // We can also define default parameter --> template<typename T = int, typename N = float>
    class Array{
        private:
        T arr[size];

        public:
        void setElement(int index,T value){
            if(index >= 0 && index < size){
                arr[index] = value;
            }
        }

        T getElement(int index){
            if(index >= 0 && index < size){
                return arr[index];
            }

            return T(); // Return default value if index is out of bounds
        }
    }

    template<typename T> constexpr T pi = T(3.14159)

    int main(){
        Array<int, 5> intArr;
        
        intArr.setElement(1, 55);
        cout << "At 1 index " << intArr.getElement(1);
        cout << "Pi as float " << pi<float> << endl;
        cout << "Pi as int " << pi<int> << endl;
        return 0;
    }
    ```

  - `template<typename T, int size>` is define the template with type parameter `T`, int parameter `int size`.
  - If you pass custom parameter like integers, float, pointer, reference then you have to pass like this `function_name<...parameters>(...function_parameters)`.
  - `template<typename T> constexpr T pi = T(3.14159)` is a way to define template variable. `constexpr` is ensures that the variable is a constant expression and evaluate at the compiler time not at run time.

### 4. Variadic Template

> Variadic Template in C++ allow us to pass list of parameter to the function as well as to the class.

- **Example**

    ```cpp
    #include<iostream>
    using namespace std;

    int main(){

        return 0;
    }
    ```

### 5. Specialization Template

> Specialization template allow us to define a specific implementation of a template for a particular type. This is useful you want to change the behavior of a template based on his type.

- **Example**

    ```cpp
    #include<iostream>
    using namespace std;
    
    template<typename T>
    void add(T a, T b){
        T result = a + b;
        cout << "The result is " << result << endl;
    }
    
    template<>
    void add<int>(int a, int b){
        int result = a + b;
        cout << "The result of two integer is " << result << endl;
    }
    
    int main(){
        cout << add<int>(2,2) << endl; // The result of two integer is 4
        cout << add(2.5,2.5) << endl; // The result is 5
        cout << add(string("Abdur Rab"), string(" Khan")) << endl; // The result is Abdur Rab Khan
        return 0;
    }
    ```

## Working Mechanism of template

> Templates are filled in when the code is compiled. The idea is simple source code only contains function/class, but compiled code may contain multiple copies of the same function and class.

![Template-Mechanism](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/06/templates-cpp.jpg)
