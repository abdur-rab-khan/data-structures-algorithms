#include <iostream>
#include <stack>

// Let's make an interface for this
class IMinStack {
   public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual int getMin() = 0;
};

// Main class
class MinStack : public IMinStack {
    std::stack<int> valueStack;
    std::stack<int> miniStack;

   public:
    void push(int value) override {
        valueStack.push(value);
        miniStack.push(miniStack.empty() ? value : std::min(value, miniStack.top()));
    }

    void pop() override {
        if (valueStack.empty()) {
            throw std::underflow_error("pop() called on empty stack");
        }

        valueStack.pop();
        miniStack.pop();
    }

    int top() override {
        if (valueStack.empty()) {
            throw std::underflow_error("top() called on empty stack");
        }

        return valueStack.top();
    }

    int getMin() override {
        if (miniStack.empty()) {
            throw std::underflow_error("getMin() called on empty stack");
        }

        return miniStack.top();
    }
};

int main() {
    MinStack s1;

    s1.push(-2);
    s1.push(0);
    s1.push(-3);

    std::cout << "Top Value of Stock is: " << s1.top() << std::endl;
    std::cout << "Min Value of Stock is: " << s1.getMin() << std::endl;

    s1.pop();

    std::cout << "Top Value of Stock is: " << s1.top() << std::endl;
    std::cout << "Min Value of Stock is: " << s1.getMin() << std::endl;
}