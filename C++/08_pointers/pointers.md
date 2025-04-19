### **Table of content**
- [🪞 Reference](#🪞-reference)
    - [🧑🏻‍💻 Example](#-example)
- [💽 Pointer](#💽-pointer)
    - [🧑🏻‍💻 Example](#🧑🏻‍💻-example)
    - [🪄 Dereferencing](#🪄-dereferencing)
    - [Modify Address](#modify-address)
    - [📃 Types of Pointers](#📃-types-of-pointers)
        - [Wild Pointer](#wild-pointer)
        - [NULL Pointer](#null-pointer)
        - [Void Pointer](#void-pointer)
        - [Dangling](#dangling)
        - [Double Pointer](#double-pointer)
        - [Pointer to functions](#pointer-to-functions)
        - [Smart Pointer](#smart-pointers)
---

# 🪞 Reference
> The `reference` is the alias of another variable. It is not a copy but another name for existing one.
* ***For more refer from additional folder.***

## 🧑🏻‍💻 Example
```
int num = 55;
int& ref = num;

cout << ref <<endl; // 55
cout << num << endl; // 55

ref = 66;

cout << ref <<endl; // 66
cout << num <<endl; // 66
```
* `ref` refer to `num`.
* Changes on `ref` can also effect to `num` and `vise-versa`.



# 💽 Pointer
> The `Pointer` is used to get the memory address of the given variable. To get memory address we use **`&`** Operator.
* **The size of the pointer is equal for every pointer. not matter way system and what type.**
    * **8 Byte** for a **64-bit System**. 
    * **4 Byte** for a **32-bit System**.     
* In C++, When we create variable a memory address is assigned to the variable. And when assign value to the variable, it stored in the memory address.
* A **`pointer`** is a variable that store the memory address as its value. We can't store memory address directly.
* A **`pointer`** variable points to a data type (like `int`, `string`) of the same type. and is created using **`*`** operator.
## 🧑🏻‍💻 Example
![Pointer Example](https://media.geeksforgeeks.org/wp-content/uploads/pointers-in-c.png)
```
int num = 11;

cout << &num <<endl; // We get memory address


int x = 55;
int* ptr = &x;

cout << x <<endl; // Memory address of variable x.
```
## 🪄 Dereferencing
> It is a process to access the value present at the memory address pointed by the pointer is called **`dereferencing`**.
* **`Example`**

    ```
    int x = 55;
    int* ptr = &x;

    cout << *ptr << endl; // This is called dereferencing.
    cout << ptr <<endl; // We got memory address where why point.
    ```



## Modify Address
> This Memory address can be modified to point another memory location if it's data type is same.

* **`Example`**

```
int x = 55
int* ptr = &x;

cout << *ptr <<endl; // 5

int a = 12;

ptr = &a;

cout << *ptr <<endl; // 12
```

## 📃 Types of Pointers
* There are 4 types of **pointers**.
    
    1. #### `Wild Pointer`

        > When pointer is created, and we does not assign variable on it. it just contains random memory address that may or may not be valid. this type of pointers are called as **`wind pointer`**. **NOT RECOMMENDED**
        
        * **`Example`**

        ```
        int* ptr;
        ```
    
    2. #### `NULL Pointer`

        > A **`NULL Pointer`** is a pointer that does not point to any valid memory location but NULL. If is Often used to initialize pointer.

        * **`Example`**

        ```
        int* ptr = NULL
        
        // OR

        int* ptr = nullptr;
        ```
    3. #### `Void Pointer`

        > The void pointer is a ***special type*** of pointer in C++. Which represent the absence of type. **`Void Pointer`** are pointer that point to the value that has no particular type. It can be point to any data type.

        > So the Datatype is does not know. the compiler also does not know how many bytes to access when the void pointer dereferenced. So compiler have to first convert it into other pointer type that points to concrete data type. To do this we can use **`static_cast<source_type>(source)`** to say the compiler how many bytes you have to access.

        * It is most commonly used in dynamic memory allocation. when we does not know about the type.
        * **Generic Coding** Where we have single pointer used for many variable.
        * **`static_cast<source_type>(source)`** It used to convert from other type of another type. it is done in **compile time**. If want to cast pointer **`static_cast<source_type*>(source)`** **OR** **`(int*)address`**.


        * **`Example`**
            ```
            int x = 55;

            int* ptr = &x;

            cout << "In this memory address:- " << ptr << " we have:- " << *ptr << endl;

            float y = 20.3;

            // ptr = &y; // It cause error here

            void* address = nullptr;

            int num = 121;
            float sal = 2000.50;
            char grade = 'A';

            address = &num;
            cout << endl;
            cout << "The value of num is:- " << *(static_cast<int*>(address)) << endl;
            cout << "The Address of num is:- " << address << endl;

            address = &sal;
            cout << "The value of sal is:- " << *(static_cast<float*>(address)) << endl;
            cout << "The Address of sal is:- " << static_cast<float*>(address) << endl;

            address = &grade;
            cout << "The value of sal is:- " << *(static_cast<char*>(address)) << endl;
            cout << "The Address of sal is:- " << address << endl;
            ```

            ```
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

            int main(){
                int num = 121;
                double doubleValue = 121.21151131;
                performOperation(&num, TypeData::I,CallbackFunction);
                performOperation(&doubleValueTypeData::D,CallbackFunction);

                return 0;
            }
            ```

    4. #### `Dangling`
        > In C++, A Pointer that point to the memory location that has been deallocated earlier in the program is called **`Dangling`**.
        * **Cases that leads to dangling Pointer in C++**
            * Deallocation of Memory using delete or free().
            * Referencing the Local Variable of the function after it is executed.
            * Variable goes out of scope.
        * **Note**
            
            * Memory Deallocation only applicable when memory is created dynamically.
            * When memory is created dynamically it does not deallocate automatically we have to free it manually.
            * **There are may way to allocate memory dynamically.**
                * **Reference [Memory Management](../additional/memory_manegment.md)
                * Using `new`
                * Using `malloc`, `calloc`, `realloc`
                * Using Smart Pointer
                * Using Custom memory Allocator (Advanced)

                    ![](https://media.geeksforgeeks.org/wp-content/uploads/20240514121236/Dangling-Pointer-in-Programming.webp)
        * **`Example:- `**
            
            ```
            int* num = new int(11);
            cout << "Value is::- " << *num << endl; // 11
            delete ptr // Here ptr become dangling pointer --> They point memory location but inside the memory location we does not have anything (random value).
            cout << *num << endl; // --> Random Value
            ```

            ```
            // What Happen Here???
            // After function is executed the num variable getting freed.
            // In the main function when we try to access getting error.

            int* getDanglingPointer() {
                int num = 42;

                return &num;
            }

            int main(){
                int* danglingPtr = getDanglingPointer(); // Getting Error

                cout << danglingPtr << endl;
            }

            // SOLUTION!!!
            // Use Dynamic Approach to initialize the variable.

            int* getDanglingPointer(){
                // You can choose any approach from ⬇️
                static int num = 42; --> return 42
                int* num = new int(42); --> return Address
                int* num = (int*)malloc(sizeof(int)); --> return Address;
                num = 42

                return num;
            }
            ```

    5. #### `Double Pointer`
        > **`Double Pointer`** is a special type of pointer, that point to the another pointer (also known as pointer to pointer). It is useful when working with multi-level data structure like array of pointer or dynamic memory management.

        * **Note**
            * The size of the double pointer are totally depend upon the machine, Like CPU architecture and OS used.
                * For 64-bit OS pointer will be 8 bytes.
                * For 32-bit OS pointer will be 4 bytes. 

                    ![Double Pointer](https://media.geeksforgeeks.org/wp-content/uploads/20221111110818/DoublePointer.png)

        * **Example**
            ```
            void allocate(int** ptr) {
                *ptr = new int;  // Allocates memory for an integer and stores the address in the pointer
                **ptr = 42;      // Dereferences twice to store the value 45 in the allocated memory
            }

            int main() {
                // Modify pointer inside function.
                int* p = nullptr;
                allocate(&p);
                cout << *p << endl;

                void* ptr = nullptr;
                void** doublePointer = &ptr;  // Address of ptr

                cout << "Initial ptr (nullptr): " << *doublePointer
                     << endl;  // Getting the value inside ptr. --> 0

                *doublePointer = new int;
                *(static_cast<int*>(*doublePointer)) = 50;

                cout << "Value at int ptr: " << *(static_cast<int*>(ptr)) << endl;

                delete static_cast<int*>(ptr);  // Free the memory to prevent memory leak

                *doublePointer = new float;
                *((float*)ptr) = 50.50;

                cout << "Value at float ptr: " << *(static_cast<float*>(ptr)) << endl;

                delete static_cast<float*>(ptr);  // Clean up

                return 0;
            }
            ```
            * **Draw a Matrix**
            ```
            int row = 3;
            int col = 3;

            // First Initialize array for 3 rows.
            int** matrix = new int*[row];

            // <------------> OR <------------->

            int* matrix = new int[row];
            int** matrix_ptr = &matrix;

            // Initialize memory location for row
            for (int i = 0; i < row; i++) {
                matrix[i] = new int[col];
            }

            // Initialize memory location for cols
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = (i + 1) * (j + 1);
                }
            }

            // Print all value
            for (int i = 0; i < row; i++) {
                cout << "[ ";
                for (int j = 0; j < col; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << " ]" << endl;
            }

            // Free the allocated memory
            for (int i = 0; i < row; i++) {
                delete[] matrix[i];  // delete each row
            }

            delete[] matrix;  // delete the array of pointers

            // Conceptual Diagram
            matrix (int**) - pointer to array of row pointers
                       |
                       |           Heap memory layout
                       v
                   +-------+       +-------+-------+-------+-------+
            matrix |   0   |-----> | int   | int   | int   | int   |  ← matrix[0]
                   +-------+       +-------+-------+-------+-------+
                   |   1   |-----> | int   | int   | int   | int   |  ← matrix[1]
                   +-------+       +-------+-------+-------+-------+
                   |   2   |-----> | int   | int   | int   | int   |  ← matrix[2]
                   +-------+       +-------+-------+-------+-------+

            ```
    6. #### `Pointer to functions`
        > Similar to normal **Pointer** that are used to point to variables. **`Pointer to functions`** are used to store the memory address of a function. Function pointer can also used to call function indirectly, Or they can also used to build **Higher Order Function**.

        * **Note**
            * Function pointer is used to point function, similarly, the pointers are used to pointer variable.
            * It utilized to save a function's address.
            * The function pointer is either used to call the function or it can be send an argument to another function.

                ![Pointer to functions](https://media.geeksforgeeks.org/wp-content/uploads/20221221122225/Function-Pointer-768.png)

        * ### Referencing and Dereferencing
            > Similar to pointer variable we can perform both Referencing and Dereferencing with a **function pointer**.
            * Referencing
                > When pointer is allocated the address of the function to be the associated with it them this process is called **`referencing`**.
            
            * Dereferencing
                > When we use the **`*`** operator to get the value of the pointer. 
            

        * **Example**
            * **Syntax**
                ```
                // Declaring
                return_type (*FuncPtr) (parameter type, ....); 

                // Referencing
                FuncPtr= function_name;

                // Dereferencing
                data_type x=*FuncPtr;
                ```
            ```
            int main() {
                int (*ptr)(int, int) = multiply;
            
                // Count function does not know how to print function pointer that is the reason they           can't
                // print the address.
                printf("Memory Address of this function:- %p", ptr);
                cout << endl << "Memory Address of this function:- " << (int*)ptr << endl;
                cout << "Memory Address of this function:- " << reinterpret_cast<void*>(ptr) << endl            << endl;
            
                cout << "The Multiplication of 2 x 2 is:- " << ptr(2, 2) << endl;
                return 0;
            }
            ```
            * **Build Higher Order Function**
            ```
            int multiply(int a, int b) {
                return a * b;
            };

            int performer(int a, int b, int (*func)(int, int)) {
                return func(a, b);
            }

            int main() {
                int (*funcPtr)(int, int) = multiply;

                cout << "The Multiplication of 4 x 4 is:- " << performer(4, 4, funcPtr) << endl;
                
                // Using std::function with lambda
                function<int(int, int)> func;

                func = multiply;

                cout << func(10, 10) << endl;
                
                return 0;
            }
            ```

            * Array of functions
            ```
            void add() {
                cout << "Add is called" << endl;
            }

            void remove() {
                cout << "Remove is called" << endl;
            }

            void update() {
                cout << "Update is called" << endl;
            }

            int main() {
                void (*main[])() = {add, remove, update};

                int choice = 0;

                main[choice]();
                return 0;
            }
            ```

            

    7. #### `Smart Pointers`
        > A **Smart Pointer** is a wrapper class over a pointer with an operator like **`*`** or **`->`**. The Object of the **smart pointer** are look like normal pointer. But ***Unlike Normal Pointer***, It can automatically allocated and deallocate the memory location.
        
        > To build Smart Pointer we some C++ functionality like [Destructor](https://www.geeksforgeeks.org/destructors-c/) and [Overloaded Operator](https://www.geeksforgeeks.org/operator-overloading-c/). **Destructor** is automatically call when object is going to out of scope. We call there to free the memory.

        > Smart pointers enable automatic memory management on heap memory to help avoid memory leaks. Think of them as pointers with automatic memory cleanup.

        ```
        #include <iostream>
        using namespace std;
        
        class SmartPointer {
           public:
            int* ptr = nullptr;
            explicit SmartPointer(int* p = nullptr) { ptr = p; }
        
            // Destructor
            ~SmartPointer() {
                cout << "Deallocating the memory" << endl;
                delete (ptr);
            }
        
            int& operator*() { return *ptr; }
        };
        
        class Try {
           public:
            string name = "Abdur Rab Khan";
        
            string operator*() { return name + "Wow"; }
        };
        
        int main() {
            SmartPointer ptr(new int());
            *ptr = 45;
        
            cout << ptr.operator*() << endl;
            return 0;
        }
        ```

        - **Problem with normal pointer**
            - Memory Leak
            - Dangling Pointers
            - Wild Pointers
            - Data Inconsistency

        - **Types of Smart Pointers**
            - auto_ptr
            - unique_ptr
            - shared_ptr
            - weak_ptr
        
        1. #### `unique_ptr` **- Exclusive Ownership**
        > When we initialize **unique_ptr**, memory is allocated on the heap for an instance of data type. In **unique_ptr** we have only one owner of the object and it will automatically deallocated when it goes to **out of scope**.

            - Only one **smart pointer** can own the object at time.
            - Automatically deletes the object when it goes out of scope.
            - Not copyable, only movable.

                ![](https://media.geeksforgeeks.org/wp-content/uploads/20191202223147/uniquePtr.png)
            ```

            ```
        2. #### `shared_ptr`
        > Hello
        
            ```

            ```
        3. #### `weak_ptr`
            ```

            ```



