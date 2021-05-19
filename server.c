#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(){

    struct sockaddr_in sockAddr;
    const int PORT=8080;
    char *str = "Hi from server";

    int server_fd = socket(AF_INET,SOCK_STREAM, 0);
    if(server_fd < 0){
        perror("Socket creation failed");
        return 0;
    }
    fprintf(stdout, "Socket Created!");


    
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sockAddr.sin_port= htons(PORT);

    memset(sockAddr.sin_zero, "\0", sizeof(sockAddr.sin_zero));

    int bindVal = bind(server_fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));

    if(bindVal < 0){
        perror("Socket Binding failed");
        return 0;
    }
    fprintf(stdout, "\n\nSocket Binded!\n");

    

    int listenVal = listen(server_fd, 10);

    if(listenVal < 0){
        perror("Socket Listening failed");
        return 0;
    }

    while(1){
        fprintf(stdout, "\n---------Waiting for connection----------\n");
        int new_socket = accept(server_fd, (struct sockaddr *)&sockAddr, (socklen_t*)&addrlen)
        if(new_socket < 0){
            perror("Socket Accept failed");
            return 0;
        }
        fprintf(stdout, "\n\nServer Listening...!\n");



        char bufferMesg[25000] = {0};
        int mesgIn = read(new_socket, bufferMesg, 25000);
        fprintf(stdout, "\n\nMessage: +%s\n", bufferMesg);

        if(mesgIn < 0){
            fprintf(stdout, "No bytes read in");
        }

    
        write(new_socket, str, strlen(str));
        fprintf(stdout, "\n---------Message Sent----------\n");
        close(new_socket);

    }


}

