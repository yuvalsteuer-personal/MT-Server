#include "../headers/worker.h"

WorkerThread::WorkerThread(TaskQueue* task_queue){
    m_id = counter;
    ++counter;
    isBusy = false; 
    sharedTaskQueue = std::make_shared<TaskQueue>(task_queue);

}

void WorkerThread::start(void){
    std::thread workerThread(work);
    worker_thread = &workerThread;
}
void WorkerThread::work(void){
    while(true){
        Task task = sharedTaskQueue.get()->pop();
        task.execute();
    }
}

void WorkerThread::stop(void){
    worker_thread->join();
}