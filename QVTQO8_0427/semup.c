#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 472L

int main(void)
{
	int semID = semget(SEMKEY , 0, 0);

   	if (semID == -1)
	{
   	    	perror("Hiba a lekerdezesben!\n");
     		exit(-1);
   	}

   	struct sembuf buffer;

  	buffer.sem_num = 3;
  	buffer.sem_op = 1;
  	buffer.sem_flg = 0666;

   	if (semop(semID, &buffer, 1))
	{
       		perror("Sikertelen beallitas\n");
       		exit(-1);
    	}
}
