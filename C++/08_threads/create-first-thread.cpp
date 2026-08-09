#include <bits/chrono.h>

#include <format>
#include <functional>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void task(int num) {
    std::this_thread::sleep_for(2000ms);
    std::cout << std::endl << std::format("Task {} is finished!!", num) << std::endl;
}

void calculate(int a, int b) {
    std::cout << std::format("Sum is: {}", a + b);
}

void modifyX(int& x) {
    x = 500;
}

int main() {
    int x = 10;

    // 🔶 A new thread is created.
    // 🔸 task1() starts executing in that new thread.
    // 🔸 The main thread does not wait here.
    // 🔸 Main immediately continues to the next statement.
    std::thread t1(task, 1);

    // 🔶 Another thread is created, don't wait for "t1" to finish.
    // 🔸 task2() starts executing in that thread.
    // 🔸 Main again does not wait.
    std::thread t2(task, 2);

    // 🔶 Sum of two number using threads
    std::thread sum1(calculate, 25, 75);

    // 🔶 Let's modify x with 500
    std::thread m(modifyX, std::ref(x));
    m.join();
    std::cout << "Now x is: " << x << std::endl;

    t1.join();
    t2.join();
    sum1.join();

    std::cout << "Tasks is finished" << std::endl;
}
