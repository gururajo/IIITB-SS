#include <iostream>
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <cerrno>      
#include <cstdlib>     
using namespace std;

int main()
{
    key_t msgQueueKey;                
    int msgQueueIdentifier;           
    struct msqid_ds msgQueueInfo;     
    int msgctlStatus;                 

    msgQueueKey = ftok(".", 1);

    msgQueueIdentifier = msgget(msgQueueKey, IPC_CREAT | 0700);

    cout<<"Message Queue Key: "<<msgQueueKey<<endl;
    cout<<"Message Queue Identifier: "<<msgQueueIdentifier<<endl<<endl;
    cin.ignore();
    
    msgctlStatus = msgctl(msgQueueIdentifier, IPC_RMID, NULL);

    return 0;
}
