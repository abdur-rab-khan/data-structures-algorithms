// 🟡 In C++, Async/Future provides simple way to achieve concurrency by running task on another thread and "future.get()" to wait and get for the result.
// 🟡 By default it's not run to a new thread, we explicitly needs to tell by passing first argument as "std::launch::async"
#include <format>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;
using namespace chrono_literals;

std::mutex  mtx;
vector<int> sharedData(2, 0);

void heavyCal(int& id) {
    std::lock_guard<std::mutex> lock(mtx);
    this_thread::sleep_for(2000ms);
    sharedData[0] = 55;
    std::cout << "[id]: " << id << " Heavy Calculation Done" << std::endl;
}

void heavyCalTwo(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    sharedData[1] = 66;
    std::cout << "[id]: " << id << " Heavy Calculation Done" << std::endl;
}

int main() {
    int  id    = 113;
    auto task1 = std::async(std::launch::async, heavyCal, std::ref(id));
    auto task2 = std::async(std::launch::async, heavyCalTwo, id);

    std::cout << "Doing some work..." << std::endl;

    // 🔶 Different waiting:
    // task1.wait_for(2s); // 🟡 Only wait for 2 sec if does return anything, then it simply move on
    //      🟡 Wait and returns the "task1" data, you can't use ".get()" function again after using it.
    task1.get();
    //      🟡 Just only wait to end the "task2".
    task2.wait();

    std::cout << std::format("Task being finished [Vector]: [{}, {}]", sharedData[0], sharedData[1])
              << std::endl;

    return 0;
}
