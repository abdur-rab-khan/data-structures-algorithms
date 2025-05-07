# Standard Template Library

> The C++ Standard Template Library set of templates of classes and functions that provides the implementation of common data structures and algorithms such as (`lists`, `stacks`, `queue`, `sorting`, `searching` etc).

- [Standard Template Library](#standard-template-library)
  - [Components of STL](#components-of-stl)
    - [Container](#container)
    - [Sequence Containers](#sequence-containers)
    - [Containers Adapters](#containers-adapters)
    - [Associative Containers](#associative-containers)
      - [2. Map](#2-map)
    - [Unordered Associative Containers](#unordered-associative-containers)

## Components of STL

- The components of STL are the features provided by Standard Template Library (STL) in C++ that can be classified into 4 parts.

1. [Containers](#container)
2. Algorithms
3. Iterators
4. Functors

### Container

> Containers are the data structures used to store objects and the data according to the requirements. Each containers are implements using template class that also contains the methods to perform basic operations on it.

- Containers are further classified into 4 types
    1. [Sequence Containers](#sequence-containers)
    2. [Containers Adapters](#containers-adapters)
    3. [Associative Containers](#associative-containers)
    4. [Unordered Associative Containers](#unordered-associative-containers)

### Sequence Containers

### Containers Adapters

### Associative Containers

#### 2. Map

> Maps are Associative Containers that are used to store data in the form of key-value pairs sorted on the basis of keys. In Map two value does not have same key, if try to do than previous one will override. By default, It store in ascending order of the keys, but it can be change as per requirement.

- **Syntax**

    ```c++
    map<key_type, value_type, comp> m;
    ```

  - Where
    1. `key_type`  Data type of key
    2. `value_type` Data type of value
    3. `comp`  Custom comparator function that defines how to compare two keys for sorting. It is optional and if not provided, sorts data in increasing order of the keys.
    4. `m` Name of the variable

- **Declaration and Initialization**

    ```cpp
    #include <iostream>
    #include <map>
    #include <string>
    using namespace std;
    
    int main() {
        map<int, string> m{{1, "Abdur Rab"}, {2, "Khan"}};
    
        for (auto& value : m) {
            cout << "Value is  " << value.first << " " << value.second << endl;
        }
    
        return 0;
    }
    ```

  - **Output**

    ```shell
    Value is  1 Abdur Rab
    Value is  2 Khan
    ```

- **Basic Operations**

    1. **Inserting Operations**

        > Element can be insert into map either using **`[]`** operator, **`.insert()`** method. **`.insert()`** method is associated with adding new element, **`[]`** for updating existing element.

        ```cpp
        #include <iostream>
        #include <map>
        #include <string>
        using namespace std;
        
        int main() {
            map<int, string> m = {{1, "Dog, Cat"}, {2, "Goat, Sheep"}};
        
            m.insert({2, "Tiger Lion"});
        
            m[2] = "Panda, Koala";
        
            for (auto& value : m) {
                cout << "Value is  " << value.first << " " << value.second << endl;
            }
        
            return 0;
        }
        ```

        ```shell
        Value is  1 Dog, Cat
        Value is  2 Panda, Koala
        ```

    2. **Accessing Elements**

        > Accessing Element associated with getting the element from map either using **`[]`** operator or **`.at(key)`** method. If the key exits, It will return associated value but if they key doesn't exits, it will create a new element with the given key and default value. To avoid this, use **`.at(key)`** method for accessing elements instead of create a new element it simple give an exception called **`out_of_range`**.

        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        
        int main() {
            map<int, string> m = {{1, "Geeks"},
                    {2, "For"}, {3, "Geeks"}};
        
            // Accessing elements
            cout << m[1] << endl;
            cout << m.at(2);
        
            return 0;
        }
        ```

        ```shell
        Panda, Koala
        Dog, Cat
        ```

    3. **Updating Elements**

        > The key of already present in the map cannot be change. But we can change the associated value by assessing the element and then using **assignment operator** to change the value

        ```cpp
        #include <iostream>
        #include <map>
        #include <string>
        using namespace std;
        
        int main() {
            map<int, string> m = {{1, "Dog, Cat"}, {2, "Goat, Sheep"}};
    
        m.at(1) = "Cow, Goat";
            m[2] = "Tiger, Lion";
        
            cout << endl << endl;
            for (auto& value : m) {
                cout << "Value is  " << value.first << " " << value.second << endl;
            }
        
            return 0;
        }
        ```

        ```shell
        Value is  1 Cow, Goat
        Value is  2 Tiger, Lion
        ```

    4. **Finding Elements**

        > Map provides fast element search by key using the **`.find(key)`** member function. This is function returns an iterator the element if found, otherwise returns end() iterators

        ```cpp
        #include<iostream>
    
        using namespace std;
    
        int main(){
            auto it = m.find(2);
            auto it2 = m.find(55);
    
            if (it != m.end()) {
                cout << "Element is found " << "Key is: " << it->first << " Value is " << it->second
                    << endl;
            } else {
                cout << "Error: Element is not found" << endl;
            }
        
        
            if (it2 != m.end()) {
                cout << "Element is found " << "Key is: " << it->first << " Value is " << it->second
                    << endl;
            } else {
                cout << "Error: Element is not found" << endl;
            }
        }
        ```

        ```shell
        Element is found Key is: 2 Value is Tiger, Lion
        Error: Element is not found
        ```

    5. **Traversing**

        > Map can be easily traversed using either **range based method** or using **`.begin()`** and **`.end()`** iterator with traditional loops.

        1. **`.begin()`**
            - The **map::begin()** method is used to retrieve a map::iterator pointing to the first element of std::map container.
        2. **`.end()`**
            - The map::end() method is used to retrieve a map::iterator pointing to the theoretical element just after the last element of the map.

        ```cpp
        #include<iostream>
        #include<map>

        int main(){
            map<int, string> m = {{1, "Dog, Cat"}, {2, "Goat, Sheep"}};
    
            // Using ForEach Method
            for (auto& value : m) {
                cout << "Value is  " << value.first << " " << value.second << endl;
            }
    
            // Traversing using iterators
            for (auto it = m.begin(); it != m.end(); ++it) 
                cout << it->first << " " << it->second
                << endl;
        }
        ```

        ```shell
        Value is  1 Cow, Goat
        Value is  2 Tiger, Lion
        1 Cow, Goat
        2 Tiger, Lion 
        ```

    6. **Deleting Elements**

        > Map element can be deleted using **`.erase()`** method by passing the key or an iterator.

        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        
        int main() {
            map<int, string> m = {{1, "Geeks"},
                    {2, "For"}, {3, "Geeks"}};
        
            // Deleting by key
            m.erase(2);
            
            // Deleting by iterator
            m.erase(m.begin());
            
            for(auto i : m)
                cout << i.first << " " << i.second
                << endl;
            return 0;
        }
        ```

        ```shell
        3 Geeks
        ```

  - **Basic Methods**

    | Function | Description |
    |----------|-------------|
    | insert() | Insert elements with a particular key in the map container. |
    | count() | Returns the number of elements matching specific key |
    | equal_range() | Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k. |
    | erase() | Used to erase elements from the map. |
    | begin() | Returns an iterator pointing to the first element of the map. |
    | end() | Returns an iterator pointing to the first element of the map. |
    | rend() | Returns a reverse iterator pointing to the element preceding the first element of the map |
    | rbegin() | Returns a reverse iterator pointing to the last element of the map. |
    | find() | Returns an iterator to the element with key-value in the map if found, else returns the iterator to end. |
    | crbegin() | Returns a constant reverse iterator referring to the last element in the map container. |
    | crend() | Returns a constant reverse iterator pointing to the theoretical element before the first element in the map. |
    | cbegin() | Returns a constant iterator referring to the first element in the map container. |
    | cend() | Returns a constant iterator pointing to the element that is beyond the last element. |
    | emplace() | Inserts the key with value in the map container. |
    | max_size() | Returns the maximum number of elements a map can hold. |
    | upper_bound() | Find the first element in the map that is just greater than the given key. |
    | lower_bound() | Find the first element in the map that is equal to or greater than the given key. |
    | emplace_hint() | Inserts the key and its element in the map container with a given hint. |
    | value_comp() | Returns the object that determines how the elements in the map are ordered ('<' by default). |
    | key_comp() | Returns the object that determines how the elements in the map are ordered ('<' by default). |
    | size() | Returns the number of elements in the map. |
    | empty() | Returns whether the map is empty. |
    | clear() | Removes all the elements from the map. |
    | at() | Used to access the element associated with the key k. |
    | swap() | Used to exchange the contents of two maps but the maps must be of the same type, although sizes may differ. |
    | next() | Returns the next iterator in the map. |
    | prev() | Returns the previous iterator in the map. |

### Unordered Associative Containers
