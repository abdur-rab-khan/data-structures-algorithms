#include <cmath>
#include <memory>
#include <thread>

#include "thread-pool.h"

using namespace std;
using namespace chrono_literals;

auto cpuTask = []() {
    volatile double result = 0.0;

    for (long long i = 0; i < 500'000'000'0; ++i) {
        result += std::sqrt(static_cast<double>(i));
    }
};

int main() {
    std::unique_ptr<ThreadPool> threadPool = make_unique<ThreadPool>();

    threadPool->pushTask(Task {1001, cpuTask});
    threadPool->pushTask(Task {1002, cpuTask});
    threadPool->pushTask(Task {1003, cpuTask});
    threadPool->pushTask(Task {1004, cpuTask});
    threadPool->pushTask(Task {1005, cpuTask});
    threadPool->pushTask(Task {1006, cpuTask});

    this_thread::sleep_for(2s);

    threadPool->pushTask(Task {1007, cpuTask});
    threadPool->pushTask(Task {1008, cpuTask});
    threadPool->pushTask(Task {1009, cpuTask});
    threadPool->pushTask(Task {1010, cpuTask});
    threadPool->pushTask(Task {1011, cpuTask});
    threadPool->pushTask(Task {1012, cpuTask});

    return 0;
}
