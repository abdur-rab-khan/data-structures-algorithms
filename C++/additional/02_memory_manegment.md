# 🧠 Memory Management
 > A memory management is a process of managing computer memory. It involves the allocation, use, and deallocation of memory resources in a computer system.

### 📅 Table of content
- [1. 💻 Static Memory Management](#1-💻-static-memory-management)
- [2. 💽 Dynamic Memory Management](#2-💽-dynamic-memory-management)
    - [1. 📦 `new`](#1-📦-new)
    - [2. 🗑️ `delete`](#2-🗑️-delete)
- [⛔ Errors associated with Dynamic Memory](#⛔-errors-associated-with-dynamic-memory)
    - [Memory Leak](#memory-leak)


 * There are two types of memory management in C++:
    * [Static Memory Management](#static-memory-management): Memory is allocated at compile time.
    * [Dynamic Memory Management](#dynamic-memory-management): Memory is allocated at runtime using pointers.

## 1. 💻 Static Memory Management
> Static memory is allocated for a variable declared by the compiler. It use **stack** instead of **heap**.

* It is done at the compiler time (before running the code).
* Once memory is allocated the size cannot be resize.
* Once scope is end is automatically deallocated.
* It is faster then dynamic memory allocation.

## 2. 💽 Dynamic Memory Management
> When a variable defined in a function is store in the stack. The requirement to store into the memory is know the **size**, and **type** of the data at the compiler time.

> Also once defined we can't neither change the size nor completely delete the memory. To solve this in C++, We have **Dynamic Memory Allocation**.

> It allow to allocate memory at run time. That allow us to handle varying size. Dynamic resources are store into **heap** instead of stack.

* ***Note***
    * ***Here memory is not deallocated automatically we have to free manually using `delete` keyword. It reserved into the memory until we delete it.***

* What is the need of **Dynamic Memory Allocation**
    1. In the array, If we does not know about the size of an array it can be increase in future. So one solution came to our mind is add the max size of the array. But it is not a good solution because it waste the memory.
    2. In **Dynamic Memory Allocation** the size of an array can be increased if more elements are to inserted or decreased. there are no need to estimate the max possible size.
---
* Dynamic memory allocation is possible in C++.
    1. [`new`](#1-📦-new)
    2. [`delete`](#2-🗑️-delete)

### 1. 📦 `new`
> In C++, The preferred way to allocate memory `dynamically` is using new operator. `new` operator request compiler to allocate block of memory of the give size of type on the **Free Store** (Part of `heap` memory available for new operator).

> If sufficient memory is available, new operator initialize the memory to the default value according to its type and returns the address to this newly allocated memory.

* **Syntax**
    ```cpp
    new data_type;
    ```
    * In the above statement, the memory block that can store a single value of give **data_type** is reserver with random value(according to type) in the heap memory and return the **address** of location.

* **Example**
    ```cpp
    #include<iostream>
    using namespace std;
    
    int main(){
        // Declare a point to store memory address
        int *ptr;
    
        ptr = new int[5]{1,2,3,4,5};
    
        // Printing
        for(int i = 0; i < 5; i++){
            // cout << *(ptr + i) << endl;
            // OR
            cout << ptr[i] << endl;
        }
        return 0;
    }
    ```

    ### ⚠️ What happen if enough memory is not available.
    > If enough memory is not available in the heap. and we try to allocate memory then cause exception called **`std::bad_alloc`**. unless `nothrow` is used with the new operator, in this cause it return `nullptr`.
    
    * **Example**
        ```cpp
        #include<iostream>
        using namespace std;
    
        int main(){
            int *ptr = new (nothrow) int;
    
            if(!ptr){
                cout << "Memory allocation failed\n" << endl;
            }
            return 0;
        }
        ```


### 2. 🗑️ `delete`
> In C++, `delete` operator is used to deallocate dynamically allocated memory.

* **Syntax**
    ```cpp
    delete ptr; // If single int;
    delete[] arr; // If array;
    ```

* **Example**
    ```cpp
    #include<iostream>
    using namespace std;
    
    int main(){
        int* ptr = new int(56);

        cout << "Value of ptr " << *ptr << endl;

        // Free once use it
        delete ptr;

        int* ptr = new int[5];

        ptr[0] = 11;
        *(ptr + 1) = 22;
        ptr[2] = 33;
        ptr[3] = 44;
        ptr[4] = 55;
        ptr[5] = 66;

        cout << "Array: ";
        for(int i = 0; i < 5; i++){
            cout << ptr[i] << endl;
        }

        // Deallocate when already use it.
        delete[] ptr;        
        return 0;
    }
    ```


## ⛔ Errors associated with Dynamic Memory
### Memory Leak
> Memory leak is a situation where the memory allocated for a particular task remains allocated even after it is not longer needed. If the address to the memory is lost, then it will remain allocated till the program runs.

* Common causes of Memory Leak
    1. **Forget to free**
        * When dynamically allocated memory is not freed up by calling free then it leads to memory leaks.
        * Always remember every time when you create dynamic memory allocation you have to free after using it.
    2. **Losing Pointer**
        * When program changing the pointer pointed to memory location and we forget to free it can cause memory leaks.
    3. **Abnormal Termination**
        * When the function or some other part of the program terminate abnormally, and the allocation is not need than it can cause memory lead.
* How to avoid memory leaks
    1. **Pairwise allocation and deallocation**
        * Always ensure the corresponding **free()** is present for each dynamically allocated memory block once it is no longer needed.
    2. **Handle Abnormal Terminologies**
        * Make sure we have to handle abnormal terminologies.
    3. **Use memory analysis Tools**
        * Use tools like **Valgrind** and **AddressSanitizer** can help detect memory leaks by analysing a program’s memory usage during runtime.
    4. **Code reviews**
        * Regular code reviews and static analysis tools can help spot potential issues related to memory management.
    5. **Avoid unnecessary allocation**
        * Only allocate memory when necessary and ensure that every allocation has a corresponding deallocation.