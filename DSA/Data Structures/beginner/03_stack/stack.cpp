#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class IStack {
   public:
    // virtual IStack(int size) = 0; ❌ Wrong because, IStack  is called with object is created but for "ABSTRACT CLASS" no object will created.
    // 1️⃣. Member function can be a virtual function
    // 2️⃣. Destructure can be a virtual
    // 3️⃣. Constructor ❌
    // 4️⃣. Member variables ❌

    // 👉 To understand why, Because abstract class is for creating a blueprint, like what member function will be there. There we only add things which are required in the main class.

    virtual ~IStack() = 0;

    // 👉 "Virtual: " Actually "virtual" keyword in C++, that tell C++ compiler don't decide that will run instead decide on run time.
    virtual void push(int n) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    // 👉 Enforce "= 0", We should have to implement this on "main" class, but it's not a case with "DESTRUCTURE" because even if you aren't define, C++ compiler will automatically create this.
    // 👉 Which is bad sometimes, Like suppose we are creating dynamic object, 100% will going to need a ""DESTRUCTURE"" for cleaning things.
};

namespace StackDS {
    // 1️⃣. Let's implement "stack" using array DATA STRUCTURE.
    class ArrayStack : public IStack {
        int* stack;
        int top;
        int size;

       public:
        ArrayStack(int s) {
            stack = new int[s];
            top = -1;
            size = s;
        }

        ~ArrayStack() { delete[] stack; }

        void push(int n) override {
            if (isFull()) {
                cout << "Stack Overflow\n";
                return;
            }

            stack[++top] = n;
        }

        int pop() override {
            if (top == -1) {
                cout << "Stack Underflow\n";
                return -1;
            }

            return stack[top--];
        }

        int peek() override {
            if (top == -1) {
                cout << "Stack is empty\n";
                return -1;
            }

            return stack[top];
        }

        bool isEmpty() override { return top < 0; }
        bool isFull() override { return top >= size - 1; }
    };

    class VectorStack : public IStack {
       public:
    };

}  // namespace StackDS

int main() {
    StackDS::ArrayStack s1(2);
    StackDS::VectorStack s2;

    return 0;
}