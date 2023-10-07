#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void communicate(int *fd) {
    ssize_t readBytes, writeBytes;
    char dataFromClient[100];

    // Server - Client communication
    writeBytes = write(*fd, "I'm the server!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to client!\n");

    readBytes = read(*fd, dataFromClient, 100);
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from client: %s\n", dataFromClient);

    close(*fd);
}

int main() {
    int sockfd, connfd;
    int bind_status;
    int listen_status;
    int client_size;

    struct sockaddr_in server_address, client_address;

    pthread_t thread_id;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        _exit(0);
    }
    printf("Server side socket successfully created!\n");

    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    bind_status = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status == -1) {
        perror("Error binding socket");
        _exit(0);
    }
    printf("Binding to socket was successful!\n");

    listen_status = listen(sockfd, 2);
    if (listen_status == -1) {
        perror("Error listening for connections");
        _exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    while (1) {
        client_size = sizeof(client_address);
        connfd = accept(sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_size);
        if (connfd == -1)
            perror("Error while accepting a connection!");
        else {
            if (pthread_create(&thread_id, NULL, (void *(*)(void *))communicate, &connfd))
                perror("Error while creating thread");
        }
    }

    close(sockfd);

    return 0;
}
