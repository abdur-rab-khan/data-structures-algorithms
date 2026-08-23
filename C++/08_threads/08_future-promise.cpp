// 🟡 In C++, "promise" is used to get a result from a thread once value/exception begin set, instead of waiting for thread to finishes the task.
// 🔶 Before promise data fulfilled, we must have to get the future using ".get_future", 👉 and for wait use ".get/.wait/.wait_for"
#include <exception>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <utility>

using namespace std::chrono_literals;

void task() {
    std::this_thread::sleep_for(2s);
    std::cout << "[Finished] Task is begin completed" << std::endl;
}

int heavyCalculation(std::promise<int> p, bool doException = false) {
    std::this_thread::sleep_for(0.5s);

    if (doException) {
        p.set_exception(
            std::make_exception_ptr(std::runtime_error("You choose to have a exception")));
    } else {
        p.set_value(500);
    }

    // Demo, creating new thread for the task
    std::thread t(task);
    t.join();  // Wait until finishes

    return 1000;
}

int main() {
    std::promise<int> promise;
    std::future<int>  future = promise.get_future();

    // 🔷 WITHOUT ANY EXCEPTION
    // 🟡 Spawn a thread like this, or using "async"
    // std::thread t(heavyCalculation, std::move(promise));
    auto calResult = std::async(std::launch::async, heavyCalculation, std::move(promise), false);

    int result = future.get();
    std::cout << "Promise Result is: " << result << std::endl;

    int cal = calResult.get();
    std::cout << "Calculation Result is: " << cal << std::endl;

    // 🔷 WITH EXCEPTION
    std::promise<int> newPromise;
    std::future<int>  newFuture = newPromise.get_future();

    try {
        auto ex = std::async(std::launch::async, heavyCalculation, std::move(newPromise), true);
        newFuture.get();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception from the thread: " << e.what() << std::endl;
    }

    return 0;
}
