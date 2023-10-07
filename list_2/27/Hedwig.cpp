// same as 26th but flag changed
#include <iostream>
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <cerrno>      
#include <cstdlib>     
#include <ctime>       
using namespace std;
int main()
{
    key_t queueKey;        
    int queueIdentifier;   
    int messageSendStatus; 

    struct msgbuf
    {
        long mtype;     
        int someNumber; 
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!");
        exit(0);
    }

    data.mtype = 1;
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), IPC_NOWAIT);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!");
        exit(0);
    }

    cout<<"Message sent! Check using `ipcs -q`"<<endl;

    return 0;
}
