//
// Created by abdur on 22-06-2026.
//
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

struct Node {
    int   value;
    Node* next;
    explicit Node(const int value) : value(value), next(nullptr) {};
};

class SinglyLinkedList {
   public:
    Node* tail_;
    Node* head_;

    SinglyLinkedList() : tail_(nullptr), head_(nullptr) {}

    ~SinglyLinkedList() {
        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            const Node* nextNode = currentNode->next;
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

    SinglyLinkedList operator+(const SinglyLinkedList& list2) const {
        Node* head1 = head_;
        Node* head2 = list2.head_;

        if (head1 == nullptr) {
            SinglyLinkedList newList;

            newList.head_ = head2;
            newList.tail_ = list2.tail_;

            return newList;
        }

        if (head2 == nullptr) {
            SinglyLinkedList newList;

            newList.head_ = head1;
            newList.tail_ = tail_;

            return newList;
        }

        Node* ptr   = head1;
        Node* tail_ = head1;

        if (head1->value > head2->value) {
            ptr   = head2;
            tail_ = head2;
            head2 = head2->next;
        } else {
            head1 = head1->next;
        }

        while (head1 && head2) {
            if (head1->value > head2->value) {
                tail_->next = head2;
                tail_       = tail_->next;
                head2       = head2->next;
            } else {
                tail_->next = head1;
                tail_       = tail_->next;
                head1       = head1->next;
            }
        }

        if (head1 != nullptr) {
            tail_->next = head1;
        } else {
            tail_->next = head2;
        }

        SinglyLinkedList list;

        list.head_ = ptr;
        list.tail_ = tail_;

        return list;
    }

    string toString() {
        string nodes = "";

        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            nodes += to_string(currentNode->value) + " ";
            currentNode = currentNode->next;
        }

        return nodes.empty() ? "(EMPTY)" : nodes;
    }
};

typedef Node* List;

// Recursive version for "merging two list"
List mergeTwoList(List list1, List list2) {
    if (list1 == nullptr) {
        return list2;
    }

    if (list2 == nullptr) {
        return list1;
    }

    if (list1->value <= list2->value) {
        list1->next = mergeTwoList(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoList(list1, list2->next);
        return list2;
    }
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

    List mergedList = mergeTwoList(list1->head_, list2->head_);

    cout << "Merged elements are: ";
    while (mergedList != nullptr) {
        cout << mergedList->value << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    delete list1;
    delete list2;
    return 0;
}
