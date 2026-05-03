#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
   public:
    queue<int> requestTracker;

    RecentCounter() { this->requestTracker = {}; }

    int ping(int t) {
        this->requestTracker.push(t);

        while ((t - 3000) > this->requestTracker.front()) {
            this->requestTracker.pop();
        }

        return this->requestTracker.size();
    }
};

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