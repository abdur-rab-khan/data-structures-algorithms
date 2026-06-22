//
// Created by abdur on 22-06-2026.
//
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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

    string toString() const {
        string nodes = "";

        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            nodes += std::to_string(currentNode->value) + " ";
            currentNode = currentNode->next;
        }

        return nodes.empty() ? "(EMPTY)" : nodes;
    }
};

typedef SinglyLinkedList::Node List;

auto mergeTwoList(List list1, List list2) {
    return list1;
}

int main() {
    const auto list1 = new SinglyLinkedList();
    const auto list2 = new SinglyLinkedList();

    // Appending on list 1
    list1->append(1);
    list1->append(2);
    list1->append(4);

    // Appending on list 2
    list2->append(1);
    list2->append(3);
    list2->append(4);

    delete list1;
    delete list2;
    return 0;
}