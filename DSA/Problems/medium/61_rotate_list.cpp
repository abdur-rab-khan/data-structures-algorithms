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

    void rotateRight(int k) {
        if (head_ == nullptr || head_->next == nullptr) {
            return;
        }

        int   size = 1;
        Node* last = head_;
        while (last->next != nullptr) {
            last = last->next;
            ++size;
        }

        last->next = head_;

        int   stepsToNewTail = size - (k % size);
        Node* newTail        = head_;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        head_         = newTail->next;
        newTail->next = nullptr;
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

    singlyLinkedList->rotateRight(2);

    cout << "Elements are: " << singlyLinkedList->toString() << endl;

    delete singlyLinkedList;
    return 0;
}
