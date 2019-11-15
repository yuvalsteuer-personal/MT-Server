#ifndef TASK_PARSER_H
#define TASK_PARSER_H


#include "task.h"

#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <exception>


#define PLACE_HOLDER    0


class TaskParser{

public:
    static std::vector<std::string> split(std::string sentence);
    static Task generateTask(std::vector<std::string> wordVector);
};


#endif