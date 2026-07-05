//
// Created by abdur on 23-06-2026.
//
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class SinglyLinkedList {
   private:
    struct Node {
        int   value;
        Node* next;
        explicit Node(const int value) : value(value), next(nullptr) {};
    };
    Node* tail_;
    Node* head_;

   public:
    SinglyLinkedList() : tail_(nullptr), head_(nullptr) {}
    ~SinglyLinkedList() {
        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            const Node* nextNode = head_->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

    void append(const int value) {
        const auto newNode = new Node(value);
        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            tail_->next = newNode;
            tail_       = tail_->next;
        }
    }

    void rotate(const int k) {
        if (head_ == nullptr) {
            return;
        }

        // Step 1. Find the size and tail of the list
        int   size = 1;  // head_ is non-null, mean at-least one element will be there.
        Node* tail = head_;
        while (tail->next != nullptr) {
            tail = tail->next;
            ++size;
        }

        // Step 2. Compute effective rotation and find the new tail
        const int effectiveRotation = ((k % size) + size) % size;
        if (effectiveRotation == 0) {
            return;
        }

        const int stepsToNewTail = size - effectiveRotation - 1;
        Node*     newTail        = head_;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 3. Rewrite pointers -- attach old tail to old head, update new head
        Node* newHead = newTail->next;
        newTail->next = nullptr;  // Breaking the chain
        tail->next    = head_;
        head_         = newHead;
    }

    string toString() const {
        string nodes;

        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            nodes += to_string(currentNode->value) + " ";
            currentNode = currentNode->next;
        }

        return nodes.empty() ? "(EMPTY)" : nodes;
    }
};

int main() {
    const auto singlyLinkedList = new SinglyLinkedList();

    singlyLinkedList->append(1);
    singlyLinkedList->append(2);
    singlyLinkedList->append(3);
    singlyLinkedList->append(4);
    singlyLinkedList->append(5);

    cout << "Elements are: " << singlyLinkedList->toString() << endl;

    singlyLinkedList->rotate(2);

    cout << "Elements are: " << singlyLinkedList->toString() << endl;

    delete singlyLinkedList;
    return 0;
}