#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>

#include "../../dsa_utils.h"

class LRUCache {
   public:
    int capacity;

    std::list<std::pair<int, int>>                                    cacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // If key empty, mean no element there
        if (cacheList.empty()) {
            return -1;
        }

        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cacheList.splice(cacheList.end(), cacheList, it->second);
            return cacheList.back().second;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);

        // Remove the last element, if capacity exeeds the cacheList size
        if (capacity == static_cast<int>(cacheList.size())) {
            auto frontList = cacheList.begin();
            if (it == cacheMap.end() || it->second->first != key) {
                cacheMap.erase(frontList->first);
                cacheList.erase(frontList);
            }
        }

        if (it == cacheMap.end()) {
            cacheList.push_back({key, value});
            cacheMap.insert({key, std::prev(cacheList.end(), 1)});
        } else {
            it->second->second = value;
            cacheList.splice(cacheList.end(), cacheList, it->second);
        }
    }
};

int main() {
    std::cout << std::endl << "Test Case 1" << std::endl;
    {
        LRUCache cache(2);

        print(cache.get(2), "The value of key 2 is: ");
        cache.put(2, 6);
        print(cache.get(1), "The value of key 1 is: ");
        cache.put(1, 5);
        cache.put(1, 2);
        print(cache.get(1), "The value of key 1 is: ");
        print(cache.get(2), "The value of key 1 is: ");
    }

    std::cout << std::endl << "Test Case 2" << std::endl;
    {
        LRUCache cache(2);

        cache.put(1, 1);
        cache.put(2, 2);

        print(cache.get(1), "The value of key 1 is: ");
        cache.put(3, 3);
        print(cache.get(2), "The value of key 2 is: ");
        cache.put(4, 4);
        print(cache.get(1), "The value of key 1 is: ");
        print(cache.get(3), "The value of key 3 is: ");
        print(cache.get(4), "The value of key 4 is: ");
    }

    return 0;
}
