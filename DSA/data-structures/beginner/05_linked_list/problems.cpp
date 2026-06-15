#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

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
        auto newNode = make_unique<Node>(value);

        if (head_ == nullptr) {
            head_ = std::move(newNode);
            return;
        }

        const auto oldHead = std::move(head_);
        head_              = std::move(newNode);
        ++size_;
    }

    void pop() const {
        if (isEmpty()) {
            throw std::runtime_error("Invalid pop: Cannot pop on empty list");
        }

        auto oldHead = std::move(head_);
        head_        = std::move(oldHead->next);
        --size_;
    }

    int peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Invalid peek: Cannot peek on empty list");
        }
        return head_->value;
    }

    int size() const noexcept { return size_; }

    bool isEmpty() const noexcept { return head_ == nullptr; }
};

typedef StackLinkedList Stack;

int main() {
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

    cout << "Top element is: " << stack->peek() << endl;
    stack->pop();

    return 0;
}