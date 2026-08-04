/*
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                        Forward List                                                                             |
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                                                                                                                 |
 | * "std::forward_list" is a container used to store element in a sequence, it's usually implemented using "Singly-LinkedList". Good thing about                  |
 |   "std::forward_list" (singly linked list) is we can insert or remove element as constant time complexity "o(1)".                                               |
 |                                                                                                                                                                 |
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                                                                                                                 |
 | * Element Access:                                                                                                                                               |
 |   1. front(): Returns first element                                                                                                                             |
 |   3. find(start_it, end_it, target): Used to access random element from the list and it returns an iterator                                                     |
 |                                                                                                                                                                 |
 | * Capacity:                                                                                                                                                     |
 |   1. empty(): Returns the bool whether list is empty or not                                                                                                     |
 |                                                                                                                                                                 |
 | * Modifiers:                                                                                                                                                    |
 |   1. insert_after(iterator, element): Insert element after the iterator                                                                                         |
 |   2. insert_range_after(iterator, container_compatible_range): Insert list of elements                                                                          |
 |                                                                                                                                                                 |
 |   1. clear(): Remove all the elements from the list                                                                                                             |
 |   2. erase_after(element): Remove particular elements after a particular iterator                                                                               |
 |                                                                                                                                                                 |
 |   2. push_front():                                                                                                                                              |
 |   2. pop_front():                                                                                                                                               |
 |                                                                                                                                                                 |
 | * Operations:                                                                                                                                                   |
 |   1. .merge(list): Merge two lists                                                                                                                              |
 |   1. .sort(list): Sort list                                                                                                                                     |
 |   1. .unique(list): Remove duplicate elements                                                                                                                   |
 |                                                                                                                                                                 |
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <algorithm>
#include <forward_list>
#include <vector>

#include "../../../../DSA/dsa_utils.h"

using namespace std;

int main() {
    forward_list<int> singlyLinkedList;

    singlyLinkedList.push_front(5);
    singlyLinkedList.push_front(4);
    singlyLinkedList.push_front(3);
    singlyLinkedList.push_front(2);
    singlyLinkedList.push_front(1);

    print(singlyLinkedList);

    // Random push via given iterator
    auto it = find(singlyLinkedList.begin(), singlyLinkedList.end(), 3);
    singlyLinkedList.insert_after(it, 33);

    print(singlyLinkedList);

    vector<int> nums    = {11, 22, 33, 44, 55};
    auto        startIt = singlyLinkedList.before_begin();
    singlyLinkedList.insert_range_after(startIt, nums);

    print(singlyLinkedList);

    return 0;
}
