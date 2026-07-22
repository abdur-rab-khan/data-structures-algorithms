//
// Created by abdur on 02-07-2026.
//
#include <cstdint>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

class MyStack {
    queue<int> q;

   public:
    void push(int x) {
        int size = static_cast<int>(q.size());

        q.push(x);
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
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
