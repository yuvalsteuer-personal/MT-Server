#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "task.h"
#include "worker.h"
#include "task_queue.h"

class ThreadPool {
private:
    std::vector<WorkerThread> workerVector;
    TaskQueue* taskQueue;
public:
    ThreadPool(int n, TaskQueue* taskQueue);

};

#endif