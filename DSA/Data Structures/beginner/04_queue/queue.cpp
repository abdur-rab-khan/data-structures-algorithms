#include <bits/stdc++.h>
using namespace std;

/*
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                1️⃣ Simple Queue                                                                                |
+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace SimpleQueue {
    class SimpleQueue {
        int* arr = nullptr;
        int capacity;
        int size;

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
*/
namespace CircularQueue {
    class CircularQueue {
        int* arr = nullptr;
        int capacity;
        int front;
        int size;

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
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
        cout << "Element is Removed: " << queue1.dequeue() << endl;
    }
}  // namespace CircularQueue

int main() {
    // SimpleQueue::main();
    CircularQueue::main();

    return 0;
}