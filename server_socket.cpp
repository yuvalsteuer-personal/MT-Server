#include "server_socket.h"





ServerSocket::ServerSocket(void){
    this->debug_mode = debug_mode;
    if(debug_mode){
        std::cout << "opening socket... [0/1]";
    }
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "[1/1]\n";
    }
    is_sock_open = true; 
        
}
int ServerSocket::bind(int port){
    bzero((char*)&m_serv_addr, sizeof(m_serv_addr));
    m_serv_addr.sin_family = AF_INET;
    m_serv_addr.sin_addr.s_addr = INADDR_ANY;
    m_serv_addr.sin_port = htons(port);
    if(debug_mode){
        std::cout << "binding... [0/1]";
    }
    int x = ::bind(m_sockfd, (SOCKADDR*)&m_serv_addr, sizeof(m_serv_addr));
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE  << "[1/1]\n" << std::endl;
    }
    if(checkError(x, "ERROR on bind!")){
        return -1;
    }
    return 0;
}

int ServerSocket::listen(void){
    if(debug_mode){
        std::cout << "listening... [0/1]";
    }
    int x = ::listen(m_sockfd, 100);
    if(checkError(x, "ERROR on listen!\n")){
        return -1;
    }
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "\b\b\b\b! [1/1]\n";
    }
    return 0;
}

int ServerSocket::accept(void){
    socklen_t clilen = sizeof(m_cli_addr);
    if(debug_mode){
        std::cout << "waiting for connections... [0/1]" << std::endl;
    }
    m_comms_sockfd = ::accept(m_sockfd, (SOCKADDR*)&m_cli_addr,(socklen_t*)&clilen);
    if(checkError(m_comms_sockfd, "ERROR on accept!")){
        return -1;
    }
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "[1/1]\n";
    }
    return 0;
}

int ServerSocket::read(char* buffer, size_t buffSize){
    if(debug_mode){
        std::cout << "Reading to buffer... [0/1]";
    }
    int x = ::read(m_comms_sockfd, buffer, buffSize);
    if(checkError(x, "ERROR on read!")){
        return -1;
    }
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "\b\b\b\b! [1/1]\n";
    }
    return 0;
}

int ServerSocket::write(std::string message){
    if(debug_mode){
        std::cout << "writing to server... [0/1]";
    }
    int x = ::write(m_sockfd, message.c_str(), message.length());
    if(checkError(x, "writing to host failed!") == -1){
        return -1;
    }
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "\b\b\b\b! " << "[1/1]\n" << std::endl;
    }
    return 0;
}