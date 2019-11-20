#include <queue>

#include "headers/server_socket.h"
#include "headers/thread_pool.h"


#define SOCKET_FD   int

struct Response {
    int Id;
    std::string Result;

    Response(int id, std::string result): Id(id), Result(result){}
};
struct ClientConnection{
    int id;
    SOCKET_FD socket_fd;

    ClientConnection(int id, SOCKET_FD socket_fd){
        this->id = id;
        this->socket_fd = socket_fd;
    }

    int getId()const {
        return id;
    }
    SOCKET_FD getSocketFD() const {
        return socket_fd;
    }

};
struct AnswerQueue{
private:
    std::queue<Response*> responseQueue;

public:
    AnswerQueue(){}

    void push(Response* response){
        responseQueue.push(response);
    }
    Response* pop(void){
        return nullptr;
    }

};
int main(int argc, char** argv)
{
    std::vector<ClientConnection> connectionPool;
    AnswerQueue respQueue;
    respQueue.push(1);
    TaskQueue taskQueue;
    ThreadPool threadPool(2, &taskQueue);
    int id = 0;
    bool flag = true;
    while(flag){
        auto client = 1;
        connectionPool.push_back(ClientConnection(id, 0));

        for(long i = 0;i < connectionPool.size(); i++){
            for(long j = 0; j < connectionPool.size(); j++){

            }
        }
        if(client){
            flag = false;
        }
        id++;
    }

    int x = 0;
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