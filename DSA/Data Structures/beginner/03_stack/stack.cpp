#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// 🟡 Stack implementation using different methods.
namespace StackDS {
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
        // 👉 Enforce "= 0", We should have to implement this on "main" class, but it's not a case with "DESTRUCTURE" because even if you aren't define, C++ compiler will automatically create this.
        // 👉 Which is bad sometimes, Like suppose we are creating dynamic object, 100% will going to need a ""DESTRUCTURE"" for cleaning things.
    };

    // Pure virtual destructors still need a definition for the linker.
    IStack::~IStack() = default;

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
        bool isFull() { return top >= size - 1; }
    };

    // 2️⃣. Let's implement "stack" using VECTOR.
    class VectorStack : public IStack {
        vector<int> stack;

       public:
        void push(int n) { stack.push_back(n); }

        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }

            int val = stack.back();
            stack.pop_back();
            return val;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }

            return stack.back();
        }

        bool isEmpty() { return stack.empty(); }
    };

    // 3️⃣. "main" function
    void main() {
        StackDS::ArrayStack s1(4);
        StackDS::VectorStack s2;

        s1.push(5);
        s1.push(4);
        s1.push(8);
        s1.push(12);
        // s1.push(12); ❌ Error: STACK OVERFLOW

        cout << "Peek element is: " << s1.peek() << endl;  // 12

        // 3️⃣. Let's use build-in "Stack" from stl
        std::stack<int> st;

        st.push(5);                  // "Push" is used to add element at the top
        cout << st.empty() << endl;  // Tell's whether stack is empty or not.
        cout << st.size() << endl;   // Gives the size of stack.
        cout << st.top() << endl;    // Gives the top element of the stack.
        st.pop();                    // Remove top element from the top

        // Stack supports two types of "underlying container" where they actually store the data.
        // And we can change them manually, First element of "STACK CONSTRUCTOR" is the "underlying container".
        // By default, ""UNDERLYING CONTAINER IS DEQUEUE"".
        std::deque<int> d(1, 8);
        std::stack<int> s(d);

        // Let's use list as a underlying container
        std::list<int> l(1, 12);
        std::stack<int, std::list<int>> sl(l);

        // Let's use vector as a underlying container
        std::vector<int> vec(1, 8);
        std::stack<int, std::vector<int>> sv(vec);

        cout << "LL: " << s.top() << endl;
    }

}  // namespace StackDS

namespace Problems {
    void main() {
        // different problems
    }
}  // namespace Problems

int main() {
    StackDS::main();
    Problems::main();

    return 0;
}