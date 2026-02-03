/*
+------------------------------------------------------+ ITERATOR IN C++ +-------------------------------------------------------+
|                                                                                                                                |
| 🟡An Iterator is an object that helps us to traverse elements of a containers like (array, vector, list) or custom data        |
|    structure one by one.                                                                                                       |
|                                                                                                                                |
| 🟡It works using pointers and references by "moving", "changing" the position of pointers commonly through operator            |
|    overloading.                                                                                                                |
|                                                                                                                                |
| 🟡By using iterator we can easily iterator through "for(auto x : container)" without using custom for loop, C++ easily convert |
|   "for-range" to for loop.                                                                                                     |
|                                                                                                                                |
+--------------------------------------------------------------------------------------------------------------------------------+
|                                                            SYNTAX                                                              |
+--------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                |
| 🟡 Build an iterator is done by using operator overloading and with the knowledge of pointers and references, So in every      |
|    we will increase the pointer address (ptr++).                                                                               |
|                                                                                                                                |
| ⭐ It's must to use "begin()" and "end()" function for your own data structure, So C++ can understand when iterator use in     |
|    "for-range loop".                                                                                                           |
|                                                                                                                                |
| class Iterator {                                                                                                               |
|     int* ptr;                                                                                                                  |
|                                                                                                                                |
|     public:                                                                                                                    |
|         Iterator(int* p): ptr(p) {}                                                                                            |
|                                                                                                                                |
|         int& operator*() {                                                                                                     |
|           ptr++;                                                                                                               |
|           return *this;                                                                                                        |
|         }                                                                                                                      |
|                                                                                                                                |
|         Iterator& operator++() {                                                                                               |
|            ptr++;                                                                                                              |
|            return *this;                                                                                                       |
|         }                                                                                                                      |
|                                                                                                                                |
|         bool operator!=(const Iterator& other) const {                                                                         |
|              return ptr != other.ptr                                                                                           |
|         }                                                                                                                      |
|   };                                                                                                                           |
|                                                                                                                                |
|   class MyContainer {                                                                                                          |
|      int data[3] = {10, 20, 30};                                                                                               |
|                                                                                                                                |
|      public:                                                                                                                   |
|         Iterator begin() {                                                                                                     |
|            return Iterator(&data[0]);                                                                                          |
|         }                                                                                                                      |
|                                                                                                                                |
|         Iterator end() {                                                                                                       |
|            return Iterator(&data[3]);                                                                                          |
|         }                                                                                                                      |
|   };                                                                                                                           |
|                                                                                                                                |
+------------------------------------------------------------+ END +-------------------------------------------------------------+ 
*/

#include <bits/stdc++.h>
using namespace std;

class Iterator{
  int* ptr;

  public:
    Iterator(int* p): ptr(p) {}

    int& operator*() {
      return *ptr;
    }

    Iterator& operator++(){
      ptr++;
      return *this;
    }

    bool operator!=(const Iterator& other) const {
      return ptr != other.ptr;
    }
};

class MyContainer {
  int data[3] = {10, 20, 30};

  public:
    Iterator begin(){
      return Iterator(&data[0]);
    }

    Iterator end() {
      size_t s = sizeof(data) / sizeof(data[0]);
      return Iterator(&data[s]);
    }
};

int main() {
    MyContainer con;

    cout << "Traversing --- " << endl;
    for(auto it = con.begin(); it != con.end(); ++it) {
      cout << *it << " ";
    }

    cout << "Traversing through for range loop: -- " << endl;
    for(const auto& x: con) {
      cout << x << " ";
    }

    // Trying iterator from build in containers.
    vector<int> x = {10, 20, 30, 50, 60};

    cout << "Traversing using vector iterator: -- " << endl;
    for(auto it = x.begin(); it != x.end(); ++it){
      cout << *it << " ";
    }
    cout << endl;


    return 0;
}
