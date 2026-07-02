//
// Created by abdur on 02-07-2026.
//
#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;

class MyStack {
   private:
    deque<int> deq;

   public:
    void push(const int x) { deq.push_back(x); }

    int pop() {
        const int top = deq.back();
        deq.pop_back();
        return top;
    }

    int top() const { return deq.back(); }

    bool empty() const { return deq.empty(); }
};

int main() {
    const auto obj = new MyStack();
    obj->push(5);
    int param_2 = obj->pop();

    obj->push(10);
    int param_3 = obj->top();

    obj->push(50);

    bool param_4 = obj->empty();

    cout << "Top element is: " << obj->top() << endl;

    delete obj;
    return 0;
}