#include <bits/stdc++.h>
using namespace std;

/*
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                1️⃣ Simple Queue                                                                                |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                               |
| 🟡 Queue is a data structure that follows "FIFO" model, Data enters from one side (back) and removed from other side (front). Simple Queue uses static array to implement it. |
|                                                                                                                                                                               |
| 🔶 Time complexity:                                                                                                                                                           |
|                                                                                                                                                                               |
|                    🔹 Insertion of an element: o(1)                                                                                                                           |
|                    🔹 Removing of an element: o(n or 1)                                                                                                                            |
|                                                                                                                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace SimpleQueue {
    class SimpleQueue {
        int size;
        int capacity;
        int* arr = nullptr;

       public:
        SimpleQueue(int capacity) {
            size = 0;
            arr = new int[capacity];
        }

        ~SimpleQueue() { delete[] arr; }

        // Is empty
        bool isEmpty() { return size == 0; }

        // Is full
        bool isFull() { return size == capacity; }

        // Add an element at the rear of the query
        void enqueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }

            cout << value << " is added" << endl;

            arr[size] = value;
            size++;
        }

        // Remove an element at the front of the query
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << arr[0] << " is removed" << endl;

            for (int i = 1; i < size; i++) {
                arr[i - 1] = arr[i];
            }

            size--;
        }

        // Return front element from the queue
        int getFront() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[0];
        }

        // Return last element from the queue
        int getRear() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[size - 1];
        }
    };

    void main() {
        // Simple Queue
        SimpleQueue queue1(5);

        // Adding elements into queue.
        queue1.enqueue(1);
        queue1.enqueue(2);
        queue1.enqueue(3);
        queue1.enqueue(4);

        // Getting front and rear
        cout << "Front element is: " << queue1.getFront() << endl;
        cout << "Back element is: " << queue1.getRear() << endl;

        queue1.dequeue();
        queue1.dequeue();
        queue1.dequeue();
        queue1.dequeue();
        queue1.dequeue();
        queue1.dequeue();
    }

}  // namespace SimpleQueue

/*
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                               2️⃣ Circular Queue                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                               |
| 🟡 Circular Queue is the extended version of "Simple Queue", It is build to reduce the "removing" cost  from "o(n)" to "o(1)". By build Queue as a circular manner.           |
|    So instead of shifting the element we use other method for doing that.                                                                                                     |
|                                                                                                                                                                               |
| 🟡 Instead of shifting or doing anything, We use "%" operator So if [_, _, 1, 2] we got blank space at the start instead of shifting it when new element can will use formula |
|    ["front + size" % capacity], ("2 + 2" % 4) = 0, So the new element will be inserted at 0th index.                                                                          |
|                                                                                                                                                                               |
| 🔶 Time complexity:                                                                                                                                                           |
|                                                                                                                                                                               |
|                    🔹 Insertion of an element: o(1)                                                                                                                           |
|                    🔹 Removing of an element: o(1)                                                                                                                            |
|                                                                                                                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace CircularQueue {
    class CircularQueue {
        int size;
        int front;
        int capacity;
        int* arr = nullptr;

       public:
        CircularQueue(int cap) {
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            size = 0;
        }

        // Destructor
        ~CircularQueue() { delete[] arr; }

        // Queue is full
        bool isFull() { return size == capacity; }

        // Queue is empty
        bool isEmpty() { return size == 0; }

        // Add element into the queue;
        int enqueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return -1;
            }

            int rear = (front + size) % capacity;
            arr[rear] = value;
            size++;
            return value;
        }

        // Remove element from the queue;
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }

            int res = arr[front];
            front = (front + 1) % capacity;
            size--;
            return res;
        }

        // Getting first element from the queue;
        int getFront() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }

        // Getting last element from the queue;
        int getRear() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            int rear = (front + size - 1) % capacity;
            return arr[rear];
        }
    };

    void main() {
        cout << "Circular Queue: " << endl;

        CircularQueue queue1(5);

        // Adding an elements into the queue
        cout << "Element is added: " << queue1.enqueue(1) << endl;
        cout << "Element is added: " << queue1.enqueue(2) << endl;
        cout << "Element is added: " << queue1.enqueue(3) << endl;
        cout << "Element is added: " << queue1.enqueue(4) << endl;
        cout << "Element is added: " << queue1.enqueue(5) << endl;

        // Getting front and back
        cout << "Front element is: " << queue1.getFront() << endl;
        cout << "Back element is: " << queue1.getRear() << endl;

        // Removing elements from the queue
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;

        cout << "Element is added: " << queue1.enqueue(3) << endl;  // Adding an element

        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
    }
}  // namespace CircularQueue

/*
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                  3️⃣ Deque Queue                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                               |
|                                                                                                                                                                               |
|                                                                                                                                                                               |
|                                                                                                                                                                               |
|                                                                                                                                                                               |
|                                                                                                                                                                               |
|                                                                                                                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace Deque {
    class Deque {
        int* arr = nullptr;
        int size;
        int front, rear, count;

       public:
        Deque(int n) {
            size = n;
            front = 0, rear = 0, count = 0;
            arr = new int[size];
        }

        ~Deque() { delete[] arr; }

        bool isEmpty() { return count == 0; }
        bool isFull() { return count == size; }

        void addRear(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }

            arr[rear] = value;
            rear = (rear + 1) % size;

            cout << value << " is added at the rear of the queue." << endl;

            count++;
        }
        void addFront(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }

            front = (front - 1 + size) % size;
            arr[front] = value;

            cout << value << " is added at the front of the queue." << endl;

            count++;
        }

        void removeRear() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            rear = (rear - 1 + size) % size;
            cout << arr[rear] << " is removed at the rear of the queue" << endl;
            count--;
        }
        void removeFront() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << arr[front] << " is removed at the front of the queue" << endl;
            front = (front + 1) % size;
            count--;
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Elements are: ";
            for (int i = 0; i < count; i++) {
                cout << arr[(front + i) % size] << " ";
            }

            cout << endl;
        }

        void printFront() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Value at front is: " << arr[front] << endl;
        }
        void printRear() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            int r = (rear - 1 + size) % size;
            cout << "Value at rear is: " << arr[r] << endl;
        }
    };

    // MAIN FUNCTION
    void main() {
        Deque dq(4);

        dq.addRear(10);  // [10]
        dq.addRear(20);  // [10, 20]
        dq.addFront(5);  // [5, 10, 20]
        dq.addFront(1);  // [1, 5, 10, 20]
        dq.display();    // Deque: 1 5 10 20

        dq.removeFront();  // Removed from front: 1
        dq.removeRear();   // Removed from rear: 20
        dq.display();      // Deque: 5 10

        dq.printFront();  // Front: 5
        dq.printRear();   // Rear: 10
    }
};  // namespace Deque

/*
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                4️⃣ Priority Queue                                                                              |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                               |
| 🟡 Priority Queue is a type of queue where insert/remove element based on priority unlike other queue where follow "FIFO" model.                                              |
|                                                                                                                                                                               |
| 🔶 Type of Priority Queue                                                                                                                                                     |
|                                                                                                                                                                               |
|    1. Max Priority Queue: "High Value High Priority" -> [10, 5, 20] -> [20, 10, 5]                                                                                            |
|    2. Min Priority Queue: "Low Value High Priority" -> [20, 5, 10] -> [5, 10, 20]                                                                                             |
|                                                                                                                                                                               |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

int main() {
    SimpleQueue::main();
    CircularQueue::main();
    Deque::main();

    return 0;
}