#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>

#include "../../dsa_utils.h"

// A fixed-capacity Least Recently Used (LRU) cache.
//
// Get and Put both run in O(1) time.
// We keep items in a doubly linked list ordered by use:
// the front holds the least recently used item,
// the back holds the most recently used item.
// The hash map lets us jump straight to any item's position in the list.
class LRUCache {
   public:
    explicit LRUCache(int capacity) : capacity_(capacity) {
        // True && True = True, Won't run on truthy condition
        assert(capacity_ > 0 && "Capacity must be a positive number");
    }

    int get(int key) {
        auto it = cacheMap_.find(key);
        if (it == cacheMap_.end()) {
            return -1;
        }

        // Mark this item as most recently used by moving it to the back.
        cacheList_.splice(cacheList_.end(), cacheList_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cacheMap_.find(key);

        if (it != cacheMap_.end()) {
            // Key already exists: update value and mark as most recently used.
            it->second->second = value;
            cacheList_.splice(cacheList_.end(), cacheList_, it->second);
            return;
        }

        // Key is new. Evict the least recently used item if we are full
        if (capacity_ == static_cast<int>(cacheList_.size())) {
            const int lruKey = cacheList_.front().first;
            cacheMap_.erase(lruKey);
            cacheList_.pop_front();
        }

        cacheList_.push_back({key, value});
        cacheMap_[key] = std::prev(cacheList_.end());
    }

   private:
    int                                                               capacity_;
    std::list<std::pair<int, int>>                                    cacheList_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap_;
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
