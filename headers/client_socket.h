#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <string>
#include <netdb.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#define ERROR                   1
#define SOCKET_FD               int
#define SOCKADDR                struct sockaddr
#define SOCKADDR_IN             struct sockaddr_in
#define BACKSPACE_REMOVE        "\b\b\b\b\b"


int checkError(int x, const char* errorMsg);


class ClientSocket{
private:
    bool debug_mode;
    bool is_sock_open;
    SOCKET_FD m_sockfd;
    struct sockaddr_in serv_addr; 

public:
    ClientSocket(std::string hostAddress, int port, bool debug_mode=true);
    ~ClientSocket(void);

    int close(void);
    int connect(void);
    int write(std::string message);
    void setServerAddress(std::string hostAddress, int port);

};
#endif