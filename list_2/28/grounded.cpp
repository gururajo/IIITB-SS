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

    msgctlStatus = msgctl(msgQueueIdentifier, IPC_STAT, &msgQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        exit(0);
    }

    cout<<"Press enter to change the permissions!"<<endl;
    cin.ignore();

    msgQueueInfo.msg_perm.mode = 0777;

    msgctl(msgQueueIdentifier, IPC_SET, &msgQueueInfo);

    return 0;
}
