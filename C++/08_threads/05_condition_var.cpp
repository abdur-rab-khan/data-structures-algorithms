// 🟡 condition_variable allows a thread to block while waiting for some condition, so it doesn't continuously consume CPU checking the condition.

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex              mtx;
std::condition_variable cv;
bool                    ready = false;

void task() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2000ms);
    std::cout << "[Task] Task has been finished successfully!" << std::endl;
}

void consumer() {
    std::cout << "[Consumer] Aquire the mtx, waiting for cv to notify it." << std::endl;
    std::unique_lock<std::mutex> lock(mtx);

    // 🔶 Wait until the condition "ready" becomes true.
    // 🔸 While waiting, the thread releases the mutex and becomes blocked,
    //    so it does not continuously consume CPU.
    // 🔸 When notified, the thread wakes up, re-acquires the mutex,
    //    and checks "ready" again.
    // 🔸 If ready is false, it waits again; if true, it continues.
    cv.wait(lock, [] { return ready; });
    std::cout << "[Consumer] Notified to continue" << std::endl;

    // 🔶 Continue -> After "notify_one" and ready is true so that we can continue it.
    std::thread t(task);
    t.join();

    std::cout << "[Consumer] Task has been finished successfully!" << std::endl;
}

void producer() {
    std::thread t(task);
    t.join();

    {
        // 🔶 Lock the mutex before modifying the shared "ready" variable.
        std::lock_guard<std::mutex> lock(mtx);

        // 🔸 The condition is now true, so the waiting thread can continue.
        ready = true;
    }

    // 🔶 Wake one thread waiting on "cv".
    // 🔸 The waiting thread will re-acquire the mutex and check "ready".
    cv.notify_one();
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}
