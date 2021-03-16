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
      printf("a gyermek folyamat nem jött letre, hiba törtent\n");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0)
   {
      // pid == 0 a gyermek folyamat létrejött
      // getpid() visszaadja a hívó processz ID-jét
      // Here It will return process id of child process
      printf("a gyermek folyamat, pid = %u\n",getpid());
      // Itt visszakapjuk a gyermek szülõ ID-jét
      printf("a gyermek folyamat szüloje, pid = %u\n",getppid());
      // futtatjuk az ls unix parancsot
      // a visszatérési érték -1
      execlp("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
      exit(0);
   }
   else
   {
      printf("a fo hivo folyamat ID-je, pid = %u\n",getppid());
      printf("a szulo folyamat, pid = %u\n",getpid());
        // a szülõ folyamat hívja a waitpid() rendszerfüggvényt a gyermek folyamatban
        // waitpid() rendszerhívás felfüggeszti a hívási folyamatot
        // amíg a gyermek folyamat státusza nem változik meg
        if (waitpid(pid, &status, 0) > 0)
        {
            if (WIFEXITED(status) && !WEXITSTATUS(status))
              printf("a program vagrehajtasa befejezodött\n");
            else if (WIFEXITED(status) && WEXITSTATUS(status))
            {
                if (WEXITSTATUS(status) == 127)
                {
                    // execlp hiba
                    printf("execlp futasi hiba\n");
                }
                else
                    printf("a program normalisan befejezodött,de nem 0 statusszal\n");
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
