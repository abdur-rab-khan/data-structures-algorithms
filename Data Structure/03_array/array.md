# Array Data Structure

> Array is the data structure that store collection of items of the same variable type, and they are store in contiguous memory location. It is one of the most and popular and simple data structures used in programming. \
> It is the foundation of some data structures such as queues, graphs, stacks and other more.

- [Array Data Structure](#array-data-structure)
  - [1. Memory Representation of Array](#1-memory-representation-of-array)
  - [2. Declaration of Array in C++](#2-declaration-of-array-in-c)
  - [3. Initialization of Array](#3-initialization-of-array)
  - [4. Types of Array](#4-types-of-array)
    - [1. Types of Arrays on the basis of Size](#1-types-of-arrays-on-the-basis-of-size)
    - [2. Types of Arrays on the basis of Dimensions](#2-types-of-arrays-on-the-basis-of-dimensions)
  - [5. Operations on Arrays](#5-operations-on-arrays)
    - [1. Array Traversal](#1-array-traversal)
    - [2. Insertion in Array](#2-insertion-in-array)
    - [3. Deletion in Array](#3-deletion-in-array)
    - [4. Searching in Array](#4-searching-in-array)

## 1. Memory Representation of Array

- In an Array, All elements are store in contiguous memory locations. So if we initialize an array. the elements will be store in **sequential manner** in memory. The allows efficient access and manipulation of elements.

    ![memory-representation-of-array-01](https://media.geeksforgeeks.org/wp-content/uploads/20250224182515919065/1-.webp)

    ![memory-representation-of-array-02](https://media.geeksforgeeks.org/wp-content/uploads/20250224182515574059/2-.webp)

## 2. Declaration of Array in C++

```cpp
void main(){
    // Array of integers
    int arr[5];
    
    // Array of characters 
    char arr[5];
    
    // Array of floats 
    float arr[5];
}
```

## 3. Initialization of Array

```cpp
void main(){
    // Array of integers
    int arr[] = {1, 2, 3, 4, 5};
    
    // Array of characters 
    char arr[5] = {'A', 'B', 'D', 'U', 'R'};

    // Array of floats 
    float arr[10] = { 1.4, 2.0, 24, 5.0, 0.0 };
}
```

## 4. Types of Array

- Array can be classified into two parts
    1. On the basis of size
    2. On the basis of dimension

        ![type-of-array](https://media.geeksforgeeks.org/wp-content/uploads/20240731124259/Types-of-Arrays.webp)

  ### 1. Types of Arrays on the basis of Size

    1. Fixed sized Arrays
        - In **Fixed sized Arrays** we cannot change or alter the size of array, means we can't increase or decrease the size.
        - The memory is allocate only for the size that is mentioned in square bracket (int arr[5], means 4 * 5 = 20 allocate 20 bytes).
        - In fixed size arrays the wastage of memory is happen, Suppose we have mentioned large size of array (or vise-versa) but adding less data it can cause wastage of memory.
        - In such cased [**static memory allocation**](../../C++/additional/02_memory_manegment.md/#1--static-memory-management) is not preferred, instead of this we use [**dynamic memory allocation**](../../C++/additional/02_memory_manegment.md/#2--dynamic-memory-management).

            ```cpp
                // Method 1 to create a fixed sized array. 
                // Here the memory is allocated at compile time.
                int arr[5]; 
                // Another way (creation and initialization both)
                int arr2[5] = {1, 2, 3, 4, 5}; 
                
                // Method 2 to create a fixed sized array
                // Here memory is allocated at run time (Also
                // known as dynamically allocated arrays)
                int *arr = new int[5];
            ```

    2. Dynamic sized Arrays

        - In Dynamic size Arrays, size can change based on user requirements during execution of program.
        - Insertion and deletion of elements in array as per needed, based on there size allocation and deallocation happen automatically.

            ```cpp
            #include<vector>

            // Dynamic Integer Array
            vector<int> v;
            ```

  ### 2. Types of Arrays on the basis of Dimensions

    1. **One-dimensional Array(1D Array):** 1D Array, You can imagine as table with single row and multiple columns.

        ![one-dimensional-array](https://media.geeksforgeeks.org/wp-content/uploads/20240405123929/One-Dimensional-Array(1-D-Array).webp)

    2. **Two-dimensional Array(2D Array):** For 2D Array, You can imagine as a table with as multiple rows and multiple columns.

        ![two-dimensional-array](https://media.geeksforgeeks.org/wp-content/uploads/20240408165401/Two-Dimensional-Array(2-D-Array-or-Matrix).webp)

    3. **Three-dimensional Array(2D Array):**  3D Multidimensional array contains three dimensions, so it can be considered an array of two-dimensional arrays.

        ![two-dimensional-array](https://media.geeksforgeeks.org/wp-content/uploads/20240408165421/Three-Dimensional-Array(3-D-Array).webp)

## 5. Operations on Arrays

### 1. Array Traversal

- Array traversal is a process of accessing and processing each elements of an array sequentially.
- This is one of the most fundamental operation on programming.

### 2. Insertion in Array

- Insertion in an array refers to the process of adding new elements at a specific position, while maintaining the order of existing elements.
- Arrays are stored in contiguous memory locations, meaning elements are arranged in sequential block.
  - There are the following steps when insertion happen.
    1. **Identify the position:**
    2. **Shifts Existing Elements to create space:**
    3. **Insert the new elements:**
    4. **Update the size (if applicable):**

### 3. Deletion in Array

- Deleting in an array refers to the process of delete elements at a specific position, while maintaining the order of existing elements.
- Since array have contiguous memory location, deletion of an element does not reduce the allocated memory size.
  - There are the following steps when deleting happen.
    1. **Identify the position**
    2. **Shift Elements after deleting**
    3. **Update the size (if applicable):**

### 4. Searching in Array

- Searching in an array is the process of finding specific element in given array of elements.
- In Searching our goal is to determine whether the elements exits in the array and if, exits so return the specific position.
- There is mainly two types of searching techniques in an arrays.

    1. **Linear Search (Sequential Search)**
    2. **Binary Search (Efficient Search for sorted array**
