# Vector in C++

> Vector in C++ is a dynamic array that store collection of elements same datatype in contiguous memory location. It has the ability to resize itself automatically when an element is inserted or deleted.

- [Vector in C++](#vector-in-c)
  - [Creating a Vector](#creating-a-vector)
  - [Basic Operations on Vector](#basic-operations-on-vector)
    - [1. Insert Elements](#1-insert-elements)
    - [2. Retrieve Elements](#2-retrieve-elements)
    - [3. Find Size](#3-find-size)
    - [4. Traverse Vector](#4-traverse-vector)
    - [5. Delete Elements](#5-delete-elements)
  - [Passing Vector to a function in C++](#passing-vector-to-a-function-in-c)
    - [1. Pass Vector by Value](#1-pass-vector-by-value)
    - [2. Pass Vector by Reference](#2-pass-vector-by-reference)
    - [3. Pass Vector by Pointer](#3-pass-vector-by-pointer)
  - [Member function of vector](#member-function-of-vector)

## Creating a Vector

```cpp
vector<T> v; // Where T specify the type of vector elements.
```

- `vector` is defined as the `std::vector` class template in the `vector` header file.
- Let's creating instance of `std::vector` class.

    ```cpp
    #include<iostream>

    using namespace std;

    int main(){
        // Creating a empty vector
        vector<int> v;

        // We can directly store value in the vector using curly braces {}
        vector<int> v1 = {1, 2, 3, 4, 5, 6};

        // Creating vector of 5 element with default value (9)
        vector<int> v2(9, 5);

        // Creating vector from another vector
        vector<int> v3(v2.begin(), v2.end());

        // Initialize vector and fill with 11
        vector<int> v4(5);

        v4.fill(v4.begin(), v4.end(), 11);

        // Creating using arr
        int arr[] num = {11, 22, 33, 44};
        int n = sizeof(arr) / sizeof(arr[0]);
        
        vector<int> vnum = {arr, arr + n};
        
        return 0;
    }
    ```

## Basic Operations on Vector

### 1. Insert Elements

- An element can be insert at the start by using `vector insert()` which takes linear time.
- To insert at the end we use `vector push_back()` which is very fast as take only constant time.

    ```cpp
    #include<iostream> 
    #include<vector>

    using namespace std;

    int main(){
        vector<char> firstName = {'a', 'd', 'u'};

        // Insert at the end of firstName
        firstName.push_back('r');


        // Insert at first index, firstName.begin() represent 0 index + 1 means 0 + 1 = 1
        firstName.insert(firstName.begin() + 1, 'b');

        for(int i = 0; i < firstName.size(); i++) cout << firstName[i]; // abdur

        return 0;
    }
    ```

- There are many more way to insert, you can see from [**here**](https://www.geeksforgeeks.org/cpp/how-to-add-elements-in-a-vector-in-cpp/).

### 2. Retrieve Elements

- Just like in array we can access vector element by using **`[]`** operator, and we can change by using assignment operator **`=`**.
- There is major problem with **`[]`** operator, it does not check whether element exits at that index in vector or not.
- To solve this problem we can use **`.at()`** operator in vector, for safely access or update elements

    ```cpp
    #include<iostream>
    #include<vector>

    using namespace std;

    int main(){

        return 0;
    }
    ```

### 3. Find Size

- Vector provide simple method to find there size, to find we use **`v.size()`**.

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    
    int main() {
        vector<char> v = {'a', 'c', 'f', 'd', 'z'};
    
        // Finding size
        cout << v.size();
    
        return 0;
    }
    ```

### 4. Traverse Vector

- To traverse on vector we can either use loop by finding there size using `vector.size()` method, or we can use `forEach` loop.

    ```cpp
    #include<iostream>
    #include<vector>

    using namespace std;

    int main(){
        // <==============> Traversing on Vector <==============>
        // Using ForLoop
        for (int i = 0; i < sample.size(); i++)
            cout << sample[i];
        cout << endl << endl;
    
        // Using ForEach
        for (const auto c : sample)
            cout << c;
        cout << endl << endl;
    
        // Reverse Traversing
        for (auto it = sample.rbegin(); it != sample.rend(); ++it) {
            cout << *(it);
        }
        cout << endl << endl;

        return 0;
    }
    ```

### 5. Delete Elements

- Deletion on vector can perform using `.erase()` method but this method need to iterator to perform deletion, it is used to perform delete at any specific position by using iterator.
- There is build in method called `find` which is use to find position of element and it return iterator, we can use this with `.eraser()`.
- Delete at the end, is done by using **`.pop()`** method and it's very faster and take constant time.

    ```cpp
    #include<iostream>
    #include<vector>

    using namespace std;

    int main(){
        // <==============> Deletion on Vector <==============>
        sample.pop_back();  // abcdf
    
        // Deleting element 'f'
        sample.erase(find(sample.begin(), sample.end(), 'f'));  // abcd
    
        for (const auto c : sample)
            cout << c;
        cout << endl << endl;
    
        return 0;
    }
    ```

## Passing Vector to a function in C++

- We often pass vector to the function to perform certain operations on them or by using them, we pass this vector to the function as arguments during the function call.
- C++ provides three method to pass vector to a function, Let's see all of them.
    1. **Pass Vector by Value**
    2. **Pass Vector by Reference**
    3. **Pass Vector by Pointer**

### 1. Pass Vector by Value

- The **pass vector by value** method is simplest method to pass any vector to a function. The method create a copy of original vector, therefore modification done on inside the function and prevent to modify original one.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // Pass by value
    void foo(vector<int> vec) {
    
        // Modifying vector inside function
        vec.push_back(8);
        for (auto i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    int main() {
        vector<int> v = {1, 3, 7, 9};
    
        // Passing the vector to foo()
        foo(v);
    
        for (auto i : v)
            cout << i << " ";
        return 0;
    }
    ```

### 2. Pass Vector by Reference

- The **pass by reference** method pass the reference of the vector to the function.
- it does not create copy of original vector therefore, all modification on vector in function can also reflect on original vector.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // Pass by reference
    void foo(vector<int> &vec) {
    
        // Modifying the vector
        vec.push_back(8);
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }
    
    int main() {
    
        vector<int> v = {1, 3, 7, 9};
    
        // Pass the vector to foo()
        foo(v);
    
        for (auto i : v)
            cout << i << " ";
        return 0;
    }
    ```

- If you want to pass vector as a reference, but at a time you want to prevent from modification on original one, you can use **`const`**
- It avoids unnecessary copying while ensuring the original vector remains unchanged.

### 3. Pass Vector by Pointer

- The **pass vector by pointer** is similar as **pass vector as reference**, but instead of reference, we pass the memory address of vector to the function.

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // Pass by pointer
    void foo(vector<int> *ptr) {
    
        // Modify the original vector
        ptr->push_back(8);
        for (int i = 0; i < ptr->size(); i++) {
        cout << ptr->at(i) << " ";
        }
        cout << endl;
    }
    
    int main() {
        vector<int> v = {1, 3, 7, 9};
    
        // Passing address of the vector to foo()
        foo(&v);
    
        for (auto i : v)
            cout << i << " ";
        return 0;
    }
    ```

- This method is not recommended as it brings the error and risks associated with pointers

## Member function of vector

- Following are the list of member function of **`std::vector`** class in C++:

| Function | Description |
|----------|-------------|
| `push_back()` | Adds an element to the end of the vector. |
| `pop_back()` | Removes the last element of the vector. |
| `size()` | Returns the number of elements in the vector. |
| `max_size()` | Returns the maximum number of elements that the vector can hold. |
| `resize()` | Changes the size of the vector. |
| `empty()` | Checks if the vector is empty. |
| `operator[]` | Accesses the element at a specific position. |
| `at()` | Accesses the element at a specific position, with bounds checking. |
| `front()` | Accesses the first element of the vector. |
| `back()` | Accesses the last element of the vector. |
| `begin()` | Returns an iterator pointing to the first element of the vector. |
| `end()` | Returns an iterator pointing to the past-the-end element of the vector. |
| `rbegin()` | Returns a reverse iterator pointing to the last element of the vector. |
| `rend()` | Returns a reverse iterator pointing to the element preceding the first element of the vector. |
| `cbegin()` | Returns const_iterator to beginning. |
| `cend()` | Returns const_iterator to end. |
| `crbegin()` | Returns const_reverse_iterator to reverse beginning. |
| `crend()` | Returns const_reverse_iterator to reverse end. |
| `insert()` | Inserts elements at a specific position in the vector. |
| `erase()` | Removes elements from a specific position or range in the vector. |
| `swap()` | Swaps the contents of the vector with those of another vector. |
| `clear()` | Removes all elements from the vector. |
| `emplace()` | Constructs and inserts an element in the vector. |
| `emplace_back()` | Constructs and inserts an element at the end of the vector. |
| `assign()` | Assigns new values to the vector elements by replacing old ones. |
| `capacity()` | Returns the size of the storage space currently allocated to the vector. |
| `reserve()` | Requests that the vector capacity be at least enough to contain a specified number of elements. |
| `shrink_to_fit()` | Reduces memory usage by freeing unused space. |
| `data()` | Returns a direct pointer to the memory array used internally by the vector to store its owned elements. |
| `get_allocator()` | Returns a copy of the allocator object associated with the vector. |
