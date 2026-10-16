/*
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       HEAP DATA STRUCTURE                                                                      |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🟡 A heap is a tree-shaped structure, stored as a plain array, that always keeps the smallest (min-heap) or biggest (max-heap) element on top for              |
|    instant access.                                                                                                                                             |
|                                                                                                                                                                |
| 🟡 There are two rule while storing in the heap:                                                                                                               |
|       1:                                                                                                                                                       |
|           🔸 min-heap: Here, Every Parent must be smaller than it's children                                                                                   |
|           🔸 max-heap: Here, Every Parent must be greater than it's children                                                                                   |
|       2:                                                                                                                                                       |
|           🔸 Tree must be filled level by level from ""left to right"", new level only start once previous level is full                                       |
|                                                                                                                                                                |
| 🟡 Using this, it will be guarantee that first element must be either smaller/greater, because of the insertion/deleting/retrieval is so easy and quick.       |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                               OPERATIONS OF HEAP DATA STRUCTURE                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔶 Insert on Heap o(log n):                                                                                                                                    |
|                   Insert a new value into the heap.                                                                                                            |
|                        1: Push new value at the end                                                                                                            |
|                        2: Compare it's parent                                                                                                                  |
|                        3: Heap rule break swap with it's parent                                                                                                |
|                        4: Repeat until, reach to the root or become valid                                                                                      |
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
| 🔶 Get Leaves: (n / 2) - 1;                                                                                                                                    |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <stdexcept>
#include <utility>
#include <vector>

#include "../../../../dsa_utils.h"

using namespace std;

struct Heap {
    void push(int v) {
        data.push_back(v);

        int currentIdx = data.size() - 1;
        int parentIdx  = (currentIdx - 1) / 2;

        while (currentIdx >= 0 && data[parentIdx] < data[currentIdx]) {
            swap(data[parentIdx], data[currentIdx]);
            currentIdx = parentIdx;
            parentIdx  = (currentIdx - 1) / 2;
        }
    }

    int pop() {
        if (empty()) {
            throw std::runtime_error("Failed to pop from empty heap");
        }

        int topElem = top();

        data[0] = data.back();
        data.pop_back();

        int idx = 0;

        while (true) {
            int leftIdx  = 2 * idx + 1;
            int rightIdx = 2 * idx + 2;

            if (leftIdx >= size())
                break;

            int greaterIdx = leftIdx;
            if (rightIdx < size() && data[rightIdx] > data[leftIdx]) {
                greaterIdx = rightIdx;
            }

            if (data[idx] >= data[greaterIdx]) {
                break;
            }

            swap(data[idx], data[greaterIdx]);

            idx = greaterIdx;
        }

        return topElem;
    }

    int top() { return data.front(); }

    bool empty() { return data.empty(); }

    int size() { return data.size(); }

    Heap() {}
    Heap(const vector<int>& data) : data(buildHeap(data)) {}

   private:
    vector<int> data;

    vector<int> buildHeap(const vector<int>& data) {
        vector<int> heap(data.begin(), data.end());

        int size = static_cast<int>(data.size());
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(heap, size, i);
        }

        return heap;
    }

    void heapify(vector<int>& data, int size, int idx) {
        while (true) {
            const int left  = 2 * idx + 1;
            const int right = 2 * idx + 2;

            int biggest = idx;
            if (left < size && data[left] > data[biggest])
                biggest = left;

            if (right < size && data[right] > data[biggest])
                biggest = right;

            if (biggest == idx)
                break;

            swap(data[idx], data[biggest]);
            idx = biggest;
        }
    }
};

int main() {
    Heap hp {{1, 2, 3, 11, 8, 2}};

    // hp.push(1);
    // hp.push(2);
    // hp.push(3);
    // hp.push(11);
    // hp.push(8);
    // hp.push(2);

    print(hp.top(), "Top element in heap is: ");
    print(hp.pop(), "Pop element that removed is: ");
    print(hp.top(), "Top element in heap is: ");

    return 0;
}
