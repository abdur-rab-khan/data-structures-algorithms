#pragma once

#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

#define DEFAULT_WORKERS 4

struct Task {
    // TODO: Make function that would take some arguments
    int                   taskId;
    std::function<void()> fn;
};

class Worker {
   public:
    Worker(std::queue<Task>& q, std::mutex& mtx, std::condition_variable& cv,
           std::atomic<bool>& stop);

    void operator()();

   private:
    std::queue<Task>&        task;
    std::mutex&              mtx;
    std::condition_variable& cv;
    std::atomic<bool>&       stop;
};

class ThreadPool {
   public:
    ThreadPool();
    ~ThreadPool();

    void pushTask(Task task);

   private:
    std::condition_variable              cv;
    std::queue<Task>                     task;
    std::vector<std::thread>             pool;
    std::mutex                           taskLock;
    std::vector<std::unique_ptr<Worker>> workers;
    std::atomic<bool>                    stop = false;
};
