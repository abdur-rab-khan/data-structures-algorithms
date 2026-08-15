#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtxA;
std::mutex mtxB;

// 🟡 "std::lock" used to lock multiple "mutex" at a time, but why not just "scoped_lock".
// 🔸 It's because of using "std::lock" we can "lock multiple mutex" as well as "unlock one of them at any place".
// 🔸 Usually we try to use "std::lock + std::unique lockA(mtxA, std::defer_lock)", "std::defer_lock" create "unique_lock" but don't lock the mutex yet.
// 🔸 Now we need to use "std::lock(lockA, lockB)", std::lock() acquires (locks) the mutexes.
// 🔸 But it does so in a way designed to avoid deadlock when multiple threads request the same mutexes in different orders.
void taskA() {
    using namespace std::chrono_literals;

    // Creates the "unique_lock" but don't lock yet, we lock using "std::lock(lockA, lockB)"
    std::unique_lock<std::mutex> lockA(mtxA, std::defer_lock);
    std::unique_lock<std::mutex> lockB(mtxB, std::defer_lock);

    std::lock(lockA, lockB);

    std::cout << "Doing Heavy calculation and mtxA and mtxB both are lock" << std::endl;
    std::this_thread::sleep_for(1000ms);
    lockA.unlock();

    std::cout << "mtxA is unlocked not doing Heavy calculation with mtxB" << std::endl;
    std::this_thread::sleep_for(4000ms);
    lockB.unlock();
    std::cout << "<---> taskA is completed sucessfully <---> " << std::endl;
}

void taskB() {
    std::cout << "[taskB] Waiting for mtxA" << std::endl;
    std::lock_guard<std::mutex> lockA(mtxA);
    std::cout << "mtxA is unlocked, Now I can use them" << std::endl;
    std::cout << "<---> taskB is completed sucessfully <---> " << std::endl;
}

// 🟡 "std::try_lock" -> Try to acquire the mutex immediately. If it's unavailable, return false instead of waiting.
void taskC() {
    using namespace std::chrono_literals;

    std::cout << "[taskC] Waiting for mtxA, it busy just close it" << std::endl;
    std::unique_lock<std::mutex> lockA(mtxA, std::defer_lock);

    if (lockA.try_lock()) {
        std::this_thread::sleep_for(1000ms);
        std::cout << "[taskC] Finished successfully" << std::endl;
    } else {
        std::cout << "[taskC] mtxA is already begin used by someone else" << std::endl;
    }
}

int main() {
    std::thread t1(taskA);
    std::thread t2(taskB);
    std::thread t3(taskC);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
