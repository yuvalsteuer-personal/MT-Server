#include "../headers/task.h"
#define SECONDS 100000

Task::Task(bool repeat, int delay_factor, TaskType command_id) {
    this->m_repeat = repeat;
    this->m_command_id = command_id;
    this->m_delay_factor = delay_factor;
}

enum TaskType{
    TIME,
    OS_VERSION,
    HOST_FILE
};

void Task::execute(){
    std::string time, osVersion, hostFile;
    size_t repeat = 1;
    if(m_repeat) {
        repeat++;
    }
    for(int i = 0; i < repeat;i++) {
        if (m_delay_factor) {
            usleep(m_delay_factor * SECONDS);
        }
        switch (m_command_id) {
            case TaskType::TIME:
                time = getTime();
                break;
            case TaskType::OS_VERSION:
                osVersion = getOSVersion();
                break;
            case TaskType::HOST_FILE:
                hostFile = getHostFile();
                break;
        }
    }
}
std::string Task::getTime() {
    return "12:00:00";
}
std::string Task::getOSVersion() {
    return "Linux";
}
std::string Task::getHostFile() {
    return "<html><h1> Hello, World! </h1></html>";
}