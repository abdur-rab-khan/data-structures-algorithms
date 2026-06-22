//
// Created by abdur on 22-06-2026.
//
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;

/*
 * [ WHAT IS THIS ]:🟡 A Floyd's tortoise and hare, It's a technique used to detect "cycle" inside the linked list.
 * [ HOW IT WORK ]: 🔵 It uses two pointers called "🐢 tortoise" and "🐇 hare" also called as (slow -> 1 step/time and fast -> 2 step/time) pointer, Let's see step by step how it works:
 *                     🔶 Example:  [1] -> [2] -> [3]
 *                                          ↑       ↓
 *                                         [5] <- [4]
 *
 *                     🔸 Step 1: slow = [1], fast = [1]
 *                     🔸 Step 2: slow = [2], fast = [3] // Go by 1 time, Go by 2 time --> It will run until ""fast is at nullptr or fast->next is nullptr""
 *                     🔸 Step 3: slow = [3], fast = [5]
 *                     🔸 Step 4: slow = [4], fast = [2]
 *                     🔸 Step 5: slow = [5], fast = [4]
 *                     🔸 Step 6: slow = [2], fast = [2] // Both meet at a position mean cycle exists
 *
 * [ WHY IT WORKED ]: 🟡 Floyd's tortious and hare technique is working because if any cycle exists means it will eventually go to meet at any position, this will be always a case.
*/
class SinglyLinkedList {
   private:
    struct Node {
        int              value;
        shared_ptr<Node> next;
        explicit Node(const int value) : value(value), next(nullptr) {};
    };
    Node*            tail_;
    shared_ptr<Node> head_;

   public:
    shared_ptr<Node> append(int value, const shared_ptr<Node>& next = nullptr) {
        auto newNode = make_shared<Node>(value);

        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = head_.get();
        } else {
            if (next != nullptr) {
                newNode->next = next;
            }

            tail_->next = newNode;
            tail_       = tail_->next.get();
        }

        return newNode;
    }

    bool hasCycle() const {
        const Node* slow = head_.get();
        const Node* fast = head_.get();

        while (slow != nullptr && fast->next != nullptr) {
            slow = slow->next.get();
            fast = fast->next->next.get();

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    const auto linkedList = make_unique<SinglyLinkedList>();

    linkedList->append(1);
    const auto node = linkedList->append(2);
    linkedList->append(3);
    linkedList->append(-4, node);

    cout << "Has cycle: " << linkedList->hasCycle() << endl;

    const auto linkedList2 = make_unique<SinglyLinkedList>();

    linkedList->append(1);

    cout << "Has cycle: " << linkedList->hasCycle() << endl;

    return 0;
}