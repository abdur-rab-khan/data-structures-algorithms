### **Table of content**

- [🪞 Reference](#-reference)
  - [🧑🏻‍💻 Example](#-example)
- [💽 Pointer](#-pointer)
    - [1. Wild Pointer](#1-wild-pointer)
      - [2. `NULL Pointer`](#2-null-pointer)
      - [3. `Void Pointer`](#3-void-pointer)
    - [3. `Dangling`](#3-dangling)
      - [3. `Double Pointer`](#3-double-pointer)

---

# 🪞 Reference
>
> The `reference` is the alias of another variable. It is not a copy but another name for existing one.

- ***For more refer from [AND](../additional//use_of_&.md).***

## 🧑🏻‍💻 Example

```cpp
int num = 55;
int& ref = num;

cout << ref <<endl; // 55
cout << num << endl; // 55

ref = 66;

cout << ref <<endl; // 66
cout << num <<endl; // 66
```

- `ref` refer to `num`.

- Changes on `ref` can also effect to `num` and `vise-versa`.

# 💽 Pointer
>
> The `Pointer` is used to store the memory address of the given variable. To get memory address we use **`&`** Operator.

- **The size of the pointer is equal for every pointer. not matter way system and what type.**
  - **8 Byte** for a **64-bit System**.
  - **4 Byte** for a **32-bit System**.
- In C++, When we create variable a memory address is assigned to the variable. And when assign value to the variable, it stored in the memory address.
  - A **`pointer`** is a variable that store the memory address as its value. We can't store memory address directly.
  - A **`pointer`** variable points to a data type (like `int`, `string`) of the same type. and is created using **`*`** operator.

- ## 🧑🏻‍💻 Example

    ![Pointer Example](https://media.geeksforgeeks.org/wp-content/uploads/pointers-in-c.png)

    ```cpp
    int num = 11;

    cout << &num <<endl; // We get memory address


    int x = 55;
    int* ptr = &x;

    cout << x <<endl; // Memory address of variable x.
    ```

- ## 🪄 Dereferencing
  >
    > It is a process to access the value present at the memory address pointed by the pointer is called **`dereferencing`**.
  - **`Example`**

        ```cpp
        int x = 55;
        int* ptr = &x;

        cout << *ptr << endl; // This is called dereferencing.
        cout << ptr <<endl; // Get Memory address of x.
        ```

- ## Modify Address
  >
    > This Memory address can be modified to point another memory location if it's data type is same.

- **`Example`**

    ```cpp
    int x = 55
    int* ptr = &x;

    cout << *ptr <<endl; // 5

    int a = 12;

    ptr = &a;

    cout << *ptr <<endl; // 12
    ```

- ## 📃 Types of Pointers

  - There are 7 types of **pointers**.

    1. `Wild Pointer`
    2. `NULL Pointer`
    3. `Void Pointer`
    4. `Dangling Pointer`
    5. `Double Pointer`
    6. `Pointer to a function`
    7. `Smart Pointer`

### 1. Wild Pointer

> When pointer is created, and we does not assign   variable on it. it just contains random memory    address that may or may not be valid. this type    of pointers are called as **`wind pointer`**.  **NOT RECOMMENDED**

- **`Example`**

    ```cpp
    int* ptr;
    ```

#### 2. `NULL Pointer`

> A **`NULL Pointer`** is a pointer that does not   point to any valid memory location but NULL. If   is Often used to initialize pointer.

- **`Example`**

    ```cpp
    int* ptr = NULL

    // OR

    int* ptr = nullptr;
    ```

#### 3. `Void Pointer`

> The void pointer is a ***special type*** of   pointer in C++. Which represent the absence of    type. **`Void Pointer`** are pointer that point    to the value that has no particular type. It can   be point to any data type.

> So the Datatype is does not known. the compiler also does not know how many bytes to access when   the void pointer dereferenced. So compiler have   to first convert it into other pointer type that  points to concrete data type. To do this we can  use **`static_cast<source_type>(source)`** to say    the compiler how many bytes you have to access.

- **Applications of `void pointer`**
    1. It is most commonly used in dynamic memory allocation. when we does not know about the type.
    2. **Generic Coding** Where we have single pointer used for many variable.
    3. **`static_cast<source_type>(source)`** It used to convert from other type of another type. it is done in **compile time**. If want to cast pointer **`static_cast<source_type*>(source)`** **OR** **`(int*)address`**.

- **Example**

    ```cpp
    int x = 55;
    int* ptr = &x;

    cout << "In this memory address:- " << ptr << "we have:- " << *ptr << endl;

    float y = 20.3;
    // ptr = &y; // It cause error here

    void* address = nullptr;
    int num = 121;
    float sal = 2000.50;
    char grade = 'A';

    address = &num;
    cout << endl;
    cout << "The value of num is:- " << * (static_cast<int*>      (address)) << endl;
        cout << "The Address of num is:- " << address  <<endl;
        
    address = &sal;
    cout << "The value of sal is:- " << * (static_cast<float*>        (address)) << endl;
    cout << "The Address of sal is:- " << static_cast<float*>     (address) << endl;
        
    address = &grade;
    cout << "The value of sal is:- " << * (static_cast<char*>     (address)) << endl;
    cout << "The Address of sal is:- " << address  <<endl;
    ```

    ```cpp
    enum class TypeData {
        I,
        D,
    };

    void CallbackFunction(void* data, TypeData  dataType) {
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

    void performOperation(void* data, TypeData  dataType, void (*callback)(void*, TypeData)) {
            callback(data, dataType);
    }

    int main(){
        int num = 121;
        double doubleValue = 121.21151131;
        performOperation(&num, TypeData::I, CallbackFunction);
        performOperation(&doubleValueTypeData::D,   CallbackFunction);

        return 0;
    }
    ```

### 3. `Dangling`

> In C++, A Pointer that point to the memory    location that has been deallocated earlier in the  program is called **`Dangling`**.

- **Cases that leads to dangling Pointer in C++**
    1. Deallocation of Memory using delete or free   ().
    2. Referencing the Local Variable of the     function after it is executed.
    3. Variable goes out of scope.

- **Note**
- Memory Deallocation only applicable when memory is created dynamically.
  - When memory is created dynamically it does not deallocate automatically we have to free it manually.
  - **There are may way to allocate memory dynamically.**
        1. Reference **[Memory Management](../additional/memory_manegment.md)**
        2. Using `new`
        3. Using `malloc`, `calloc`, `realloc`
        4. Using Smart Pointer
        5. Using Custom memory Allocator (Advanced)

    ![Dangling Pointer](https://media.geeksforgeeks.org/wp-content/uploads/20240514121236/Dangling-Pointer-in-Programming.webp)

- **`Example:-`**

    ```cpp
    int* num = new int(11);
    cout << "Value is::- " << *num << endl; // 11
    delete ptr // Here ptr become dangling  pointer --> They point memory location but   inside the memory location we does not have   anything (random value).
    cout << *num << endl; // --> Random Value
    ```

  - What Happen Here???
    - After function is executed the num   variable getting freed.
    - In the main function when we try to access   getting error.

    ```cpp

    int* getDanglingPointer() {
        int num = 42;

            return &num;
        }

        int main(){
            int* danglingPtr = getDanglingPointer   (); // Getting Error

            cout << danglingPtr << endl;
        }

        // SOLUTION!!!
        // Use Dynamic Approach to initialize the   variable.

        int* getDanglingPointer(){
            // You can choose any approach from ⬇️
            static int num = 42; --> return 42
            int* num = new int(42); --> return Address
            int* num = (int*)malloc(sizeof(int)); -->   return Address;
            num = 42

            return num;
        }
    ```

#### 3. `Double Pointer`

> **`Double Pointer`** is a special type of     pointer, that point to the another pointer (also    known as pointer to pointer). It is useful when    working with multi-level data structure like   array of pointer or dynamic memory management.

- **Note**
  - The size of the double pointer are totally    depend upon the machine, Like CPU  architecture and OS used.
    - For 64-bit OS pointer will be 8 bytes.
    - For 32-bit OS pointer will be 4 bytes.

        ![Double Pointer](https://media.geeksforgeeks.org/wp-content/uploads/20221111110818/DoublePointer.png)

- **Example**

    ```cpp
    void allocate(int** ptr) {
    *ptr = new int;  // Allocates memory for    an integer and stores the address in the   pointer
    **ptr = 42;      // Dereferences twice to   store the value 45 in the allocated memory
    }

    int main() {
        // Modify pointer inside function.
        int* p = nullptr;
        allocate(&p);
        cout << *p << endl;

        void* ptr = nullptr;
        void** doublePointer = &ptr;  // Address    of ptr

        cout << "Initial ptr (nullptr): " <<    *doublePointer
                << endl;  // Getting the value     inside ptr. --> 0

        *doublePointer = new int;
        *(static_cast<int*>(*doublePointer)) = 50;

        cout << "Value at int ptr: " << *   (static_cast<int*>(ptr)) << endl;

        delete static_cast<int*>(ptr);  // Free     the memory to prevent memory leak

        *doublePointer = new float;
        *((float*)ptr) = 50.50;

        cout << "Value at float ptr: " << * (static_cast<float*>(ptr)) << endl;

        delete static_cast<float*>(ptr);  //    Clean up

        return 0;
    }
    ```

  - **Draw a Matrix**

    ```cpp
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

    delete[] matrix;  // delete the array of    pointers

    ```

- **Concept Diagram**

    ```mermaid
    flowchart TD
    A["matrix (int**)"] --> B["matrix[0]"]
    A --> C["matrix[1]"]
    A --> D["matrix[2]"]

    subgraph Heap Memory
        B --> B1[int]
        B --> B2[int]
        B --> B3[int]
        B --> B4[int]

        C --> C1[int]
        C --> C2[int]
        C --> C3[int]
        C --> C4[int]

        D --> D1[int]
        D --> D2[int]
        D --> D3[int]
        D --> D4[int]
    end
    ```

1. #### `Pointer to functions`

> Similar to normal **Pointer** that are used to    point to variables. **`Pointer to functions`**     are used to store the memory address of a   function. Function pointer can also used to call  function indirectly, Or they can also used to    build **Higher Order Function**.

- **Note**
  - Function pointer is used to point function,   similarly, the pointers are used to pointer   variable.
  - It utilized to save a function's address.
  - The function pointer is either used to call   the function or it can be send an argument to     another function.

    ![Pointer to functions](https://media.geeksforgeeks.org/wp-content/uploads/20221221122225/Function-Pointer-768.png)

    - ### Referencing and Dereferencing
  
    > Similar to pointer variable we can perform    both Referencing and Dereferencing with a **function pointer**.
    - Referencing
        > When pointer is allocated the address     of the function to be the associated with   it them this process is called    **`referencing`**.

    - Dereferencing
        > When we use the **`*`** operator to get   the value of the pointer.

    - **Syntax**

        ```cpp
        // Declaring
        return_type (*FuncPtr) (parameter   type, ....); 
    
        // Referencing
        FuncPtr= function_name;
    
        // Dereferencing
        data_type x=*FuncPtr;
        ```

    - **Example**

        ```cpp
        int main() {
            int (*ptr)(int, int) =  multiply;

            // Count function does not know how to print function pointer that is the reason they can't
                
            printf("Memory Address of this function:-   %p", ptr);
            cout << endl << "Memory Address of this         function:- " << (int*)ptr << endl;
            cout << "Memory Address of this function:- " << reinterpret_cast<void*> (ptr) << endl << endl;
    
            cout << "The Multiplication of 2 x 2 is:-   " << ptr(2, 2) << endl;

            return 0;
        }
        ```

      - **Build Higher Order Function**

            ```cpp
            int multiply(int a, int b) {
                return a * b;
            };

            int performer(int a, int b, int (*func)(int,    int)) {
                return func(a, b);
            }

            int main() {
                int (*funcPtr)(int, int) = multiply;

                cout << "The Multiplication of 4 x 4 is:-   " << performer(4, 4, funcPtr) << endl;

                // Using std::function with lambda
                function<int(int, int)> func;

                func = multiply;

                cout << func(10, 10) << endl;

                return 0;
            }
            ```

      - Array of functions

        ```cpp
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

1. #### `Smart Pointers`

> A **Smart Pointer** is a wrapper class over a     pointer with an operator like **`*`** or    **`->`**. The Object of the **smart pointer** are  look like normal pointer. But ***Unlike Normal   Pointer***, It can automatically allocated and    deallocate the memory location.

> To build Smart Pointer we some C++    functionality like [Destructor](<https://www>.   geeksforgeeks.org/destructors-c/) and [Overloaded  Operator](<https://www.geeksforgeeks.org/> operator-overloading-c/). **Destructor** is  automatically call when object is going to out of    scope. We call there to free the memory.

> Smart pointers enable automatic memory    management on heap memory to help avoid memory     leaks. Think of them as pointers with automatic     memory cleanup.

- **Own version of Smart Pointer**

    ```cpp
    #include <iostream>
    using namespace std;

    class SmartPointer {
        public:
        int* ptr = nullptr;
        explicit SmartPointer(int* p = nullptr) { ptr   = p; }

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

    > When we initialize **unique_ptr**, memory is  allocated on the heap for an instance of data    type. In **unique_ptr** we have only one owner of  the object and it will automatically deallocated     when it goes to **out of scope**.

    - Only one **smart pointer** can own the object     at time.
    - Automatically deletes the object when it goes     out of scope.
    - Not copyable, only movable.

    ![unique-ptr](https://media.geeksforgeeks.org/wp-content/uploads/20191202223147/uniquePtr.png)

    ```cpp
    class Car1 {
        public:
        void drive() { cout << "Drawing the Car"    <<  endl; }
    };

    int main(){
        // unique_ptr
        // unique_ptr<Car> carPtr =     make_unique<Car>();
        unique_ptr<Car1> carPtr(new Car1);

        cout << "Memory Address is:- " << carPtr.   get()   << endl;

        carPtr->drive();
        // unique_ptr<Car> copyCarPtr = carPtr; ❌  Error:  can't copy
        unique_ptr<Car1> copyCarPtr = move  (carPtr);  // ✅    Ownership transferred
        carPtr->drive();
        copyCarPtr->drive();

        // With Basic Data Type
        unique_ptr<int> num = make_unique<int>  (54);

        cout << *(num.get()) << endl;
        cout << *num << endl;
    }
    ```

    2. #### `shared_ptr`

    > By using **`shared_ptr`** we can pointer more     than one object at a time. and it will maintain a   Reference Counter using **`use_count`** method

    > The reference counter shared among all the    copies of the **`shared_ptr`** instance pointing   to the same object, ensuring proper memory    management and deletion.

    ![shared-ptr](https://media.geeksforgeeks.org/wp-content/uploads/20191202231341/shared_ptr.png)

    - **Example**

        ```cpp
        class File {
            public:
            void open() { cout << "File is  opened" <<  endl; }};

        int main() {
            // unique_ptr
            // unique_ptr<Car> carPtr =     make_unique<Car>();
            unique_ptr<Car> carPtr(new Car);

            cout << "Memory Address is:- " << carPtr.   get()   << endl;

            carPtr->drive();
            // unique_ptr<Car> copyCarPtr = carPtr; ❌  Error:  can't copy
            unique_ptr<Car> copyCarPtr = move   (carPtr);  // ✅    Ownership                 transferred
            carPtr->drive();
            copyCarPtr->drive();

            // With Basic Data Type
            unique_ptr<int> num = make_unique<int>  (54);

            cout << *(num.get()) << endl;
            cout << *num << endl;

            // shared_pointer
            // shared_ptr<File> f1 = make_shared<File>  ();
            shared_ptr<File> f1(new File);
            f1->open();

            shared_ptr<File> f2 = f1;
            f2->open();

            cout << "Address of f2:- " << f2.get() <<   endl;
            cout << "Reference Count:- " << f2. use_count() <<  endl;

            return 0;
        }
        ```

    - Implement Swapping

        ```cpp
        int main() {
            shared_ptr<int> num1 = make_shared<int> (42);
            shared_ptr<int> num2 = make_shared<int> (52);

            shared_ptr<int> num3 = num1;

            if (*num1 == *num3) {  // True
                cout << "Both num1 and num2 shared same memory address." << endl;
            }

            cout << "Before swapping" << endl;
            cout << "Value of num2 is:- " << *num2 << endl;
            cout << "Value of num3 is:- " << *num3 << endl;

            num2.swap(num3);

            cout << "After swapping" << endl;
            cout << "Value of num2 is:- " << *num2 << endl;
            cout << "Value of num3 is:- " << *num3 << endl;

            return 0;
        }
        ```

      - **Some Important Methods**

        | Method | Description |
        |--------|-------------|
        | **`reset`** |Reset **shared_ptr** to empty |
        | **`use_count`** | Returns the current     reference   count |
        | **`unique`** | Return 1, If there is only     one     owning the **`ptr`** |
        | **`get`** | Return a raw pointer to manage    the     object |
        | **`swap(given_ptr)`** | swap the ownership    of  given ptr instance |

    3. #### `weak_ptr`
 
    > **`weak_ptr`** is just like shared ptr, It    has capability to point to the resource owned  by another shared_ptr but without owning it. In other words, they are able to create a    non-owning reference to the object managed by  shared_ptr. You can use when you want to     give. Whenever you want to access the   weak_ptr value you have to always use **`ptr. lock()`**.

    > It only works with **`shared_ptr`**.

    ![Weak Pointer](https://media.geeksforgeeks.org/wp-content/uploads/20191202233339/weakPtr.png)

- **Example**

```cpp
int main(){
shared_ptr<int> number1 =   make_shared<int>(55);
shared_ptr<int> number2 = number1;

cout << "Reference count:- " <<     number1.use_count() << endl;
cout << "Both number1 and number2   address:- " << number1 << "   "   <<          number2 << endl;

weak_ptr<int> number3 = number1;

cout << "Reference count:- " <<     number1.use_count()
        << endl;  // 2 instead of 3    because it does not own it.

if (auto temp = number3.lock()) {
    cout << "Value of number 3 is:- "   << *temp << endl;
}

return 0;
}
```

```cpp
class Car;

class Owner {
public:
string owner_name = "Abdur Rab Khan";
shared_ptr<Car> car = make_shared<Car>   ();

~Owner() { cout << "Car is destroyed"   << endl; }
};

class Car {
public:
// shared_ptr<Owner> owner =    make_shared<Owner>();
weak_ptr<Owner> owner;  // --> By   using this we only share                  resource instead of owning it.

string get_owner_name(){
                            if(auto temp = owner.lock()){
                                return temp->owner_name;
                            }
                        }
    
                        ~Car() { cout << "Owner is destroyed"   << endl; }
                    };
    
                    int main(){
                        std::shared_ptr<Owner> p =  std::make_shared<Owner>();
                        std::shared_ptr<Car> c =    std::make_shared<Car>();
    
                        p->car = c;
                        c->owner = p;
    
                        cout << "Owner name is:- " <<   p->get_owner_name() << endl;
    
                        return 0;
                    }
                    ```

                    - **Behind the scenes**
                        - In the **above** example, if we   does not use **`weak_ptr`**.
                            - **Circular Reference** Problem    Occur:
                                - When we create **`p`**, the   **`shared_ptr`** creates a    **`control block`** with:
                                    - A **`reference count`**.
                                    - A Pointer to actual   Object **`Owner`**.
                                - Same for **`c`** also.

                            - **Now:**
                                - **`p`** point to  **`Person`**, and it owns    **`c's`** --> so reference     count becomes 2(1 from  **`main`**, 1 from   `c->owner`).
                                - `c` point back to `p` using   another `shared_ptr` -> now   `p's` reference count becomes     2(1 `main`, 1 from  `c->owner`).

                          ### **🧠 What’s the issue?**

                            When main ends:
                            - `p` and `c` go out of scope.
                            - But their reference counts are    still 1, because they point to     each other.
                            - So the memory is never    deallocated — and you get a    memory leak.

                        - If we use **`weak_ptr`**.
                            - A `weak_ptr` does not increase    the reference count.
                            - It uses the same control block    as the shared_ptr, but it has its  own weak count.

                            - So now:
                                - p’s reference count is 1  (from main)
                                - c’s reference count is 1  (from p->car)
                               - And the weak reference     (c->owner) doesn't affect this  count.

                            - When main ends:
                                - p and c go out of scope.
                                - Their reference counts drop   to 0.
                                - So both Person and Car    objects are properly *     destroyed.
                                - Even though c->owner (a   weak_ptr) still exists, it    doesn’t keep the object alive.
                - **Example**

                    ```cpp
                    #include <iostream>
                    #include <memory>
                    #include <vector>
                    using namespace std;
                    
                    class WithoutSmartPtr {
                       public: 
                        int** marks = nullptr;
                        int total_student = 0;
                        int total_subject = 5;
                    
                        WithoutSmartPtr(int total_student) {
                            cout << "Without using Smart    Pointer" << endl << endl;
                            ;
                            this->total_student =   total_student;
                            marks = new int*[total_student];
                        }
                    
                        void add_marks() {
                            int mark = 0;
                    
                            for (int i = 0; i <     total_student; i++) {
                                marks[i] = new int  [total_subject];
                                cout << "Enter Student " << i   + 1 << " marks " << endl;
                    
                                for (int j = 0; j <     total_subject; j++) {
                                    cout << "Enter you  marks:- ";
                                    cin >> mark;
                    
                                    marks[i][j] = mark;
                                }
                            }
                        }
                    
                        void display_marks() {
                            for (int i = 0; i <     total_student; i++) {
                                cout << "Student " << i + 1     << " marks:- ";
                    
                                for (int j = 0; j <     total_subject; j++) {
                                    cout << marks[i][j] << "    ";
                                }
                    
                                cout << endl;
                            }
                        }
                    
                        ~WithoutSmartPtr() {
                            for (int i = 0; i <     total_student; i++) {
                                delete[] marks[i];
                            }
                    
                            delete[] marks;
                        }
                    };
                    
                    class WithSmartPtr {
                       public:
                        vector<vector<int>> marks;
                        int total_student = 0;
                        int total_subject = 5;
                    
                        WithSmartPtr(int total_student) {
                            cout << "With using Smart   Pointer" << endl << endl;
                            this->total_student =   total_student;
                            marks.resize(total_student,     vector<int>(total_subject));
                        }
                    
                        void add_marks() {
                            for (int i = 0; i <     total_student; i++) {
                                cout << "Enter Student " << i   + 1 << " marks " << endl;
                    
                                for (int j = 0; j <     total_subject; j++) {
                                    cout << "Enter you  marks:- ";
                                    cin >> marks[i][j];
                                }
                            }
                        }
                    
                        void display_marks() {
                            for (int i = 0; i <     total_student; i++) {
                                cout << "Student " << i + 1     << " marks:- ";
                    
                                for (int j = 0; j <     total_subject; j++) {
                                    cout << marks[i][j] << "    ";
                                }
                    
                                cout << endl;
                            }
                        }
                    };
    
                    int main() {
                        // Building a small system that     stores the marks of students. The   number of students is not
                        // fixed — it is decided at runtime.
    
                        // Without Smart Pointer
                        WithoutSmartPtr wsp = WithoutSmartPtr   (2);
                        wsp.add_marks();
                        wsp.display_marks();
    
                        // With Smart Pointer
                        WithSmartPtr spt = WithSmartPtr(2);
                        spt.add_marks();
                        spt.display_marks();
                        return 0;
                    }
                    ```
