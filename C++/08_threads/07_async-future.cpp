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

    task1.get();
    task2.get();
    std::cout << std::format("Task being finished [Vector]: [{}, {}]", sharedData[0], sharedData[1])
              << std::endl;

    return 0;
}
