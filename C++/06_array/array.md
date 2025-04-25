# 📃 Array

> **`Array`** is a type of data structure which is used to store collection of similar type of data structure. And it store data in a contiguous memory location.

> We know that a pointer is used to store memory addresses, and an array is a special type of data structure where the array name points to the memory location of its first element.

* There are two types of array.
    * Static Typed (Default).
    * Dynamic Typed (Vectors).

---

## 📔 Array Declaration
`type name_variable[size] = {element}`

So there two things that carry variable.
* Data.
* Size information.

```
int array[4] = {1,2,3,4};

cout << array <<endl; --> Return First Address.
cout << *array <<endl; --> Getting the value on first address.
```

> ***⚠️ Problem happen when we pass these array into the function. It only goes the first pointer address of the array instead of going all array. 
`int *ptr` = `pointer to int` `int (*ptr)[size]` = `pointer to array`***

## 🍄‍🟫 Calling inside Function
```
void looping(int (&arr)[size_array]) // Reference to whole array

void looping(int arr[size]) // Same as int* array --> Lost size information and only has first pointer element.
```


## 🔁 Looping
```
// Using For Loop.
for(int i = 0; i < length; i++){
    cout << array[i] <<endl;
}

// Lopping using pointer.
int num[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << "The " << i << "th " << "Element is:- " << *(&(nu[i])) << endl;
}

// While Loop.
while(length--){
    cout << array[length] <<endl;
}

// For Each.
for(int num : number){
    cout << num << endl;
}
```

## 💾 Pointer in Array
> A Pointer is a variable that store the memory address of another variable. Pointer in array that store the first memory address of the array. And also they can also able to point whole array.
* **First Way**
    ```cpp
    #include<iostream>
    using namespace std;

    int main(){
        int arr[] = {1,2,3,5};
        int* ptr = arr;

        cout << ptr << endl; // Address of first array element.

        // Access the element using pointer arithmetic
        cout << *ptr << endl; // 1
        cout << *(ptr + 1) << endl; // 2
        cout << *(ptr + 2) << endl; // 3

        // Access element using index
        cout << ptr[0] << endl; // 1
        cout << ptr[1] << endl; // 2
        cout << ptr[2] << endl; // 3
        return 0;
    }
    ```
    * **Explanation**
        * In the `above` example we assign the first array element address on ptr.
        * We know that array in store in `contiguous` manner, mean that we can access element.
            1. Using Pointer Arithmetic `ptr + 1` = `address + 4` means next memory address.
            2. Using Index Also `ptr[1]` = `ptr + 1`
    
* **Second Way (Array Parameter and Pointers)**
    ```cpp
    #include<iostream>
    using namespace std;

    int main(){
        int arr[6] = {1,2,3,4,5,6};
        int (*ptr)[6] = &arr;

        cout << (*ptr)[0] << endl; // 1
        cout << (*ptr)[1] << endl; // 2
        return 0;
    }
    ```
    * **Explanation**
        * Here we point whole array instead of first element.
        * To access the element from the array we have to use above one like syntax.
            * `(*ptr)` here we got the address of first array element. if we deference it `1` got.
            * `(*ptr)[2]` here exact same as `(*ptr) + 2` means `first_address + 2` point to third element.
    

## ⭐ Impotent Methods for Array.
| Method | Description |
|--------|-------------|
| **`size_of`** | Returns the size of the array. |
| **`std::begin`** | Returns the first element of the array. |
| **`std::end`** | Returns the last element of the array. |
| **`std::rbegin`** | Returns the reverse iterator to the last element of the array. |
| **`std::rend`** | Returns the reverse iterator to the first element of the array. |
| **`std::data`** | Returns the pointer to the first element of the array. |
| **`std::empty`** | Returns true if the array is empty. |
| **`std::fill`** | Fills the array with a specific value. |
| **`std::copy`** | Copies the elements of one array to another. |
| **`std::swap`** | Swaps the elements of two arrays. |
| **`std::sort`** | Sorts the elements of the array. |
| **`std::reverse`** | Reverses the order of the elements in the array. |
| **`std::find`** | Finds an element in the array. |
| **`std::accumulate`** | Computes the sum of the elements in the array. |
| **`std::count`** | Counts the number of occurrences of a specific value in the array. |
| **`std::max_element`** | Returns the largest element in the array. |
| **`std::min_element`** | Returns the smallest element in the array. |                                  
