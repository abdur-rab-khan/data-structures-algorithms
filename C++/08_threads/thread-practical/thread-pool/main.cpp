#include <array>
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

    std::array<int, 5> batch1 = {1001, 1002, 1003, 1004, 1005};
    std::array<int, 5> batch2 = {1006, 1007, 1008, 1009, 1010};

    for (const int& jobId : batch1) {
        threadPool->pushTask(Task {jobId, cpuTask});
    }

    this_thread::sleep_for(2s);

    for (const int& jobId : batch2) {
        threadPool->pushTask(Task {jobId, cpuTask});
    }

    return 0;
}
