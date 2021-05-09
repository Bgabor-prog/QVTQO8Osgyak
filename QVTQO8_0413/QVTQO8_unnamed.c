#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int pipes[3];
    if (pipe(pipes) < 0)
    {
        perror("HIBA");
        exit(1);
    }

    int pid = fork();
    if (pid < 0)
        exit(2);

    if (pid == 0)
    {
        write(pipes[1], "QVTQO8", 64);
    } else if (pid > 0)
    {
        wait(NULL);

        char charArray[64];
        read(pipes[0], charArray, sizeof(charArray));
        printf("%s\n", charArray);
    }

    return 0;
}
