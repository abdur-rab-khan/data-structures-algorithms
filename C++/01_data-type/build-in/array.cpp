/*
+---------------------------------------------------------------+ ARRAY DATA TYPE +---------------------------------------------------------------+
|                                                                                                                                                 |
| 🟡 Array in C++ is used to store collection of similar type of data in continuous memory, and it returns the "first address" of memory          | 
|  location.                                                                                                                                      |
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                      SYNTAX                                                                     |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| type arr[size] = {...values};                                                                                                                   |
| type* first_address = arr;                                                                                                                      |
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     LOOPING                                                                     |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| 🔁 FOR LOOP                                                                                                                                     |
| int length = sizeof(arr) / sizeof(arr[0]);                                                                                                      |
| for(int i = 0; i < length; i++) { std::cout << arr[i] << " \n"; }                                                                               |
|                                                                                                                                                 |
| 🔁 FOR EACH LOOP                                                                                                                                |
| for([const] int[&] i: arr) { std::cout << i << " \n"; }                                                                                         |
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                💡 Universal Rule                                                                |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| 1️⃣. int&: If "&" with "type" means reference, useful when you want to directly reference the memory location --> Useful in sum(vector<int>& x)  |
| 2️⃣. &variable: If "&" after variable means address of "variable"                                                                                |
|                                                                                                                                                 |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                Methods for Array                                                                |
+-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                 |
| 1️⃣. sizeOf(arr)   <--> Return size of the array                                                                                                 |
| 2️⃣. std::begin(arr)      <--> Returns iterator to the first element of the array                                                                |
| 3️⃣. std::end(arr)        <--> Returns iterator to the last element of the array                                                                 |
| 4️⃣. std::rbegin(arr)     <--> Returns reverse iterator to the last element of the array                                                         |
| 5️⃣. std::rend(arr)       <--> Returns reverse iterator to the first element of the array                                                        |
| 6️⃣. std::data(arr)       <--> Returns pointer to the first element of the array                                                                 |
| 7️⃣. std::empty(arr)      <--> Returns true if the array is empty                                                                                |
| 8️⃣. std::fill(begin, end, value) <--> Fills the array with a specific value                                                                     |
| 9️⃣. std::copy(src_begin, src_end, dest_begin) <--> Copies elements of one array to another                                                      |
| 🔟. std::swap(arr1, arr2) <--> Swaps the elements of two arrays                                                                                 |
| 1️⃣1️⃣. std::sort(begin, end) <--> Sorts the elements of the array                                                                                |
| 1️⃣2️⃣. std::reverse(begin, end) <--> Reverses the order of elements in the array                                                                 |
| 1️⃣3️⃣. std::find(begin, end, value) <--> Finds an element in the array                                                                           |
| 1️⃣4️⃣. std::accumulate(begin, end, init) <--> Computes the sum of elements in the array                                                          |
| 1️⃣5️⃣. std::count(begin, end, value) <--> Counts occurrences of a specific value in the array                                                    |
| 1️⃣6️⃣. std::max_element(begin, end) <--> Returns iterator to the largest element in the array                                                    |
| 1️⃣7️⃣. std::min_element(begin, end) <--> Returns iterator to the smallest element in the array                                                   |
|                                                                                                                                                 |
+---------------------------------------------------------------------+ END +---------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    int* first_address = arr; // Storing first address
    int* second_address = &(arr[1]);  // Storing second address

    // *(first_address + 1)  // Equivalent to first_address[1]

    cout << "First address: " << arr << endl; // Printing first address
    cout << "Second address: " << second_address << endl; // Printing second address

    cout << "First value: " << *arr << endl;  // Getting the value from the address
    // int*   <--> Using to store address of value typed int
    // *value <--> Using to get the value from pointer address

    int length = sizeof(arr) / sizeof(arr[0]);

    // --> FOR LOOP
    cout << endl;
    for (int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }

    // --> FOR EACH
    cout << endl;
    for(const int& i: arr){
        cout << i << endl;
    }

    return 0;
}