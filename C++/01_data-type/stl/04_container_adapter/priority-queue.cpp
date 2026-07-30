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

#include <format>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../../../../DSA/dsa_utils.h"

using namespace std;

struct Enemy {
    string playerName;
    int    health;
};

struct Compare {
    bool operator()(const Enemy& a, const Enemy& b) {
        return a.health > b.health;  // smaller health = higher priority
    }
};

int main() {
    // 1. Max Heap, by default "Priority Queue" is max-heap
    priority_queue<int> maxHeap;

    maxHeap.push(1);
    maxHeap.push(8);
    maxHeap.push(3);
    maxHeap.push(10);

    vector<int> nums = {50, 1, 2, 4, 12};
    maxHeap.push_range(nums);

    // Get the max value from the heap
    print(maxHeap.top(), "Top element of heap is: ");

    // 2. Min Heap, by using "greater<int>" comparision
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push_range(nums);
    print(minHeap.top(), "Top smallest element of heap is: ");

    // LET'S USE MIN HEAP BY BUILDING OUR OWN COMPARISION FUNCTION
    priority_queue<Enemy, vector<Enemy>, Compare> enemyHeap;

    enemyHeap.push({"Goblin", 30});
    enemyHeap.push({"Dragon", 200});
    enemyHeap.push({"Rat", 100});

    Enemy enemyWithLowestHealth = enemyHeap.top();
    cout << (std::format("\nEnemy with lowest health is: \n  Name: {}\n  Health: {}",
                         enemyWithLowestHealth.playerName, enemyWithLowestHealth.health))
         << endl;

    return 0;
}
