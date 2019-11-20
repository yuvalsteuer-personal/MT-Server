#include "../headers/task_queue.h"

TaskQueue::TaskQueue(void){
    has_limit = false;
}

TaskQueue::TaskQueue(size_t limit){
    has_limit = true;
    m_limit = limit;
}

Task TaskQueue::top(void) const{

}

void TaskQueue::push_back(Task& task){
    {
        std::unique_lock<std::mutex> lock(this->m_mutex);
        m_queue.push_back(task);
    }
    this->m_condition.notify_one();
}

Task TaskQueue::pop(void){
    std::unique_lock<std::mutex> lock(this->m_mutex);
    this->m_condition.wait(lock, [=]{ return !this->m_queue.empty(); });
    Task task(std::move(this->m_queue.front()));
    this->m_queue.pop_front();
    return task;
}

