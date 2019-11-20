#include "../headers/thread_pool.h"

ThreadPool::ThreadPool(int n, TaskQueue* taskQueue) {
    this->taskQueue = taskQueue;
    workerVector.reserve(n);
    for(int w = 0; w < n; w++){
        workerVector[w] = WorkerThread(taskQueue);
    }
    for(int w = 0; w < n; w++){
        workerVector[w].start();
    }
};
