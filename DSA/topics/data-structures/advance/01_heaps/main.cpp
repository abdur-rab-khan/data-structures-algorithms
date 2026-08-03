/*
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       HEAP DATA STRUCTURE                                                                      |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🟡 A heap is a tree-shaped structure, stored as a plain array, that always keeps the smallest (min-heap) or biggest (max-heap) element on top for              |
|    instant access.                                                                                                                                             |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                               OPERATIONS OF HEAP DATA STRUCTURE                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔶 Insert on Heap o(log n):                                                                                                                                    |
|                   Insert a new value into the heap.                                                                                                            |
|                        1: add val at the end of the array                                                                                                      |
|                        2: compare it with its parent                                                                                                           |
|                        3: if heap rule is broken (parent > new value), swap and move up                                                                        |
|                        4: repeat until parent holds, or we reach the root                                                                                      |
|                                                                                                                                                                |
|                        This is "bubble up" — the new element floats toward the top if it's too small.                                                          ||                                                                                                                                                                |
|                                                                                                                                                                |
| 🔶 Remove on Heap o(log n):                                                                                                                                    |
|                    Remove the top element (smallest) from the heap.                                                                                            |
|                           1: move the last element to the top, shrink the array                                                                                |
|                           2: compare the new top with its smaller child                                                                                        |
|                           3: if heap rule is broken (parent > smaller child), swap and move down                                                               |
|                           4: repeat until rule holds, or we run out of children                                                                                |
|                                                                                                                                                                |
|                       This is "bubble down" — the replacement element sinks toward the leaves if too big.                                                      |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                FORMULAS OF HEAP DATA STRUCTURE                                                                 |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔶 Get Parent of a child: (n - 1) / 2;                                                                                                                         |
| 🔶 Get Left Child: (n * 2) + 1;                                                                                                                                |
| 🔶 Get Right Child: (n * 2) + 2;                                                                                                                               |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <format>
#include <stdexcept>
#include <utility>
#include <vector>

#include "../../../../dsa_utils.h"

using namespace std;

namespace Heap {
    class CustomHeap {
       public:
        CustomHeap(const vector<int>& d = {}) { heapify(d); }

        // Insert a new value into the heap.
        // Steps: 1) add val at the end of the array
        //        2) compare it with its parent
        //        3) if heap rule is broken (parent > new value), swap and move up
        //        4) repeat until parent holds, or we reach the root
        // This is "bubble up" — the new element floats toward the top if it's too small.
        void push(int val) {
            data.push_back(val);

            int lastPtr   = data.size() - 1;
            int parentPtr = (lastPtr - 1) / 2;

            while (parentPtr >= 0 && parentPtr < lastPtr) {
                int parent = data[parentPtr];
                if (parent < data[lastPtr]) {
                    break;
                }

                std::swap(data[parentPtr], data[lastPtr]);

                lastPtr   = parentPtr;
                parentPtr = lastPtr / 2;
            }

            print(data, std::format("Heap after adding {}: ", val));
        }

        // Remove the top element (smallest) from the heap.
        // Steps: 1) move the last element to the top, shrink the array
        //        2) compare the new top with its smaller child
        //        3) if heap rule is broken (parent > smaller child), swap and move down
        //        4) repeat until rule holds, or we run out of children
        // This is "bubble down" — the replacement element sinks toward the leaves if too big.
        void pop() {
            if (empty()) {
                throw std::runtime_error("Failed to pop from the empty heap");
            }

            int popedElement = data[0];

            data[0] = data.back();
            data.pop_back();

            int ptr      = 0;
            int leftPtr  = 1;
            int rightPtr = 2;

            while (leftPtr < size() && rightPtr < size()) {
                int smallerIdx = (data[leftPtr] < data[rightPtr] ? leftPtr : rightPtr);
                if (data[ptr] < data[smallerIdx]) {
                    break;
                }

                std::swap(data[ptr], data[smallerIdx]);

                ptr      = smallerIdx;
                leftPtr  = (ptr * 2) + 1;
                rightPtr = (ptr * 2) + 2;
            }

            if (leftPtr < size() && data[ptr] > data[leftPtr]) {
                std::swap(data[ptr], data[leftPtr]);
                ptr = leftPtr;
            }

            if (rightPtr < size() && data[ptr] > data[rightPtr]) {
                std::swap(data[ptr], data[rightPtr]);
                ptr = rightPtr;
            }

            print(data, std::format("Heap after removing {}: ", popedElement));
        }

        int top() { return data.front(); }

        int size() { return data.size(); }

        bool empty() { return data.empty(); }

       private:
        vector<int> data;

        void heapify(const vector<int>& d = {}) {
            if (d.empty()) {
                return;
            }

            // int lastNonLeafIdx = n / 2;
        }
    };

    void main() {
        CustomHeap heap;

        // Pushing the element into the heap
        heap.push(1);
        heap.push(2);
        heap.push(3);
        heap.push(11);
        heap.push(8);
        heap.push(2);

        // Popping the element from the heap
        heap.pop();
    }
}  // namespace Heap

int main() {
    Heap::main();
    return 0;
}
