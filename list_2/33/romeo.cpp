#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
using namespace std;
int main() {
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus; 
    int listenStatus; 
    socklen_t clientSize;

    struct sockaddr_in address, client;

    ssize_t readBytes, writeBytes;
    char dataFromClient[100];

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1) {
        perror("Error while creating socket!");
        exit(1);
    }
    cout<<"Server side socket successfully created!"<<endl;

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1) {
        perror("Error while binding name to socket!");
        exit(1);
    }
    cout<<"Binding to socket was successful!"<<endl;

    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1) {
        perror("Error while trying to listen for connections!");
        exit(1);
    }
    cout<<"Now listening for connections on a socket!"<<endl;
    while(1){
        clientSize = sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1)
            perror("Error while accepting a connection!");
        else {
            
            writeBytes = write(connectionFileDescriptor, "I'm the server!", 15);
            if (writeBytes == -1)
                perror("Error while writing to network via socket!");
            else
                cout<<"Data sent to client!"<<endl;
            
            do{
                readBytes = read(connectionFileDescriptor, dataFromClient, 100);
                if (readBytes == -1)
                    perror("Error while reading from network via socket!");
                else {
                    dataFromClient[readBytes] = '\0'; 
                    cout<<"Data from client: "<<dataFromClient<<endl;
                }
            }while(readBytes!=-1 && readBytes>0);

            close(connectionFileDescriptor);
        
        }
    }

    close(socketFileDescriptor);

    return 0;
}
