#include <iostream>
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/shm.h>   
#include <unistd.h>    
#include <cstdio>      
#include <cstring>     
using namespace std;
int main()
{
    key_t shmKey;         
    int shmIdentifier;    
    ssize_t shmSize = 20; 
    char *shmPointer, *rdOnlyShmPointer;

    shmKey = ftok(".", 1);
    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700); 
    shmPointer = (char *)shmat(shmIdentifier, nullptr, 0) ;

    cout << "Press enter to write to the shared memory!" << endl;
    cin.ignore();
// 11111111111111111111111111111111111111111111111111111111111111111111111111111
    sprintf(shmPointer, "Yolo"); 

    cout << "Press enter to read from the shared memory!" << endl;
    cin.ignore();

    cout << "Data from shared memory: " << shmPointer << endl; 

    
// 2222222222222222222222222222222222222222222222222222222222222222222222222222222222
    
    rdOnlyShmPointer = (char * )shmat(shmIdentifier, nullptr, SHM_RDONLY);
    if (rdOnlyShmPointer == (char *)(-1))
    {
        perror("Error while attaching address space!");
        _exit(0);
    }

    
    

    cout << "Press enter to read from the shared memory!" << endl;
    cin.ignore();

    cout << "Data from shared memory (Read-only): " << rdOnlyShmPointer << endl; 

    
// 333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    
    cout << "Detaching pointer to shared memory!" << endl;
    shmdt(shmPointer);       
    shmdt(rdOnlyShmPointer); 
    
// 444444444444444444444444444444444444444444444444444444444444444444444444444444
    
    cout << "Press enter to delete the shared memory!" << endl;
    cin.ignore();

    
    shmctl(shmIdentifier, IPC_RMID, nullptr);
    

    return 0;
}
