//
// Created by abdur on 24-06-2026.
//
#include <iostream>
#include <string>

class SinglyLinkedList {
   private:
    struct Node {
        int   value;
        Node* next;
        explicit Node(const int val) : value(val), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

   public:
    SinglyLinkedList() : head_(nullptr), tail_(nullptr) {}

    SinglyLinkedList(const SinglyLinkedList&)            = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    ~SinglyLinkedList() {
        Node* currentNode = head_;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

    bool isEmpty() const noexcept { return head_ == nullptr; }

    void append(const int value) {
        const auto newNode = new Node(value);

        if (isEmpty()) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            tail_->next = newNode;
            tail_       = tail_->next;
        }
    }

    SinglyLinkedList* operator+(const SinglyLinkedList& list2) const {
        int   carry  = 0;
        auto* result = new SinglyLinkedList();

        // Helper calculate and update the list
        auto sumHelper = [&carry, &result](const int num1, const int num2 = 0) {
            const int sum   = num1 + num2 + carry;  // Adding a sum of two numbers along with carry
            const int digit = sum % 10;             // Extracting the last digit from the sum
            carry           = sum / 10;             // Update the carry from current sum
            result->append(digit);
        };

        auto cursor1 = this->head_;
        auto cursor2 = list2.head_;

        // Adding sum by calculating both numbers
        while (cursor1 && cursor2) {
            sumHelper(cursor1->value, cursor2->value);
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
        }

        // Adding remaining part of the node
        while (cursor1) {
            sumHelper(cursor1->value);
            cursor1 = cursor1->next;
        }

        while (cursor2) {
            sumHelper(cursor2->value);
            cursor2 = cursor2->next;
        }

        // Adding the remaining carry
        if (carry > 0) {
            result->append(carry);
        }

        return result;
    }

    std::string toString() const {
        std::string result;

        const Node* currentNode = head_;
        while (currentNode != nullptr) {
            result += std::to_string(currentNode->value) + " ";
            currentNode = currentNode->next;
        }

        return result.empty() ? "(empty)" : result;
    }
};

int main() {
    SinglyLinkedList list1;
    SinglyLinkedList list2;

    // 1. Appending on list1
    list1.append(9);
    list1.append(9);
    list1.append(9);
    list1.append(9);
    list1.append(9);
    list1.append(9);
    list1.append(9);

    // 2. Appending on list2
    list2.append(9);
    list2.append(9);
    list2.append(9);
    list2.append(9);

    const SinglyLinkedList* sumList = list1 + list2;
    std::cout << "Sum of List of Elements are: " << sumList->toString() << std::endl;

    delete sumList;
    return 0;
}