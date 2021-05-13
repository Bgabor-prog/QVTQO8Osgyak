#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SMHKEY 783523

int main(void)
{
	pid_t process1;
   	pid_t process2;
    pid_t process3;

    	process1 = fork();
    	if (process1 == 0) {

        	int sharedMemoryId = shmget(SMHKEY, 256, IPC_CREAT | 0666);
        	if (sharedMemoryId == -1) {
        	    perror("Memoria lefoglalas sikertelen!\n");
            	exit(-1);
        	}
      	printf("Process1 lefoglalta a memoriat!\n");
	} else {
        	process2 = fork();
        	if (process2 == 0) {
           printf("Processz2 kiolvasasa\n");
           int sharedMemoryId = shmget(SMHKEY, 0, 0);
           char *s = shmat(sharedMemoryId, NULL, SHM_RND);
           strlen(s) > 0 ? printf("Osztott memoriaban a szoveg : %s\n", s) : printf("Ures az osztott memoria\n");
           strcpy(s, "Uj szoveg");
           printf("Process2-tol kaptam az uzenetet\n");
		} else {
           	process3 = fork();
          		if (process3 == 0) {
          	 		printf("Process3:\n");
           		int sharedMemoryId = shmget(SMHKEY, 0, 0);
           		struct shmid_ds buffer;
           		if (shmctl(sharedMemoryId, IPC_STAT, &buffer) == -1) {
           			perror("Lekerdezes sikertelen!\n");
                			exit(-1);
          			}
           	printf("Memoria merete : %ld\n", buffer.shm_segsz);
           	printf("Utolso operacio processze pidje : %d\n", buffer.shm_lpid);
      	}
      }
   }
}
