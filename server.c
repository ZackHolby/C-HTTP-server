#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(){

    struct sockaddr_in sockAddr;
    const int PORT=8080;

    int server_fd = socket(AF_INET,SOCK_STREAM, 0);
    if(server_fd < 0){
        perror("Socket creation failed");
        return 0;
    }
    fprintf(stdout, "Socket Created!");


    memset((char *) &sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sockAddr.sin_port= htons(PORT);

    int bindVal = bind(server_fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));

    if(bindVal < 0){
        perror("Socket Binding failed");
        return 0;
    }
    fprintf(stdout, "\n\nSocket Binded!\n");

    

    int listenVal = listen(server_fd, 3)

    if(listenVal < 0){
        perror("Socket Listening failed");
        return 0;
    }

    int new_socket = accept(server_fd, (struct sockaddr *)&sockAddr, (socklen_t*)&addrlen)
    if(new_socket < 0){
        perror("Socket Accept failed");
        return 0;
    }
    fprintf(stdout, "\n\nServer Listening...!\n");



}

