#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int main() {
    int socketFileDescriptor; 
    int connectStatus;        

    struct sockaddr_in address; 

    ssize_t readBytes, writeBytes; 
    char dataFromServer[100];

    
    
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1) {
        perror("Error while creating socket!");
        exit(1);
    }
    cout << "Client side socket successfully created!" << endl;

    
    cout<<(uint32_t)INADDR_ANY<<endl;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1) {
        perror("Error while connecting to the server!");
        exit(1);
    }
    cout << "Client to server connection successfully established!" << endl;

    
    readBytes = read(socketFileDescriptor, dataFromServer, 100);
    if (readBytes == -1)
        perror("Error while reading from the network via socket!");
    else {
        dataFromServer[readBytes] = '\0'; 
        cout << "Data from server: " << dataFromServer << endl;
    }

    writeBytes = write(socketFileDescriptor, "I'm the client!", 15);
    if (writeBytes == -1)
        perror("Error while writing to the network via socket!");
    else
        cout << "Data sent to server!" << endl;
    

    close(socketFileDescriptor);

    return 0;
}
