#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

/*
 * 🟡 A linked list is a data structure that are form using chain of nodes, these nodes are nothing but an "object" which hold some kind of information. Unlike array data structure that where data is stored into contiguous memory location.
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

namespace LinkedListTypes {
    /*
     * 🟡 Singly Linked List: In Singly Linked List, Nodes are only pointed to it's next element in the chain and every node has "actual value", "reference pointer to next node".
    */
    class SinglyLinkedList {
       private:
        // Node of singly linked, that will create a memory block where we have ""data"" and ""next node pointer""
        struct Node {
            int   value;
            Node* next;
            explicit Node(const int val) : value(val), next(nullptr) {}
        };

        Node* head_;
        int   size_;

       public:
        SinglyLinkedList() : head_(nullptr), size_(0) {}

        SinglyLinkedList(const SinglyLinkedList&)            = delete;
        SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

        // Removing once linked list goes out of scope
        ~SinglyLinkedList() {
            Node* currentNode = head_;
            while (currentNode != nullptr) {
                Node* nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
        }

        bool isEmpty() const noexcept { return head_ == nullptr; }

        int size() const noexcept { return size_; }

        // ❌ Did Wrong: "Ignoring the head" by using this condition "current->head != nullptr"
        bool search(const int target) {
            Node* currentNode = head_;
            while (currentNode != nullptr) {
                if (currentNode->value == target) {
                    return true;
                }
                currentNode = currentNode->next;
            }
            return false;
        }

        void append(const int value) {
            Node* newNode = new Node(value);

            if (isEmpty()) {
                head_ = newNode;
            } else {
                Node* currentNode = head_;

                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
        }

        void insertAtHead(const int value) {
            Node* newNode = new Node(value);
            newNode->next = head_;
            head_         = newNode;

            ++size_;
        }

        void deleteAtHead() {
            if (isEmpty()) {
                throw std::runtime_error("deleteAtHead: list is empty");
            }

            Node* oldHead = head_;
            head_         = head_->next;

            delete oldHead;
            --size_;
        }
        void deleteAtTail() {
            if (isEmpty()) {
                throw std::runtime_error("deleteAtTail: list is empty");
            }

            // Single node case
            if (head_->next == nullptr) {
                delete head_;
                head_ = nullptr;
                --size_;
                return;
            }

            Node* currentNode = head_;
            while (currentNode->next->next != nullptr) {
                currentNode = currentNode->next;
            }

            delete currentNode->next;
            currentNode->next = nullptr;
            --size_;
        }

        void deleteByValue(const int target) {
            if (isEmpty()) {
                throw std::runtime_error("deleteByValue: list is empty");
            }

            // Head is the target
            if (head_->value == target) {
                deleteAtHead();
                return;
            }

            Node* currentNode = head_;
            while (currentNode->next != nullptr && currentNode->next->value != target) {
                currentNode = currentNode->next;
            }

            if (currentNode->next != nullptr) {
                Node* targetNode  = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete targetNode;
                --size_;
            }
        }

        std::string toString() const {
            std::string result;

            Node* currentNode = head_;
            while (currentNode != nullptr) {
                result += std::to_string(currentNode->value) + " ";
                currentNode = currentNode->next;
            }

            return result.empty() ? "(empty)" : result;
        }
    };

    /*
     * 🟡 Doubly Linked List: In Doubly Linked List, Nodes are pointer into both direction and every node in Doubly Linked List has three values, "actual value", "reference pointer to next node", "reference pointer to previous node".
     */
    class DoublyLinkedList {
       private:
        struct Node {
            int              value;
            shared_ptr<Node> next;
            shared_ptr<Node> previous;
            explicit Node(const int value) : value(value), next(nullptr), previous(nullptr) {}
        };
        shared_ptr<Node> head_;
        shared_ptr<Node> tail_;

       public:
        DoublyLinkedList() : head_(nullptr) {}
        // ~DoublyLinkedList() {
        //     Node* currentNode = head;
        //     while (currentNode != nullptr) {
        //         Node* nextNode = currentNode->next;
        //         delete currentNode;
        //         currentNode = nextNode;
        //     }
        // }

        void append(const int value) {
            auto newNode = make_shared<Node>(value);

            if (head_ == nullptr) {
                head_ = std::move(newNode);
                tail_ = newNode;
            } else {
                tail_->next       = std::move(newNode);
                newNode->previous = tail_;
                tail_             = newNode;
            }
        }

        std::string toString() const {
            std::string nodeStr = "";

            const auto currentNode = head_;
            while (currentNode != nullptr) {
                if (currentNode->previous != nullptr) {
                    nodeStr += std::to_string(currentNode->previous->value) + " <-> ";
                }

                nodeStr += std::to_string(currentNode->value);

                if (currentNode->next != nullptr) {
                    nodeStr += " <-> ";
                }
            }

            return nodeStr.empty() ? "(EMPTY)" : nodeStr;
        }
    };

    /*
     * 🟡 Circular Linked List: Circular Linked List are similar to Singly Linked List but only difference it the "tail node", always point to "head" node instead of "nullptr".
     */
    class CircularLinkedList {
       private:
        struct Node {
            int   value;
            Node* next;
            explicit Node(const int value) : value(value), next(nullptr) {}
        };
        Node* head;

       public:
        CircularLinkedList() : head(nullptr) {}

        void append(const int value) {
            Node* newNode = new Node(value);

            if (head == nullptr) {
                head       = newNode;
                head->next = head;
                return;
            }

            Node* currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
            newNode->next     = head;
        }

        void print() {
            if (head == nullptr)
                return;

            const Node* current = head;
            do {
                std::cout << current->value << " ";
                current = current->next;
            } while (current != head);

            std::cout << "(back to head)" << std::endl;
        }
    };

    void main() {
        // 🟡 Singly LinkedList
        cout << "Singly LinkedList" << endl << endl;

        const auto singlyLinkedList = std::make_unique<SinglyLinkedList>();

        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;

        singlyLinkedList->append(1);
        singlyLinkedList->append(2);
        singlyLinkedList->append(5);

        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;
        singlyLinkedList->insertAtHead(55);
        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;
        singlyLinkedList->append(100);
        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;
        singlyLinkedList->deleteByValue(3);
        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;
        singlyLinkedList->deleteAtTail();
        std::cout << "Linked list elements are: " << singlyLinkedList->toString() << std::endl;

        // 🟡 Doubly LinkedList
        cout << endl << "Doubly LinkedList" << endl;

        const auto doublyLinkedList = std::make_unique<DoublyLinkedList>();

        doublyLinkedList->append(11);
        doublyLinkedList->append(22);
        doublyLinkedList->append(33);
        doublyLinkedList->append(44);

        std::cout << "Doubly linked list elements are: " << doublyLinkedList->toString() << endl;

        // 🟡 Circular LinkedList
        cout << endl << "Circular LinkedList" << endl;

        const auto circularLinkedList = std::make_unique<CircularLinkedList>();

        circularLinkedList->append(111);
        circularLinkedList->append(222);
        circularLinkedList->append(333);
        circularLinkedList->append(444);
        circularLinkedList->append(555);

        std::cout << "Circular LinkedList elements are: ";
        circularLinkedList->print();
    }

}  // namespace LinkedListTypes

int main() {
    LinkedListTypes::main();
    return 0;
}
