

#include "server_socket.h"



int main(int argc, char** argv)
{
    SOCKADDR_IN cli_addr;
    SOCKADDR_IN serv_addr;
    
    int x = 0;
    int sockfd = 0;
    int newsockfd = 0;
    socklen_t clilen = 0;
    char buffer[1024] = {0};

    auto server_socket = ServerSocket(); 
    if(server_socket.bind(8080)){
        return ERROR;
    }
    if(server_socket.listen()){
        return ERROR;
    }

    size_t i = 0;
    bool first = true;
    while(strcmp(buffer, "exit")){
        if(first){
            first = false;
        }
        x = server_socket.accept();
        if(x){
            return ERROR;
        }
        if(server_socket.read(buffer)){
            return ERROR;
        }

        std::cout << i << ". " << buffer << std::endl;
        if(strcmp(buffer, "exit")){
            bzero(buffer, strlen(buffer));
        }
        ++i;
    }
    printf("Done!\n");
    return 0;
}

int checkError(int x, const char* errorMsg){
    if(x<0){
        std::cerr << "\n" << errorMsg << std::endl;
        return -1;
    }
    return 0;
}