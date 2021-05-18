#include <sys/socket.h>
#include <netinet/in.h>

int main(){

    struct sockaddr_in sockAddr;
    const int PORT=8080;

    int server_fd = socket(AF_INET,SOCK_STREAM, 0);
    if(server_fd < 0){
        perror("Socket creation failed");
        return 0;
    }
    fprintf("Socket Created!");

    


}

