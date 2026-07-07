/*
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     🔗 Doubly Ended Queue                                                                        |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
|  🔶 A "<deque>" data structure in C++ that allow remove/add of an element from both side either "front", "back".                                                 |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                      🟡 Important Methods                                                                        |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                  |
|. "front()/back()": See the first/last element.                                                                                                                |
|                                                                                                                                                                  |
|  2. "at(i)": See ith "index" element.                                                                                                                            |
|                                                                                                                                                                  |
|  3. "push_back(element)": Add to the back.                                                                                                                       |
|                                                                                                                                                                  |
|  4. "push_front(element)": Add to the front.                                                                                                                     |
|                                                                                                                                                                  |
|  5. "pop_back(element)": Remove from the back.                                                                                                                   |
|                                                                                                                                                                  |
|  6. "pop_front(element)": Remove from the front.                                                                                                                 |
|                                                                                                                                                                  |
|  7. "size()": Getting size of "deque".                                                                                                                           |
|                                                                                                                                                                  |
|  8. "empty(element)": Checking whether deque "empty or not".                                                                                                     |
|                                                                                                                                                                  |
|  9. "clear(element)": Remove all elements.                                                                                                                       |
|                                                                                                                                                                  |
+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> deq;

    // Adding to back
    deq.push_back(5);
    deq.push_back(3);

    // Adding to front
    deq.push_front(1);
    deq.push_front(2);

    // Printing all "deque" elements
    cout << "Deque elements are: ";
    for (const int& n : deq) {
        cout << n << " ";
    }
    cout << endl;

    // Printing "front" and "back" elements
    cout << "Front: " << deq.front() << endl;
    cout << "Back: " << deq.back() << endl;

    // Clearing all elements
    deq.clear();

    cout << "Now after clearing deq size is: " << deq.size() << endl;

    return 0;
}
