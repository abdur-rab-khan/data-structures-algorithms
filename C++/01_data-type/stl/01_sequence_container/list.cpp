/*
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                             List                                                                                |
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                                                                                                                 |
 | * "std::list" is a container used to store element in a sequence, it's usually implemented using "Doubly-LinkedList". Good thing about "std::list"              |
 |   (doubly linked list) is we can insert or remove element as constant time complexity "o(1)".                                                                   |
 |                                                                                                                                                                 |
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                                                                                                                 |
 | * Element Access:                                                                                                                                               |
 |   1. front(): Returns first element                                                                                                                             |
 |   2. back(): Returns last element                                                                                                                               |
 |   3. find(start_it, end_it, target): Used to access random element from the list and it returns an iterator                                                     |
 |                                                                                                                                                                 |
 | * Capacity:                                                                                                                                                     |
 |   1. size(): Returns the size of the list                                                                                                                       |
 |   2. empty(): Returns the bool whether list is empty or not                                                                                                     |
 |                                                                                                                                                                 |
 | * Modifiers:                                                                                                                                                    |
 |   1. insert(iterator, element): Insert element before the iterator                                                                                              |
 |   2. insert_range(iterator, container_compatible_range): Insert list of elements                                                                                |
 |   3. .splice("pos before the content will be inserted", "another container where it will be transfered", "element to be transfer"): all will be iterator        |
 |                                                                                                                                                                 |
 |   1. clear(): Remove all the elements from the list                                                                                                             |
 |   2. erase(iterator): Remove particular elements by giving the iterator                                                                                         |
 |                                                                                                                                                                 |
 |   1. push_back():                                                                                                                                               |
 |   2. push_front():                                                                                                                                              |
 |                                                                                                                                                                 |
 |   1. pop_back():                                                                                                                                                |
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
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;

int main() {
    list<int> doublyLinkedList;

    // Takes Constant TIME-COMPLEXITY for pushing element on the list
    doublyLinkedList.push_front(5);
    doublyLinkedList.push_back(10);
    doublyLinkedList.push_front(4);

    // Insert, takes an "iterator" and push after before that iterator
    auto it = std::next(doublyLinkedList.begin(), 2);
    doublyLinkedList.insert(it, 22);

    // Insert 50, after 22
    auto findIt = find(doublyLinkedList.begin(), doublyLinkedList.end(), 22);
    doublyLinkedList.insert(std::next(findIt, 1), 50);

    // Removing the 2th element which is 22
    doublyLinkedList.erase(std::next(doublyLinkedList.begin(), 2));

    // Updating the place of first element (4) at the end of the list
    //                      "place to insert"       "container to insert"   "element to insert"
    doublyLinkedList.splice(doublyLinkedList.end(), doublyLinkedList, doublyLinkedList.begin());

    // Moving the 10 directly from second last to the start
    doublyLinkedList.splice(doublyLinkedList.begin(), doublyLinkedList,
                            std::prev(doublyLinkedList.end(), 2));

    // Converting list to vector
    cout << "Elements are: ";
    for (const int& num : std::vector<int>(doublyLinkedList.begin(), doublyLinkedList.end())) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
