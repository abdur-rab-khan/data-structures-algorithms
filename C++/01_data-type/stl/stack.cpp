/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              💻 STACK                                                                            |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 🟡 Stack is a data structure that follows "LIFO" model where we push and pop elements from the top.                                                              |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          🔶 STACK METHODS                                                                        |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1. "st.push(x)": Add element "x" at the top.                                                                                                                    |
|                                                                                                                                                                  |
| 2. "st.pop()": Remove element from the top.                                                                                                                      |
|                                                                                                                                                                  |
| 3. "st.top()": Return the top element.                                                                                                                          |
|                                                                                                                                                                  |
| 4. "st.empty()": Return true if stack is empty.                                                                                                                 |
|                                                                                                                                                                  |
| 5. "st.size()": Return the size of the stack.                                                                                                                   |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 3. Let's use built-in "stack" from STL
    stack<int> st;

    st.push(5);                  // push adds element at the top
    cout << st.empty() << endl;  // tells whether stack is empty or not
    cout << st.size() << endl;   // gives the size of stack
    cout << st.top() << endl;    // gives the top element of the stack
    st.pop();                    // removes the top element

    // 👉 Stack supports three type for underlying containers, (deque --> default, vector, list).
    // By default, the underlying container is deque.
    deque<int> d(1, 8);
    stack<int> s(d);

    // Use list as an underlying container
    list<int> l(1, 12);
    stack<int, list<int>> sl(l);

    // Use vector as an underlying container
    vector<int> vec(1, 8);
    stack<int, vector<int>> sv(vec);

    cout << "LL: " << s.top() << endl;

    return 0;
}