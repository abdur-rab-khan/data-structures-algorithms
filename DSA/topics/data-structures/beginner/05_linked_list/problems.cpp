#include <iostream>
#include <list>
#include <memory>

using std::cout;
using std::endl;
using std::list;
using std::make_unique;
using std::unique_ptr;

namespace DataStructureUsingLinkedList {
    class StackLinkedList {
       private:
        struct Node {
            int              value;
            unique_ptr<Node> next;
            explicit Node(const int value) noexcept : value(value), next(nullptr) {}
        };
        int              size_;
        unique_ptr<Node> head_;

       public:
        StackLinkedList() : size_(0), head_(nullptr) {}

        void push(int value) noexcept {
            auto newNode  = make_unique<Node>(value);
            newNode->next = std::move(head_);
            head_         = std::move(newNode);
            ++size_;
        }

        void pop() {
            if (isEmpty()) {
                throw std::runtime_error("Invalid pop: Cannot pop on empty list");
            }

            // 👉 ".get keyword": It's gives the "raw pointer" of the current object, which is the exactly point into the memory address where the actual object is stored without any ownership sharing.
            // 👉 "Node* headPointer = head_.get()": Now "headPointer" is pointing to the same memory address where "head_" is actually stored, Now we can perform any operation like update (next, value) etc.
            const auto nodeToDiscard = std::move(head_);
            head_                    = std::move(nodeToDiscard->next);
            --size_;
        }

        // 👉 "const keyword": Using a const keyword with a function means, you aren't going to modify any object within the function, key effect are: (read only pointers,data protection,function call restriction (only const function can call within const function).
        // 👉 "mutable": This behaviour can be modify by using "mutable [Type] [Variable Name] = obj", So even if a function has "const" it will bypass the "const".
        int peek() const {
            if (isEmpty()) {
                throw std::runtime_error("Invalid peek: Cannot peek on empty list");
            }
            return head_->value;
        }

        int size() const noexcept { return size_; }

        bool isEmpty() const noexcept { return head_ == nullptr; }
    };

    class QueueLinkedList {
       private:
        struct Node {
            int              value;
            unique_ptr<Node> next;
            explicit Node(const int value) : value(value), next(nullptr) {}
        };
        int              size_;
        Node*            tail_;
        unique_ptr<Node> head_;

       public:
        QueueLinkedList() : size_(0), head_(nullptr), tail_(nullptr) {}

        void enqueue(int value) {
            auto newNode = make_unique<Node>(value);

            if (head_ == nullptr) {
                head_ = std::move(newNode);
                tail_ = head_.get();
            } else {
                tail_->next = std::move(newNode);
                tail_       = tail_->next.get();
            }

            ++size_;
        }

        int dequeue() {
            if (isEmpty()) {
                throw std::runtime_error("Invalid dequeue: Cannot perform dequeue on empty queue.");
            }

            const auto oldHead = std::move(head_);
            head_              = std::move(oldHead->next);
            --size_;

            // tail_ is raw observer, once the last node removed. It will become dangling pointer it we should have to explicitly reset them.
            if (head_ == nullptr) {
                tail_ = nullptr;
            }

            return oldHead->value;
        }

        int peek() const {
            if (isEmpty()) {
                throw std::runtime_error("Invalid peek: Cannot perform peek on empty queue.");
            }
            return head_->value;
        }

        int size() const { return size_; }

        bool isEmpty() const { return head_ == nullptr; }
    };

    typedef StackLinkedList Stack;
    typedef QueueLinkedList Queue;

    void main() {
        cout << "--> Stack data structure: " << endl << endl;
        const auto stack = make_unique<Stack>();

        stack->push(1);
        stack->push(2);
        stack->push(3);
        stack->push(4);
        stack->push(5);

        cout << "Top element is: " << stack->peek() << endl;
        stack->pop();

        cout << "Top element is: " << stack->peek() << endl;
        stack->pop();

        cout << "Top element is: " << stack->peek() << endl;
        stack->pop();

        cout << "Top element is: " << stack->peek() << endl;
        stack->pop();

        cout << "Top element is: " << stack->peek() << endl;
        stack->pop();

        // ❌ Cannot peek on empty list
        // cout << "Top element is: " << stack->peek() << endl;
        // stack->pop();

        cout << endl << endl << "--> Queue data structure: " << endl << endl;

        Queue queue;

        // ❌ [Invalid Peek] cout << "Peek element is: " << queue.peek() << endl;
        queue.enqueue(1);
        cout << "Peek element is: " << queue.peek() << endl;

        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        queue.dequeue();
        cout << endl << "Peek element is: " << queue.peek() << endl;
        cout << "Size of a queue is: " << queue.size() << endl;

        queue.dequeue();
        cout << endl << "Peek element is: " << queue.peek() << endl;
        cout << "Size of a queue is: " << queue.size() << endl;

        queue.dequeue();
        cout << endl << "Peek element is: " << queue.peek() << endl;
        cout << "Size of a queue is: " << queue.size() << endl;

        queue.dequeue();
        cout << endl << "Peek element is: " << queue.peek() << endl;
        cout << "Size of a queue is: " << queue.size() << endl;
    }
}  // namespace DataStructureUsingLinkedList

namespace Problems {
    list<int> addTwoNumber(const list<int>& a, const list<int>& b) {
        list<int> result;
        int       carry = 0;

        auto ptrA = a.begin(), ptrB = b.begin();
        while (ptrA != a.end() || ptrB != b.end() || carry != 0) {
            int valA = ptrA != a.end() ? *ptrA : 0;
            int valB = ptrB != b.end() ? *ptrB : 0;

            int totalSum = valA + valB + carry;
            result.push_back((totalSum % 10));

            carry = totalSum / 10;

            if (ptrA != a.end()) {
                ++ptrA;
            }

            if (ptrB != b.end()) {
                ++ptrB;
            }
        }

        return result;
    }
}  // namespace Problems

int main() {
    DataStructureUsingLinkedList::main();

    cout << "Result is: ";
    for (
        const int& n :
        Problems::addTwoNumber(list<int>({9, 9, 9, 9, 9, 9, 9}), list<int>({9, 9, 9, 9}))) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
