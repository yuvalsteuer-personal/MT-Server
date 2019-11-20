#ifndef TASK_H
#define TASK_H

#include <string>
#include <time.h>
#include <unistd.h>


enum TaskType{
    TIME,
    OS_VERSION,
    HOST_FILE
};

class Task{
private:
    bool m_repeat;
    int m_delay_factor;
    TaskType m_command_id;

public:
    Task(bool repeat, int delay_factor, TaskType command_id);

    void execute();
    
    std::string getTime();
    std::string getOSVersion();
    std::string getHostFile();
};



#endif