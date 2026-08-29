#include "thread-pool.h"

#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <format>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

// <------------------------> WORKER IMPLEMENTATION <------------------------>
Worker::Worker(std::queue<Task>& q, std::mutex& mtx, std::condition_variable& cv,
               std::atomic<bool>& stop)
    : task(q), mtx(mtx), cv(cv), stop(stop) {}

void Worker::operator()() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this]() { return !task.empty() || stop; });

        if (stop && task.empty()) {
            break;
        }

        auto t = task.front();
        task.pop();
        std::cout << std::format("[Worker]: Took Job: {} for process", t.taskId) << std::endl;

        // Unlock so that other workers can pull tasks
        lock.unlock();

        // Call fn to execute task
        t.fn();

        std::cout
            << std::format(
                   "<-------------------------> {} FINISHED EXECUTION <------------------------->",
                   t.taskId)
            << std::endl;
    }
}

// <------------------------> THREAD IMPLEMENTATION <------------------------>
ThreadPool::ThreadPool() {
    for (size_t i = 0; i < DEFAULT_WORKERS; i++) {
        auto worker = std::make_unique<Worker>(task, taskLock, cv, stop);
        workers.push_back(std::move(worker));
        pool.push_back(std::thread(std::ref(*workers.back())));
    }
}

ThreadPool::~ThreadPool() {
    // Destroy the workers
    stop.store(true);
    cv.notify_all();

    // Join the thread
    for (auto& thread : pool) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void ThreadPool::pushTask(Task t) {
    std::lock_guard<std::mutex> lock(taskLock);
    task.push(t);
    cv.notify_one();
}
