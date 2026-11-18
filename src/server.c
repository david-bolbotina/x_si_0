#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>      
#include <sys/socket.h>  
#include <netinet/in.h>  
#define PORT 8080

int main(){
    int server_fd;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Socket created successfully\n");
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    int bind_result = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    if(bind_result < 0){
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    else{
        printf("Bind successful at port %d\n", PORT);
    }

    int listen_result = listen(server_fd, 3);
    if(listen_result < 0){
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    else{
        printf("Listening for connections on port %d\n", PORT);
    }

    socklen_t addrlen = sizeof(address);
    int new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if(new_socket < 0){
        perror("accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    else{
        printf("Client connected successfully\n");
    }
    
    close(new_socket);
    close(server_fd);
    return 0;
}