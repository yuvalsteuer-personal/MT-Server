#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include <memory>

#include "task.h"
#include "task_queue.h"


class WorkerThread{
private:
    static int counter;
    int m_id;
    bool isBusy;
    std::shared_ptr<TaskQueue> sharedTaskQueue;

public:
    WorkerThread(TaskQueue* task_queue);
    void start(void);
    void work(void);
    
};

#endif