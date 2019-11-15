#include "task_parser.h"


static std::vector<std::string> TaskParser::split(std::string sentence){
    std::vector<std::string> wordVector;
    std::string word = "";
    for(char c:sentence){
        if(c == ' '){
            wordVector.push_back(word);
            word = "";
            break;
        }
        word += c;
    }
    return wordVector;
}

static Task TaskParser::generateTask(std::vector<std::string> wordVector){
    TaskType command_id;
    bool repeat = false;
    int delay_factor = 0;

    std::vector<Task> taskVector;
    std::stack<std::string> argumentStack;

    for(const std::string& word : wordVector){
        if(not argumentStack.empty()){
            std::string flag = argumentStack.pop();
            if(flag == "--command-id"){
                command_id = atoi(word);
            }
            else if(flag == "--delay-factor"){
                delay_factor = atoi(word);
            }
            else if(flag == "--repeat"){
                bool value = false;
                if(value == "true"){
                    value = true;
                }
                else if(value == "false"){
                    value = false;
                }
                else{
                    throw std::invalid_argument();;
                }
            }
            else{
                throw std::invalid_argument();
            }
        }
        else {
            if (word == "--command-id") {
                stack.push(word)
            }
            else if(word == "--repeat"{
                stack.push(word);
            }
                    else if(word == "--delay-factor"){
                stack.push(word);
            }
            else{
                throw std::invalid_argument();
            }
        }
    }
    return Task(repeat, delay_factor, command_id);
}