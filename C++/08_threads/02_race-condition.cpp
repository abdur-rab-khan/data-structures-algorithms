#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

// 🔶 The same "count" data might also be taken by another thread to update them, which could lead to have wrong behaviour.
// 🔸 Solution "mutex" which controls the access of "critical section of the code".
// 🔸 Suppose we have global data and we want while someother thread access the data other thread should have to wait until previous thread done.

// 🔷 Suppose multiple threads need to access the same shared data. We can use a mutex to make sure only one thread enters the critical section at a time.
// 🔹 Other threads trying to enter that same critical section have to wait until the mutex is unlocked.
// void counter(int& count) {
//     count++;
// }

// 🔶 "Mutex" works perfectly fine, until we got some issues and we never reaches to "mtx.unlock", Now this will create "deadlock" situtation for other threads waiting for unlock.
// 🔸 Solution "std::lock_guard<std::mutex> lock(mtx)", it's using 'RAII' technique in C++ that automatically destory (unlock) once it goes out of scope probabily using "destructure".
// void mutexCounter(int& count) {
//     mtx.lock();
//     count++;
//     mtx.unlock();
// }

void perfectCounter(int& count) {
    std::lock_guard<std::mutex> lock(mtx);
    count++;
}

int main() {
    int count = 0;

    std::thread t1(perfectCounter, std::ref(count));
    std::thread t2(perfectCounter, std::ref(count));
    std::thread t3(perfectCounter, std::ref(count));

    std::cout << "Count value before join: " << count << std::endl;

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Count value after join: " << count << std::endl;

    return 0;
}
