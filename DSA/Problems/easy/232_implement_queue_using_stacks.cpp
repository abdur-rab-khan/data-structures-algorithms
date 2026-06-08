#include <iostream>
#include <stack>

class AbsTwoStack {
   public:
    virtual void push(int x) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
};

class TwoStack : public AbsTwoStack {
    std::stack<int> inbox;
    std::stack<int> outbox;

   public:
    TwoStack() {}

    void push(int x) override { inbox.push(x); }

    int pop() override {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                int top = inbox.top();
                outbox.push(top);
                inbox.pop();
            }
        }

        int top = outbox.top();
        outbox.pop();
        return top;
    }

    int peek() override {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                int top = inbox.top();
                outbox.push(top);
                inbox.pop();
            }
        }

        return outbox.top();
    }

    bool isEmpty() override { return outbox.empty() && inbox.empty(); }
};

int main() {
    TwoStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout << "Top element is: " << st.peek() << std::endl;
}