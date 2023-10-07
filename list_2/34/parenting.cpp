#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int sockfd, connfd;
    int bind_status;
    int listen_status;
    int client_size;

    struct sockaddr_in server_address, client_address;

    ssize_t read_bytes, write_bytes;
    char data_from_client[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        _exit(0);
    }

    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    bind_status = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status == -1) {
        perror("Error binding socket");
        _exit(0);
    }

    listen_status = listen(sockfd, 2);
    if (listen_status == -1) {
        perror("Error listening for connections");
        _exit(0);
    }

    printf("Listening for connections on port 8080...\n");

    while (1) {
        client_size = sizeof(client_address);
        connfd = accept(sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_size);
        if (connfd == -1) {
            perror("Error accepting connection");
        } else {
            if (fork() == 0) {
                write_bytes = write(connfd, "I'm the server!", 15);
                if (write_bytes == -1) {
                    perror("Error writing to socket");
                } else {
                    printf("Data sent to client!\n");
                }
                while(1){
                    read_bytes = read(connfd, data_from_client, sizeof(data_from_client));
                    if (read_bytes == -1) {
                        perror("Error reading from socket");
                    } else {
                        printf("Data from client: %s\n", data_from_client);
                    }
                }
                _exit(0);
            } else {
                close(connfd);
            }
        }
    }

    close(sockfd);

    return 0;
}
