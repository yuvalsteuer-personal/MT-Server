#include <string>
#include <stdio.h> 
#include <netdb.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#include "client_socket.h"

#define ERROR                   1
#define SOCKET_FD               int
#define BACKSPACE_REMOVE        "\b\b\b\b\b"


int checkError(int x, const char* errorMsg);


int main(int argc, char** argv){
    auto client = ClientSocket("127.0.0.1", 8080);
    if(client.connect()){
        return ERROR;
    }
    char* buffer = "exit";
    printf("test");
    if(client.write(buffer)){
        return ERROR;
    }
    client.close();
    return 0;
}

int checkError(int x, const char* errorMsg){
    if(x<0){
        std::cerr << "\n" << errorMsg << std::endl;
        return -1;
    }
    return 0;
}