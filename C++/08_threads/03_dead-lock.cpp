// 🟡 A deadlock occurs when two or more threads are waiting for resources held by each other, so none of them can continue.

#include <process.h>
#include <processthreadsapi.h>
#include <sys/types.h>
#include <unistd.h>
#include <windows.h>

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtxA;
std::mutex mtxB;

// 🔷 Following functions creates a "DEADLOCK" situation because "task1" is waiting for "mtxB" and "task2" is waiting for "mtxA".
// 🔹 There are few solutions to prevant "DEADLOCK" situation:
//      1. Consistent Lock Order:
//                  ❌ task1 -> mtxA -> waiting for -> mtxB -> already taken by task2 -> mtxB waiting for mtxA
//                  ✅ task1 -> A -> B
//                  ✅ task2 -> A -> B
//
//      2. Scoped Lock: Used to lock mutiple mutex, unlike "lock_guard" who one locks one "mutex" at a time
//                  🟡 std::scoped_lock lock(mtxA, mtxB)
//
//      3. "std::try_lock" (do later)

// "DEADLOCK" function:
void task1() {
    std::lock_guard<std::mutex> lockA(mtxA);
    std::cout << "Waiting for mtx B" << std::endl;
    std::lock_guard<std::mutex> lockB(mtxB);
}

void task2() {
    std::lock_guard<std::mutex> lockA(mtxB);
    std::cout << "Waiting for mtx A" << std::endl;
    std::lock_guard<std::mutex> lockB(mtxA);
}

void deadLock() {
    pid_t pId = getpid();

    std::thread t1(task1);
    std::thread t2(task2);

    std::cout << "Process ID is: " << pId << std::endl;

    t1.join();
    t2.join();
}

// "NO DEADLOCK":
void t1() {
    std::scoped_lock lock(mtxA, mtxB);
    std::cout << "T1 is completed" << std::endl;
}

void t2() {
    std::scoped_lock lock(mtxA, mtxB);
    std::cout << "T2 is completed" << std::endl;
}

void withoutDeadLock() {
    std::thread th1(t1);
    std::thread th2(t2);

    th1.join();
    th2.join();
}

int main() {
    deadLock();
    withoutDeadLock();
    return 0;
}
