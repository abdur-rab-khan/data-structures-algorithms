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
    /**
     * Counts how many recent calls happened within the last 3000 time units.
     *
     * Given a sequence of timestamps, return the number of timestamps that fall
     * within the most recent 3000-unit window ending at the last timestamp.
     *
     * Example:
     * Input: timeStamps = {1, 100, 3001, 3002, 8001}
     * Output: 3
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param timeStamps Ordered list of request timestamps
     * @return Number of recent calls in the last 3000 units
     */
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
    /**
     * Computes the minimum total interval needed to finish all tasks with cooldown.
     *
     * Given a list of task labels and a cooldown value n, return the minimum
     * total time units needed to schedule all tasks so identical tasks are at
     * least n units apart.
     *
     * Example:
     * Input: tasks = ['A', 'B', 'C'], n = 2
     * Output: 3
     *
     * Time Complexity: O(m log m) where m is the number of distinct tasks
     * Space Complexity: O(m)
     *
     * @param tasks List of task labels
     * @param n Cooldown interval between identical tasks
     * @return Minimum total interval needed to finish all tasks
     */
    int totalInterval(const vector<char>& tasks, int n) {
        // Step 1. Count frequency of each task
        unordered_map<char, int> freq;
        for (char t : tasks) {
            freq[t]++;
        }

        // Step 2. Push all frequencies into max priority queue
        priority_queue<int> pq;
        for (const auto& p : freq) {
            pq.push(p.second);
        }

        // Step 3. Use a waiting queue to hold tasks on cooldown
        queue<pair<int, int>> waitingQueue;

        int time = 1;

        // Step 4. Run until both queue is empty.
        while (!pq.empty() || !waitingQueue.empty()) {
            time++;

            if (!pq.empty()) {
                int top = pq.top() - 1;
                pq.pop();

                if (top > 0) {
                    waitingQueue.push({top, time + n});
                }
            }

            if (!waitingQueue.empty() && waitingQueue.front().second == time) {
                pq.push(waitingQueue.front().first);
                waitingQueue.pop();
            }
        }

        return time;
    }

    void main() {
        vector<char> tasks = {'A', 'B', 'C'};
        cout << "Total interval takes: " << totalInterval(tasks, 2) << endl;
    }
}  // namespace medium_problems

namespace hard_problems {
    /**
     * Finds the minimum value in every contiguous window of size k.
     *
     * Given an array and a window size k, return a list containing the minimum
     * value from each window.
     *
     * Example:
     * Input: numbers = {2, 3, 4, 2, 6, 2}, k = 3
     * Output: {2, 2, 2, 2}
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k)
     *
     * @param numbers Input array of integers
     * @param k Window size
     * @return Minimum value of each window
     */
    vector<int> findMinimumWindow(const vector<int>& numbers, int k) {
        int leftIndex = 0;

        deque<int> deq;
        vector<int> minimumValues = {};

        for (int rightIndex = 0; rightIndex < numbers.size(); rightIndex++) {
            // Step 1: Remove greater from back
            while (!deq.empty() && numbers[deq.back()] > numbers[rightIndex]) {
                deq.pop_back();
            }

            // Add current index
            deq.push_back(rightIndex);

            // Step 2: Remove elements out of window
            if (!deq.empty() && deq.front() <= rightIndex - k) {
                deq.pop_front();
            }

            // Step 3: Store result when window is valid
            if (rightIndex >= k - 1) {
                minimumValues.push_back(numbers[deq.front()]);
            }
        }

        return minimumValues;
    }

    void main() {
        cout << "Hard Problems: " << endl;
        vector<int> numbers = {2, 3, 4, 2, 6, 2};
        printArrayElements(findMinimumWindow(numbers, 3), "Minimum values are: ");
    }
}  // namespace hard_problems

int main() {
    easy_problems::main();
    medium_problems::main();
    hard_problems::main();

    return 0;
}