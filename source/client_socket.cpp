#include "../headers/client_socket.h"

ClientSocket::ClientSocket(std::string hostAddress, int port, bool debug_mode){
    this->debug_mode = debug_mode;
    if(debug_mode){
        std::cout << "opening socket... [0/1]";
    }
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "[1/1]\n";
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostAddress.c_str());
    serv_addr.sin_port = htons(port);
    is_sock_open = true;
}

void ClientSocket::setServerAddress(std::string hostAddress, int port){
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostAddress.c_str());
    serv_addr.sin_port = htons(port);
}

int ClientSocket::connect(void){
    if(debug_mode){
        std::cout << "connection established... [0/1]";
    }
    SOCKET_FD x = ::connect(
        m_sockfd,
        (struct sockaddr *) &serv_addr,
        sizeof(serv_addr)
    );
    if(checkError(x, "\nconnecting to host failed!") == -1){
        return -1;
    }
    if(debug_mode){
        std::cout << BACKSPACE_REMOVE << "\b\b\b\b!" << "[1/1]\n" << std::endl;
    }
    return 0;
}

int ClientSocket::write(std::string message){
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

int ClientSocket::close(){
    is_sock_open = false;
    int x = ::close(m_sockfd);
    if(checkError(x, "Failed closing client socket!")){
        return ERROR;
    }
    if(debug_mode){
        std::cout << "closing socket... [1/1]\n";
    }
    return 0;
}

ClientSocket::~ClientSocket(){
    if(is_sock_open){
        close();
    }
}
