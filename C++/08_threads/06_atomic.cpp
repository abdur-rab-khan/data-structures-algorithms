// 🟡 "atomic" is a type that makes certain operations on shared data
// 🔸 safe when multiple threads access the data at the same time.
//
// 🔸 A mutex protects a critical section of code.
// 🔸 An atomic makes specific operations on an atomic shared value
//    safe from interference by other threads.

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

int              mutexCount = 0;
std::atomic<int> atomicCount;

std::mutex mtx;

void mCounter() {
    std::cout << "[mCounter] Running the mutex counter fn" << std::endl;
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < 1000; i++) {
        mutexCount++;
    }
}

void aCounter() {
    std::cout << "[aCounter] Running the atomic counter fn" << std::endl;
    for (int i = 0; i < 1000; i++) {
        atomicCount++;
    }
}

int main() {
    // 🔶 Mutex Counter
    // 🔸 The first thread that acquires the mutex enters the critical section.
    // 🔸 Other threads trying to acquire the same mutex wait until it is released.
    std::thread mT1(mCounter);
    std::thread mT2(mCounter);

    // 🔶 Atomic Counter
    // 🔸 Similar to mutex that protects perticular section of a code, "automic" makes "specific operations" on an atomic shared value safe from interference by other threads.
    std::thread aT1(aCounter);
    std::thread aT2(aCounter);

    mT1.join();
    mT2.join();
    aT1.join();
    aT2.join();

    std::cout << "MutexCount is: " << mutexCount << std::endl;
    std::cout << "AtomicCount is: " << atomicCount << std::endl;

    return 0;
}
