#include "task.h"

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
    if(m_delay_factor){
        switch(m_command_id){
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
std::string getTime() {
    return "12:00:00";
}
std::string getOSVersion() {
    return "Linux";
}
std::string getHostFile() {
    return "<html><h1> Hello, World! </h1></html>";
}