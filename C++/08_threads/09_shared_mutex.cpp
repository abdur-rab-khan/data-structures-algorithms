// 🟡 Shared Mutex, fit beautifully in a situation where we thread that is not updating anything just reading it and we don't need to lock them but a thread who writes it need to have shared data for only one thread.
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

using namespace std::chrono_literals;

std::shared_mutex mtx;

void writing(int id) {
    // 🟡 For Writing, mean multiple thread with this lock can get the data simultaneously
    std::shared_lock<std::shared_mutex> lock(mtx);

    std::cout << "[Writing " << id << "] START\n";

    std::this_thread::sleep_for(4s);

    std::cout << "[Writer " << id << "] END\n";
}

void reader(int id) {
    // 🟡 For Reading, mean only one thread can access the shared data
    std::unique_lock<std::shared_mutex> lock(mtx);

    std::cout << "[Reader " << id << "] START\n";

    std::this_thread::sleep_for(4s);

    std::cout << "[Reader " << id << "] END\n";
}

int main() {
    std::thread r1(reader, 1);
    std::thread r2(reader, 2);
    std::thread r3(reader, 3);
    std::thread r4(reader, 4);

    std::thread w1(writing, 1);

    r1.join();
    r2.join();
    r3.join();
    r4.join();
    w1.join();

    return 0;
}
