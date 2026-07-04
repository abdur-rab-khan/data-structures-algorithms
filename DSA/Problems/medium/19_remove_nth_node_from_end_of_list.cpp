//
// Created by abdur on 26-06-2026.
//
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::to_string;
using std::unique_ptr;

class SinglyLinkedList {
   private:
    struct Node {
        int              value;
        unique_ptr<Node> next;
        explicit Node(const int val) : value(val), next(nullptr) {}
    };
    unique_ptr<Node> head_;
    Node*            tail_;

   public:
    SinglyLinkedList() : head_(nullptr), tail_(nullptr) {}

    // delete nth element from the list
    void deleteNthNode(const int targetFromEnd) {
        if (head_ == nullptr)
            return;

        // Count total nodes
        int   listLength = 0;
        Node* cursor     = head_.get();
        while (cursor != nullptr) {
            ++listLength;
            cursor = cursor->next.get();
        }

        // predecessorIndex is the 0-based position of the node just before the target.
        const int predecessorIndex = listLength - targetFromEnd - 1;

        // If predecessorIndex < 0, the target is the head node itself.
        const bool targetIsHead = predecessorIndex < 0;
        if (targetIsHead) {
            head_ = std::move(head_->next);
            return;
        }

        Node* predecessorNode = head_.get();
        for (int i = 0; i < predecessorIndex; i++) {
            predecessorNode = predecessorNode->next.get();
        }

        // Unlink the target node by bypassing it and transferring ownership of its success
        auto nodeToRemove     = std::move(predecessorNode->next);
        predecessorNode->next = std::move(nodeToRemove->next);
    }

    // delete nth element within one pass
    // [ How it's working ]: For this problem we are using two pointer technique, by maintaining the gap between them by "targetFromEnd". Mean the first pointer will go to point "0" and "2", If fast pointer become nullptr or fast pointer->next become nullptr means we found the place where i want to remove
    void deleteNthNodeInOnePass(const int targetFromEnd) {
        if (head_ == nullptr) {
            return;
        }

        // Make the "fastNode" to "targetFrom + k" from the start
        auto fastNode = head_.get();
        for (int i = 0; i < targetFromEnd && fastNode != nullptr; i++) {
            fastNode = fastNode->next.get();
        }

        // Make the slow and fast to correct position.
        Node* slowNode = head_.get();
        while (fastNode != nullptr && fastNode->next != nullptr) {
            slowNode = slowNode->next.get();
            fastNode = fastNode->next.get();
        }

        // Check whether slowNode is head or not
        if (fastNode == nullptr) {
            head_ = std::move(head_->next);
        } else {
            const auto removeNode = std::move(slowNode->next);
            slowNode->next        = std::move(removeNode->next);
        }
    }

    // append value into list
    void append(int value) noexcept {
        auto newNode = make_unique<Node>(value);

        if (head_ == nullptr) {
            head_ = std::move(newNode);
            tail_ = head_.get();
        } else {
            tail_->next = std::move(newNode);
            tail_       = tail_->next.get();
        }
    }

    // converting list into list to print them
    string toString() const noexcept {
        string result;

        Node* currentNode = head_.get();
        while (currentNode != nullptr) {
            result += to_string(currentNode->value) + " ";
            currentNode = currentNode->next.get();
        }

        return result.empty() ? "(EMPTY)" : result;
    }
};

int main() {
    const auto list = make_unique<SinglyLinkedList>();

    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);

    list->deleteNthNodeInOnePass(2);

    cout << "Elements of the list are: " << list->toString() << endl;

    return 0;
}