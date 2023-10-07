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
    struct msqid_ds messageQueueInfo; 
    int msgctlStatus;                 

    queueKey = ftok(".", 1);
    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        exit(0);
    }

    cout<<"Key: "<<queueKey<<endl;
    cout<<"Message Queue Identifier: "<<queueIdentifier<<endl<<endl;

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        exit(0);
    }

    cout<<"Access Permission: "<<oct<<messageQueueInfo.msg_perm.mode<<dec<<endl;
    cout<<"UID: "<<messageQueueInfo.msg_perm.uid<<endl;
    cout<<"GID: "<<messageQueueInfo.msg_perm.gid<<endl;
    cout<<"Time of last message sent: "<<ctime(&messageQueueInfo.msg_stime);
    cout<<"Time of last message received: "<<ctime(&messageQueueInfo.msg_rtime);
    cout<<"Size of queue: "<<messageQueueInfo.__msg_cbytes<<" bytes"<<endl;
    cout<<"Number of messages in the queue: "<<messageQueueInfo.msg_qnum<<endl;
    cout<<"Maximum number of bytes allowed in the queue: "<<messageQueueInfo.msg_qbytes<<" bytes"<<endl;
    cout<<"PID of last sent message: "<<messageQueueInfo.msg_lspid<<endl;
    cout<<"PID of last received message: "<<messageQueueInfo.msg_lrpid<<endl;

    return 0;
}