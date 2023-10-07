#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

// Function to create or get a semaphore
int createOrGetSemaphore(key_t semKey, int initialValue) {
    int semIdentifier = semget(semKey, 1, IPC_CREAT | IPC_EXCL | 0666);

    if (semIdentifier == -1) {
        semIdentifier = semget(semKey, 1, 0666);
        if (semIdentifier == -1) {
            perror("Error while creating/getting semaphore!");
            exit(1);
        }
    } else {
        union semun {
            int val;
            struct semid_ds *buf;
            unsigned short *array;
        } semSet;
        semSet.val = initialValue;
        if (semctl(semIdentifier, 0, SETVAL, semSet) == -1) {
            perror("Error while initializing semaphore!");
            exit(1);
        }
    }

    return semIdentifier;
}

int main() {
    // Initialize semaphore for protecting critical section
    key_t critSemKey = ftok(".", 1);
    int critSemId = createOrGetSemaphore(critSemKey, 1);

    // Create or access shared memory
    key_t shmKey = ftok(".", 2);
    int shmId = shmget(shmKey, sizeof(int), IPC_CREAT | 0666);

    if (shmId == -1) {
        perror("Error while creating/accessing shared memory!");
        exit(1);
    }

    int *sharedValue = (int *)shmat(shmId, NULL, 0);
    if (sharedValue == (int *)(-1)) {
        perror("Error while attaching shared memory!");
        exit(1);
    }

    // Protect shared memory with semaphore
    key_t memSemKey = ftok(".", 3);
    int memSemId = createOrGetSemaphore(memSemKey, 1);

    // Counting semaphore example
    key_t countSemKey = ftok(".", 4);
    int countSemId = createOrGetSemaphore(countSemKey, 2); // Initialize to 2

    // ========== Start of Critical Section ==========
    struct sembuf critSemOp;
    critSemOp.sem_num = 0;
    critSemOp.sem_flg = 0;

    std::cout << "Press enter to obtain lock on the critical section" << std::endl;
    getchar();

    critSemOp.sem_op = -1; // Lock the critical section
    if (semop(critSemId, &critSemOp, 1) == -1) {
        perror("Error while locking the critical section!");
        exit(1);
    }

    std::cout << "Obtained lock on the critical section!" << std::endl;
    std::cout << "Now entering critical section!" << std::endl;

    // Simulate critical section by incrementing shared value
    (*sharedValue)++;
    std::cout << "Shared value: " << *sharedValue << std::endl;

    critSemOp.sem_op = 1; // Unlock the critical section
    if (semop(critSemId, &critSemOp, 1) == -1) {
        perror("Error while unlocking the critical section!");
        exit(1);
    }
    std::cout << "Released lock on the critical section!" << std::endl;
    // ========== End of Critical Section ===========

    // Protect shared memory with semaphore
    struct sembuf memSemOp;
    memSemOp.sem_num = 0;
    memSemOp.sem_flg = 0;
    memSemOp.sem_op = -1; // Lock shared memory
    if (semop(memSemId, &memSemOp, 1) == -1) {
        perror("Error while locking shared memory!");
        exit(1);
    }

    // Modify shared memory value
    *sharedValue += 100;

    memSemOp.sem_op = 1; // Unlock shared memory
    if (semop(memSemId, &memSemOp, 1) == -1) {
        perror("Error while unlocking shared memory!");
        exit(1);
    }

    std::cout << "Shared memory updated. New value: " << *sharedValue << std::endl;

    // Counting semaphore example
    struct sembuf countSemOp;
    countSemOp.sem_num = 0;
    countSemOp.sem_flg = 0;
    countSemOp.sem_op = -1; // Decrement counting semaphore
    if (semop(countSemId, &countSemOp, 1) == -1) {
        perror("Error while decrementing counting semaphore!");
        exit(1);
    }

    std::cout << "Counting semaphore decremented." << std::endl;

    // Remove the created semaphores
    semctl(critSemId, 0, IPC_RMID, 0);
    semctl(memSemId, 0, IPC_RMID, 0);
    semctl(countSemId, 0, IPC_RMID, 0);

    // Detach shared memory
    shmdt(sharedValue);

    return 0;
}
