#include <iostream>

/*
 * 🟡 A linked list is a data structure that are form using chain of nodes, these nodes are nothing but an "object" which hold some kind of informations. Unlike array data structure that where data is stored into contiguous memory location.
   🟡 In linked list each node have the ""reference of a memory block"" represents the next node. Means these nodes are scattered in memory but connected with there ""reference pointer"".
   
   🔶 Information stored by node:
        1. "Actual Data"
        2. "Reference Pointer to next node"
        3. "Reference Pointer to previous node (Doubly Linked List)"
   
   🔷 Types of Linked List:
        1. "Singly Linked List"
        2. "Doubly Linked List"
        3. "Circular Linked List"
*/

namespace AbstractLinkedList {
    class SinglyLinkedList {
       public:
        virtual void something() = 0;
    };
}  // namespace AbstractLinkedList

namespace LinkedListTypes {
    /*
     * 1️⃣. Singly Linked List:   
    */
    class SinglyLinkedList {};
}  // namespace LinkedListTypes

int main() {}