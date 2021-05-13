#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMKEY 4531

int main(void)
{
    int sharedMemoryId = shmget(SHMKEY, 256, IPC_CREAT | 0666);
    printf("Osztott memoria letrehozva.\n");
}
