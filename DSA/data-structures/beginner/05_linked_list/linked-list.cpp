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

   🔶 Key Terminologies
        1. "Node"
        2. "Head"
        3. "Tail"
        4. "Pointer / Next"
        5. "Prev"
        6. "Traversal"
        7. "nullptr / NULL"
*/

// Node of singly linked, that will create a memory block where we have ""data"" and ""next node pointer""
struct Node {
    int   value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

namespace AbstractLinkedList {
    class SinglyLinkedList {
       public:
        virtual int            length()           = 0;
        virtual void           search(int target) = 0;
        virtual generator<int> traverse()         = 0;

        virtual void insertAtHead(int value)           = 0;
        virtual void insertAtTail(int value)           = 0;
        virtual void insertAt(int position, int value) = 0;

        virtual void deleteAtTail()           = 0;
        virtual void deleteAtHead()           = 0;
        virtual void deleteAt(int position)   = 0;
        virtual void deleteByValue(int value) = 0;

        virtual void print() = 0;
    };
}  // namespace AbstractLinkedList

namespace LinkedListTypes {
    /*
     * 1️⃣. Singly Linked List:   
    */
    class SinglyLinkedList : public AbstractLinkedList::SinglyLinkedList {
        int   size;
        Node* head;

       public:
        SinglyLinkedList() : head(nullptr), size(0) {}

        ~SinglyLinkedList() {
            Node* currentNode = head;
            Node* nextNode    = nullptr;

            while (currentNode->next != nullptr) {
                nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
        }

        int length() override { return size; }

        generator<int> traverse() override {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                co_yield currentNode->value;
                currentNode = currentNode->next;
            }
        }

        void insertAtHead(int value) override {
            if (head == nullptr) {
                Node* newNode = new Node(value);
                head          = newNode;
            } else {
                head->value = value;
            }
        }

        void insertAtTail(int value) override {
            if (head == nullptr) {
                throw overflow_error("Do not found any head!");
            }

            Node* currentNode = head;
            while (currentNode->next != nullptr)
                currentNode = currentNode->next;

            currentNode->value = value;
        }

        void insertAt(int position, int value) override {
            if (head == nullptr) {
                throw overflow_error("Do not found any head!");
            }

            int   currentPosition = 0;
            Node* currentNode     = head;

            while (currentNode->next != nullptr && currentPosition != position) {
                if (currentNode->next == nullptr && currentPosition != position) {
                    throw overflow_error("No element found at that position");
                }
                currentNode = currentNode->next;
                currentPosition++;
            };

            currentNode->value = value;
        }

        void print() {
            cout << "Linked List elements are: ";
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                cout << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    };
}  // namespace LinkedListTypes

int main() {}