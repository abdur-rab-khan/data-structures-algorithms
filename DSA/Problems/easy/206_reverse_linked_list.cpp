#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::unique_ptr;

struct ListNode {
    int                  value;
    unique_ptr<ListNode> next;
};

class SinglyLinkedList {
   private:
    unique_ptr<ListNode> head;

   public:
    SinglyLinkedList() : head(nullptr) {};

    void append(int value) {
        auto newListNode = make_unique<ListNode>(value);

        if (head == nullptr) {
            head = std::move(newListNode);
            return;
        } else {
            auto currentListNode = head.get();
            while (currentListNode->next != nullptr) {
                currentListNode = (currentListNode->next).get();
            }

            currentListNode->next = std::move(newListNode);
        }
    }

    string toString() const {
        string result = "";

        const ListNode* currentListNode = head.get();
        while (currentListNode != nullptr) {
            result += std::to_string(currentListNode->value) + " ";
            currentListNode = currentListNode->next.get();
        }

        return result.empty() ? "(EMPTY)" : result;
    }

    auto getHead() { return std::move(head); }

    /*
      🟡 Iterative Approach to solve this problem, To reverse a linkedlist we'll start from head and gradually changing the pointers that pointing the next ListNode.
      👉 Let's see an example: 1 --> 2 --> 3 --> 4 --> 5
              1 --> nullptr, head = 2 // Head will going to be tail
              2 --> 1, head = 3
              3 --> 2 --> 1, head = 4
              4 --> 3 --> 2 --> 1
              5 --> 4 --> 3 --> 2 --> 1 // Now we fully reverse the linkedlist
    */
    void reverseLinkedList() {
        unique_ptr<ListNode> previous = nullptr;

        while (head != nullptr) {
            unique_ptr<ListNode> next = std::move(head->next);
            head->next                = std::move(previous);
            previous                  = std::move(head);
            head                      = std::move(next);
        }
        head = std::move(previous);
    }
};

/*
 * 👉 We're trying to solve this problem via "recursive" approach, where we using "divide and conquer" approach, let's see how it's working
 * Example: 1 ➡️ 2 ➡️ 3
 *
 * Step 1: When list = 1 ➡️ 3, Calling fn for (2 ➡️ 3) --> Updating 2 ➡️ next ➡️ next = head (2), Now it become 2 ⬅️ 3 ⬅️ 4 -- Return 3 tail/newHead
 * Step 2: When list = 2 ➡️ 3, Calling fn for (3) ➡️ Updating 3 ➡️ next ➡️ next = head (3), Now it become 3 ⬅️ 4 -- Return 3 tail/newHead
 * Step 3: Now the basecase hit ➡️ Return 3 tail/newHead
 *
*/
unique_ptr<ListNode> reverseListRec(unique_ptr<ListNode> head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // 👉 Everything time this going to return the last node which is oldTail/newHead, once we reaches to end of the node.
    auto reversedHead = reverseListRec(std::move(head->next));

    head->next->next = std::move(head);
    head->next       = nullptr;

    return reversedHead;
}

int main() {
    const auto singlyLinkedList = make_unique<SinglyLinkedList>();

    singlyLinkedList->append(1);
    singlyLinkedList->append(2);
    singlyLinkedList->append(3);
    singlyLinkedList->append(4);
    singlyLinkedList->append(5);

    auto reversedList = reverseListRec(singlyLinkedList->getHead());

    cout << "Reversed List elements are: ";
    while (reversedList != nullptr) {
        cout << reversedList->value << " ";
        reversedList = std::move(reversedList->next);
    }

    return 0;
}
