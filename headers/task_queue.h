#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H


#include <deque>
#include <mutex>
#include <vector>
#include <condition_variable>


#include "task.h"


class TaskQueue{
private:
    bool has_limit;
    size_t m_limit;
    std::mutex m_mutex;
    std::deque<Task> m_queue;
    std::condition_variable m_condition;

public:
    TaskQueue(void );
    TaskQueue(size_t limit);

    Task top(void) const;
    Task pop(void);
    void push_back(Task& task);

    
};

#endif