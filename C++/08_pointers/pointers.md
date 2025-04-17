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
```
int num = 11;

cout << &num <<endl; // We get memory address


int x = 55;
int* ptr = &x;

cout << x <<endl; // Memory address of variable x.
```
## 🪄 Dereferencing
> It is a process to access the value present at the memory address pointed by the pointer is called **`dereferencing`**.
```
int x = 55;
int* ptr = &x;

cout << *ptr << endl; // This is called dereferencing.
cout << ptr <<endl; // We got memory address where why point.
```
* **`Example`**

    ![Pointer Example](https://media.geeksforgeeks.org/wp-content/uploads/pointers-in-c.png)


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
    
    1. #### **`Wild Pointer`**

        > When pointer is created, and we does not assign variable on it. it just contains random memory address that may or may not be valid. this type of pointers are called as **`wind pointer`**. **NOT RECOMMENDED**
        
        * **`Example`**

        ```
        int* ptr;
        ```
    
    2. #### **`NULL Pointer`**

        > A **`NULL Pointer`** is a pointer that does not point to any valid memory location but NULL. If is Often used to initialize pointer.

        * **`Example`**

        ```
        int* ptr = NULL
        
        // OR

        int* ptr = nullptr;
        ```
    3. #### **`Void Pointer`**

        > The void pointer is a *special type* of pointer in C++. Which represent the absence of type. **`Void Pointer`** are pointer that point to the value that has no particular type. It can be point to any data type.

        > So the Datatype is does not know. the compiler also does not know how many bytes to access when the void pointer dereferenced. So compiler have to first convert it into other pointer type that points to concrete data type.

        * It is most commonly used in dynamic memory allocation. when we does not know about the type.
        * **Generic Coding** Where we have single pointer used for many variable.
        * **`static_cast<source_type>(source)`** It used to convert from other type of another type. it is done in **compile time**.


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

    4. #### **`Dangling`**
        > In C++, A Pointer that point to the memory location that has been deallocated earlier in the program is called **`Dangling`**.
        * **Cases that leads to dangling Pointer in C++**
            * Deallocation of Memory using delete or free().
            * Referencing the Local Variable of the function after it is executed.
            * Variable goes out of scope.
        * **Note**
            
            * Memory Deallocation only applicable when memory is created dynamically.
            * When memory is created dynamically it does not deallocate automatically we have to free it manually.
            * **There are may way to allocate memory dynamically.**
                * Using `new` --> Reference in **`/additional/new.cpp`**
                * Using `malloc`, `calloc`, `realloc`
                * Using Smart Pointer
                * Using Custom memory Allocator(Advanced)
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
            ![](https://media.geeksforgeeks.org/wp-content/uploads/20240514121236/Dangling-Pointer-in-Programming.webp)


