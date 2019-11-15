#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 


#define ERROR               1
#define SOCKADDR            struct sockaddr
#define SOCKET_FD           int
#define SOCKADDR_IN         struct sockaddr_in
#define BACKSPACE_REMOVE    "\b\b\b\b\b"

int checkError(int x, const char* errorMsg);

class ServerSocket{

private:
    bool is_sock_open;
    bool debug_mode                 ;
    socklen_t m_clilen              ;
    SOCKET_FD m_sockfd              ;
    SOCKET_FD m_comms_sockfd        ;
    SOCKADDR_IN m_cli_addr          ;
    SOCKADDR_IN m_serv_addr         ;

public:
    ServerSocket(void);
    int bind(int port=8080);
    int listen();
    int accept();
    int read(char* buffer, size_t buffSize=1024);
    int write(std::string message);
};

int checkError(int x, const char* errorMsg);

#endif