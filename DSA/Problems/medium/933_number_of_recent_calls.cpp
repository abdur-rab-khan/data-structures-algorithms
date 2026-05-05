#include <bits/stdc++.h>
using namespace std;

/**
 * Tracks recent requests within a 3000-millisecond window.
 */
class RecentCounter {
   public:
    queue<int> requestTracker;

    /**
     * Initializes an empty request tracker.
     */
    RecentCounter() { this->requestTracker = {}; }

    /**
     * Records a request and returns the number of requests in [t-3000, t].
     *
     * Example:
     * Input: t = 3001 with prior calls at 1 and 100
     * Output: 3
     *
     * Time Complexity: Amortized O(1) per call - each request is enqueued
     * and dequeued once.
     * Space Complexity: O(w) - at most the number of requests in the window
     *
     * @param t Current timestamp in milliseconds
     * @return Number of recent requests within the last 3000 ms
     */
    int ping(int t) {
        this->requestTracker.push(t);

        while ((t - 3000) > this->requestTracker.front()) {
            this->requestTracker.pop();
        }

        return this->requestTracker.size();
    }
};

/**
 * Executes sample request sequences.
 */
int main() {
    RecentCounter* rc = new RecentCounter();

    cout << "Request is: " << rc->ping(1) << endl;
    cout << "Request is: " << rc->ping(100) << endl;
    cout << "Request is: " << rc->ping(3001) << endl;
    cout << "Request is: " << rc->ping(3002) << endl;

       RecentCounter* rc2 = new RecentCounter();

    cout << "Request is: " << rc2->ping(5000) << endl;
    cout << "Request is: " << rc2->ping(5500) << endl;
    cout << "Request is: " << rc2->ping(9000) << endl;

    delete rc;

    return 0;
}