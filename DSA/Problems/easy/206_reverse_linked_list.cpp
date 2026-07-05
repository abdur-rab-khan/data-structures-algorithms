#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::unique_ptr;

class SinglyLinkedList {
   private:
    struct Node {
        int              value;
        unique_ptr<Node> next;
    };

   public:
    unique_ptr<Node> head;
    SinglyLinkedList() : head(nullptr) {}

    void append(int value) {
        auto newNode = make_unique<Node>(value);

        if (head == nullptr) {
            head = std::move(newNode);
            return;
        } else {
            auto currentNode = head.get();
            while (currentNode->next != nullptr) {
                currentNode = (currentNode->next).get();
            }

            currentNode->next = std::move(newNode);
        }
    }

    string toString() const {
        string result = "";

        const Node* currentNode = head.get();
        while (currentNode != nullptr) {
            result += std::to_string(currentNode->value) + " ";
            currentNode = currentNode->next.get();
        }

        return result.empty() ? "(EMPTY)" : result;
    }

    /* 
      🟡 Iterative Approach to solve this problem, To reverse a linkedlist we'll start from head and gradually changing the pointers that pointing the next node.
      👉 Let's see an example: 1 --> 2 --> 3 --> 4 --> 5
              1 --> nullptr, head = 2 // Head will going to be tail
              2 --> 1, head = 3
              3 --> 2 --> 1, head = 4
              4 --> 3 --> 2 --> 1
              5 --> 4 --> 3 --> 2 --> 1 // Now we fully reverse the linkedlist
    */
    void reverseLinkedList() {
        unique_ptr<Node> previous = nullptr;

        while (head != nullptr) {
            unique_ptr<Node> next = std::move(head->next);
            head->next            = std::move(previous);
            previous              = std::move(head);
            head                  = std::move(next);
        }
        head = std::move(previous);
    }
};

int main() {
    const auto singlyLinkedList = make_unique<SinglyLinkedList>();

    singlyLinkedList->append(1);
    singlyLinkedList->append(2);
    singlyLinkedList->append(3);
    singlyLinkedList->append(4);
    singlyLinkedList->append(5);

    cout << "Node are: " << singlyLinkedList->toString() << endl;

    singlyLinkedList->reverseLinkedList();

    cout << "Node are: " << singlyLinkedList->toString() << endl;

    return 0;
}