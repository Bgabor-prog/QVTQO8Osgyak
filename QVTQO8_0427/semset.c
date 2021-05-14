#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 472L

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main(void)
{
	union semun arg;

	int n = 5;
    	int semID = semget(SEMKEY, n, IPC_CREAT | 0666);

   	if (semID == -1)
	{
     	  	perror("Hiba tortent a letrehozaskor!\n");
   	 	exit(-1);
    	}

   	arg.array = (short *)calloc(n, sizeof(int));


   	if (semctl(semID, 0, SETALL, arg))
	{
   	     perror("Hiba az ertek beallitasanal!\n");
  	     exit(-1);
   	}

}
