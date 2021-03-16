#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
   pid_t  pid;
   int ret = 1;
   int status;
   pid = fork();
   if (pid == -1)
   {
      // pid == -1 hiba keletkezett
      printf("a gyermek folyamat nem j�tt letre, hiba t�rtent\n");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0)
   {
      // pid == 0 a gyermek folyamat l�trej�tt
      // getpid() visszaadja a h�v� processz ID-j�t
      // Here It will return process id of child process
      printf("a gyermek folyamat, pid = %u\n",getpid());
      // Itt visszakapjuk a gyermek sz�l� ID-j�t
      printf("a gyermek folyamat sz�loje, pid = %u\n",getppid());
      // futtatjuk az ls unix parancsot
      // a visszat�r�si �rt�k -1
      execlp("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
      exit(0);
   }
   else
   {
      printf("a fo hivo folyamat ID-je, pid = %u\n",getppid());
      printf("a szulo folyamat, pid = %u\n",getpid());
        // a sz�l� folyamat h�vja a waitpid() rendszerf�ggv�nyt a gyermek folyamatban
        // waitpid() rendszerh�v�s felf�ggeszti a h�v�si folyamatot
        // am�g a gyermek folyamat st�tusza nem v�ltozik meg
        if (waitpid(pid, &status, 0) > 0)
        {
            if (WIFEXITED(status) && !WEXITSTATUS(status))
              printf("a program vagrehajtasa befejezod�tt\n");
            else if (WIFEXITED(status) && WEXITSTATUS(status))
            {
                if (WEXITSTATUS(status) == 127)
                {
                    // execlp hiba
                    printf("execlp futasi hiba\n");
                }
                else
                    printf("a program normalisan befejezod�tt,de nem 0 statusszal\n");
            }
            else
               printf("a program nem normalisan ert veget\n");
        }
        else
        {
           // waitpid() hiba
           printf("waitpid() varakozasi hiba\n");
        }
      exit(0);
   }
   return 0;
}
