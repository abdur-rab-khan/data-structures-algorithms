#include <bits/stdc++.h>
using namespace std;

namespace queues {
    class CircularQueue {
        int* arr;
        int front;
        int count;
        int capacity;

       public:
        CircularQueue(int size) {
            front = 0;
            count = 0;
            capacity = size;
            arr = new int[capacity];
        }

        ~CircularQueue() { delete[] arr; }

        bool isEmpty() { return count == 0; }

        bool isFull() { return count == capacity; }

        int size() { return count; }

        void push(int value) {
            if (isFull()) {
                cout << "Queue is full!" << endl;
                return;
            }

            int position = (front + count) % capacity;
            arr[position] = value;
            count++;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            front = (front + 1) % capacity;
            count--;
        }

        int getFront() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return arr[front];
        }
    };
}  // namespace queues

namespace easy_problems {
    int numberOfRecentCalls(const vector<int>& timeStamps) {
        int size = timeStamps.size();

        queues::CircularQueue cQueue(size);

        for (int i = 0; i < size; i++) {
            cQueue.push(timeStamps[i]);

            // Remove older calls
            while ((timeStamps[i] - cQueue.getFront()) > 3000) {
                cQueue.pop();
            }
        }

        return cQueue.size();
    }

    void main() {
        // Number of Recent Calls
        vector<int> timeStamps = {1, 100, 3001, 3002, 8001};
        cout << "Recent calls are: " << numberOfRecentCalls(timeStamps) << endl;
    }
}  // namespace easy_problems

namespace medium_problems {
    int totalInterval(const vector<char>& tasks) {
        priority_queue<int> pQueue;

        // Step 1. Pre-processing adding every element into priority queue
        unordered_map<char, int> freq;
        for (char t : tasks) {
            freq[t]++;
        }
        for (const auto& p : freq) {
            pQueue.push(p.second);
        }

        // Step 2. Doing calculation
        int prevTask = 0;
        int totalInterval = 0;

        for (int i = 0; i < pQueue.size(); i++) {
            if (i != 0) {
            }

            prevTask = (prevTask + 1) % pQueue.size();
            totalInterval++;
        }

        return totalInterval;
    }

    void main() {
        vector<char> tasks = {'A', 'A', 'B', 'B', 'B'};
        cout << "Total interval takes: " << totalInterval << endl;
    }
}  // namespace medium_problems

int main() {
    easy_problems::main();
    return 0;
}