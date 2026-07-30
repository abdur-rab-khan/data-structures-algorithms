/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                              💻 Priority Queue                                                                   |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 🟡 Priority Queue (Heap), A special data structure that guarantee the first element either be a smallest or greater. It maintains tree shape to store data       |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                          🔶 PRIORITY METHODS                                                                     |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
| 1. ".push(x)": Add element "x" at the top.                                                                                                                       |
|                                                                                                                                                                  |
| 2. ".pop()": Remove element from the top.                                                                                                                        |
|                                                                                                                                                                  |
| 3. ".top()": Return the top element.                                                                                                                             |
|                                                                                                                                                                  |
| 4. "st.empty()": Return true if stack is empty.                                                                                                                  |
|                                                                                                                                                                  |
| 5. "st.size()": Return the size of the stack.                                                                                                                    |
|                                                                                                                                                                  |
| 5. ".push_range()": Used to Insert list of elements as a container.                                                                                              |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <queue>

#include "../../../../DSA/dsa_utils.h"

using namespace std;

int main() {
    // Max Heap, by default "Priority Queue" is max-heap
    priority_queue<int> maxHeap;

    maxHeap.push(1);
    maxHeap.push(8);
    maxHeap.push(3);
    maxHeap.push(10);
    print(maxHeap.top(), "Top element of heap is: ");
}
