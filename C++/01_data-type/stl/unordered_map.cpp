/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                            UNORDERED_MAP                                                                         |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 🟡 An "unordered_map" is an STL container that stores data as "key-value" pairs using a hash table.                                                              |
|    It provides average O(1) insert/find/erase by key (worst-case can degrade to O(n)).                                                                           |
|    It's similar to Python "dict" and JavaScript "Map" (not "Set", because values are mapped to keys).                                                            |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              CAPACITY                                                                            |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1) empty()        -> checks whether the container has no elements.                                                                                               |
| 2) size()         -> returns number of key-value pairs currently stored.                                                                                         |
| 3) max_size()     -> returns the theoretical max number of elements the container can hold.                                                                      |
| 4) bucket_count() -> returns number of buckets used internally for hashing.                                                                                      |
| 5) load_factor()  -> returns average elements per bucket (size / bucket_count).                                                                                  |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              ITERATOR                                                                            |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1) begin(), end()           -> iterate through all key-value pairs.                                                                                              |
| 2) cbegin(), cend()         -> const iterators for read-only traversal.                                                                                          |
| 3) find(key)                -> returns iterator to key if found, otherwise end().                                                                                |
| 4) Iterate safely           -> always compare iterator with end() before dereferencing.                                                                          |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          ELEMENT ACCESS                                                                          |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1) operator[] -> returns reference to value by key; inserts default value if key does not exist.                                                                 |
| 2) at(key)    -> returns reference to value by key; throws std::out_of_range if key is missing.                                                                  |
| 3) Use at() when you need bounds checking; use [] when insertion-on-miss is acceptable.                                                                          |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          ELEMENT LOOKUP                                                                          |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 1) find(key)  -> iterator to element or end() if not found.                                                                                                      |
| 2) count(key) -> returns 1 if key exists, otherwise 0 (for unordered_map with unique keys).                                                                      |
| 3) contains(key) (C++20) -> true if key exists, otherwise false.                                                                                                 |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              MODIFIER                                                                            |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1) insert({k, v})  -> inserts only if key does not exist; does NOT overwrite existing value.                                                                     |
| 2) emplace(k, v)   -> constructs/inserts only if key does not exist.                                                                                             |
| 3) erase(key)      -> removes element by key.                                                                                                                    |
| 4) clear()         -> removes all elements.                                                                                                                      |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <iostream>
#include <string>
#include <unordered_map>

// It's use to define build-in type with custom name alias.
typedef std::unordered_map<std::string, std::string> stringmap;

int main() {
    // 1. Creating an empty map
    std::unordered_map<int, int> number;

    // 2. Creating map with fruits data.
    stringmap fruits({{"Apple", "🍎"}, {"Banana", "🍌"}});

    // 3. Copying the previous map uses "copy constructor" store on it's own memory.
    stringmap fruits2(fruits);

    fruits["Apple"] = "APPLE";

    std::cout << "From Original Apple is: " << fruits["Apple"] << std::endl;
    std::cout << "From Copied One Apple is: " << fruits2["Apple"] << std::endl;

    // 4. Building map using range.
    stringmap apple(fruits.begin(), fruits.end());

    // 1. ELEMENT ACCESS
    std::cout << "Apple is: " << fruits.at("Apple")
              << std::endl;  // Return to the mapped value of "apple".
    std::cout << "Apple is: " << fruits["Apple"] << std::endl;

    // 2. ELEMENT LOOKUP
    std::unordered_map<std::string, std::string>::const_iterator banana = fruits.find("Banana");
    if (banana != fruits.end()) {
        std::cout << "Banana is: " << banana->second << std::endl;
    }

    // Return an iterator for the element, If not found it will return iterator what match with map.end();
    auto cherry = fruits.find("Cherry");
    std::cout << "Cherry is: " << (cherry != fruits.end() ? (*(cherry)).second : "Not found")
              << std::endl;

    // Search on the map container and if value with "key" is found return 1 otherwise 0.
    std::cout << "Apple is " << (((fruits.count("Apple")) > 0) ? " found" : " not found")
              << std::endl;

    // 3. MODIFIERS

    // Correction: emplace inserts only when key does not exist. Existing key is not replaced.
    fruits.emplace("Apple", "APPPPLLEEE");

    // Correction: insert also does not replace existing value for duplicate key.
    fruits.insert({"Mango", "MANGO"});

    // Remove Apple from the "map".
    fruits.erase("Apple");

    // Used to remove every elements from the map
    fruits.clear();

    return 0;
}
